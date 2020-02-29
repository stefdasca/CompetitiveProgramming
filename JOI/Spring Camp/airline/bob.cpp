/*
    JOISC 18-Airline

    We can add extra vertexes to solve the problem:

    * 10 vertexes will be used as follows: ith of them(0-indexed) will be connected to edges which have bit i equal to 1
    * the 11th vertex will be connected to the initial n vertexes
    * the 12th vertex will be connected only to the 11th vertex

    In order to recover the information, we will firstly find out the 12th vertex
(it has degree 1 and its neighbor has degree N+1, where N is the initial N(V-11 in Bob's code))

    Then, we will find out the bit vertexes starting from the last one to the first one, and thus we find the real
values of the edges.

    After we decrypted the graph, now we can reconstruct the original graph based on the edges which don't have any of the extra
12 vertexes at one of its ends.

*/

#include "Boblib.h"
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

vector<int> v[1024];
int trueval[1024];
bool adj[1024][1024], bit[1024], viz[1024];

void Bob(int V, int U, int C[], int D[])
{
    for (int i = 0; i < U; i++)
    {
        v[C[i]].push_back(D[i]);
        v[D[i]].push_back(C[i]);
        adj[C[i]][D[i]] = adj[D[i]][C[i]] = 1;
    }
    int special;
    for(int i = 0; i < V; i++)
        if(v[i].size() == 1 && v[v[i][0]].size() == V - 11)
        {
            special = v[i][0];
            break;
        }
    bit[special] = 1;
    int last_bit = special;
    for(int i = 0; i < V; i++)
        if(i != special && !adj[i][special])
        {
            bit[i] = 1;
            if(v[i].size() <= v[last_bit].size())
                last_bit = i;
        }
    for(int i = 9; i >= 0; i--)
    {
        viz[last_bit] = 1;
        for(int j = 0; j < v[last_bit].size(); ++j)
        {
            int nod = v[last_bit][j];
            trueval[nod] += (1 << i);
        }
        for(int j = 0; j < v[last_bit].size(); ++j)
        {
            int nod = v[last_bit][j];
            if(bit[nod] && !viz[nod])
            {
                last_bit = nod;
                break;
            }
        }
    }
    vector<pair<int, int> >muchii;
    for(int i = 0; i < V; i++)
        for(int j = i + 1; j < V; j++)
            if(adj[i][j] && !bit[i] && !bit[j])
                muchii.pb({trueval[i], trueval[j]});
    InitMap(V - 12, muchii.size());
    for(int i = 0; i < muchii.size(); ++i)
        MakeMap(muchii[i].fi, muchii[i].se);
}

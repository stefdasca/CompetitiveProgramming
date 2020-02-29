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

#include "Alicelib.h"
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;

void Alice(int N, int M, int A[], int B[])
{
    vector<pair<int, int> >muchii;
    for(int i = 0; i < M; ++i)
        muchii.pb({A[i], B[i]});
    for(int i = 0; i <= 9; ++i)
    {
        for(int j = 0; j < N; ++j)
            if(j & (1<<i))
                muchii.pb({N + i, j});
        if(i < 9)
            muchii.pb({N + i, N + i + 1});
    }
    for(int j = 0; j < N; ++j)
        muchii.pb({N + 10, j});
    muchii.pb({N + 11, N + 10});
    InitG(N + 12, muchii.size());
    for (int i = 0; i < muchii.size(); i++)
        MakeG(i, muchii[i].fi, muchii[i].se);
}

/*

        TheCitiesAndRoadsDivTwo - SRM460-D2-1000

    This problem can be solved with either recursion with many optimizations or some math, based on Prufer code
and a modification of Cayley's formula

    https://cp-algorithms.com/graph/pruefer_code.html#toc-tgt-8

    Basically if we have connected components of size X1, X2, ..., XK and their sum is n, the number of ways to connect the graph is

    X1 * X2 * X3 * ... * XK * N^(K-2).


*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int adj[12][12];

class TheCitiesAndRoadsDivTwo
{
     public:
        int find(vector <string> s)
        {
            int n = s.size();
            for(int i = 0; i < n; ++i)
            {
                string x = s[i];
                for(int j = 0; j < n; ++j)
                    if(x[j] == 'Y')
                        adj[i+1][j+1] = adj[j+1][i+1] = 1;
            }
            int cc[12] = {0};
            int x = 0;
            int prod = 1;
            for(int i = 1; i <= n; ++i)
            {
                if(!cc[i])
                {
                    ++x;
                    deque<int> d;
                    d.pb(i);
                    int le = 0;
                    while(!d.empty())
                    {
                        ++le;
                        cc[d[0]] = x;
                        int nod = d[0];
                        d.pop_front();
                        for(int j = 1; j <= n; ++j)
                            if(adj[nod][j] && !cc[j])
                                d.pb(j), cc[j] = x;
                    }
                    prod = prod * le;
                }
            }
            for(int i = 1; i <= x-2; ++i)
                prod = prod * n;
            if(x == 1)
                return 1;
            return prod;
        }
};

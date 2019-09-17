#include<bits/stdc++.h>
#include "advisor.h"
using namespace std;


deque<int>v[100002];
void ComputeAdvice(int *C, int N, int K, int M)
{
    for(int i = 0; i < N; ++i)
        v[C[i]].push_back(i);
    for(int i = 0; i < N; ++i)
        v[i].push_back((1<<20));
    set<pair<int, int> >cb;
    set<int>nr;
    for(int i = 0; i < K; ++i)
        cb.insert({v[i][0], i}), nr.insert(i);
    int act[100002];
    memset(act, 0, sizeof(act));
    int st[100002];
    for(int i = 0; i < K; ++i)
        st[i] = 1;
    int saved[100002];
    memset(saved, 0, sizeof(saved));
    int prv[100002];
    memset(prv, -1, sizeof(prv));
    for(int i = 0; i < N; ++i)
    {
        if(nr.find(C[i]) != nr.end())
        {
            if(C[i] < K && !saved[C[i]])
                saved[C[i]] = 1;
            cb.erase({v[C[i]][0], C[i]});
            v[C[i]].pop_front();
            cb.insert({v[C[i]][0], C[i]});
            if(prv[C[i]] != -1)
                act[prv[C[i]]] = 1;
            prv[C[i]] = i;
        }
        else
        {
            if((*cb.rbegin()).second < K)
            {
                int val = (*cb.rbegin()).second;
                if(val < K && !saved[val])
                    st[val] = 0, saved[val] = 1;
            }
            nr.erase((*cb.rbegin()).second);
            cb.erase(*cb.rbegin());
            nr.insert(C[i]);
            v[C[i]].pop_front();
            cb.insert({v[C[i]][0], C[i]});
            prv[C[i]] = i;
        }
    }
    for(int i = 0; i < K; ++i)
        WriteAdvice(st[i]);
    for(int i = 0; i < N; ++i)
        WriteAdvice(act[i]);
}

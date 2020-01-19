/*
            IOI 18-doll

    Build a complete binary tree and use return edges in order to avoid using extra switches
(if we don't use them, we end up using 2n edges, which doesn't give us too many points)

*/
#include "doll.h"
#include<bits/stdc++.h>

using namespace std;

int adja[400002], adjb[400002], sw = 1, tot, state[400002];

void build(int p, int st, int dr)
{
    int mid = (st + dr) / 2;
    if(st + 1 == dr)
    {
        if(tot <= mid)
            adja[p] = 1;
        return;
    }
    ++sw;
    adjb[p] = sw;
    build(sw, st, mid);
    if(tot > mid)
    {
        ++sw;
        adja[p] = sw;
        build(sw, mid+1, dr);
    }
    else
        adja[p] = 1;
}

void dfs(int nod, int val)
{
    state[nod] ^= 1;
    if(!state[nod])
    {
        if(adjb[nod])
            dfs(adjb[nod], val);
        else
            adjb[nod] = val;
    }
    else
    {
        if(adja[nod])
            dfs(adja[nod], val);
        else
            adja[nod] = val;
    }
}
void create_circuit(int M, vector<int> A)
{
    vector<int> C;
    C.push_back(A[0]);
    for(int i = 1; i <= M; ++i)
        C.push_back(-1);
    A.push_back(0);
    int sz = 1;
    while(sz * 2 <= (int) A.size() - 2)
        sz *= 2;
    sz *= 2;
    tot = A.size() - 1;
    build(1, 1, sz);
    for(int i = 1; i < A.size(); ++i)
        dfs(1, -A[i]);
    vector<int> X(sw), Y(sw);
    for(int k = 0; k < sw; ++k)
    {
        X[k] = -adja[k + 1];
        Y[k] = -adjb[k + 1];
    }
    answer(C, X, Y);
}

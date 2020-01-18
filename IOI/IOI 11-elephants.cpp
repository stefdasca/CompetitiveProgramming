/*
        IOI 11-elephants

    solution: https://github.com/tmwilliamlin168/CompetitiveProgramming/blob/master/IOI/11-Elephants.cpp

*/

#include "elephants.h"
#include <bits/stdc++.h>
using namespace std;

int n, l, *x, uc, bc, r[302];
map<int, int> mp;
vector<int> v[302];
vector<array<int, 2>> w[302];

void init(int N, int L, int X[])
{
    n=N, l=L, x=X;
    for(int i=0; i<n; ++i)
        ++mp[x[i]];
}

void bb(int i)
{
    w[i]=vector<array<int, 2>>(v[i].size());
    for(int j1=(int)v[i].size()-1, j2=v[i].size(); ~j1; --j1)
    {
        while(v[i][j2-1]>v[i][j1]+l)
            --j2;
        if(j2<v[i].size())
            w[i][j1]= array<int, 2> {w[i][j2][0]+1, w[i][j2][1]};
        else
            w[i][j1]= array<int, 2> {1, v[i][j1]+l};
    }
}
void bld()
{
    bc=0;
    for(pair<int, int> p : mp)
    {
        if(!bc || v[bc-1].size()>=550)
            v[bc++].clear();
        v[bc-1].push_back(p.first);
    }
    for(int i=0; i<bc; ++i)
    {
        if(i+1 < bc)
            r[i]=v[i+1][0]-1;
        else
            r[i] = 1000000000;
        bb(i);
    }
}

void upd(int x, bool a)
{
    int c=-1;
    while(x>r[++c]);
    int p=lower_bound(v[c].begin(), v[c].end(), x)-v[c].begin();
    if(a)
        v[c].insert(v[c].begin()+p, x);
    else
        v[c].erase(v[c].begin()+p);
    bb(c);
}

int update(int i, int y)
{
    ++uc;
    if(uc % 550 ==0)
        bld();
    --mp[x[i]];
    if(!mp[x[i]])
    {
        upd(x[i], 0);
        mp.erase(x[i]);
    }
    if(!mp[y])
        upd(y, 1);
    ++mp[y];
    x[i]=y;
    int a=0;
    for(int i=0, c=-1; i<bc; ++i)
    {
        int p=upper_bound(v[i].begin(), v[i].end(), c)-v[i].begin();
        if(p<v[i].size())
        {
            a+=w[i][p][0];
            c=w[i][p][1];
        }
    }
    return a;
}

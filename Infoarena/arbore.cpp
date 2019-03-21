/*
            Infoarena arbore(https://www.infoarena.ro/problema/arbore)
    
    "Given a tree with n nodes, rooted at 1, where all values of nodes are initially empty, and m queries where at each of the queries,
we either add a value q to the subtree rooted at node p, or we have to report whether it exists a node with a value z or not."

    We can do dfs tour of the tree and sqrt decomposition for each query for a total complexity of O(n sqrt n)

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("arbore.in");
ofstream g("arbore.out");
int n, q;
int sbuk[400], st[400], dr[400], Bucket, ar[100002];
int L[100002], R[100002], mm, cr[100002], euler[100002];
bitset<1000002>mp[402];
vector<int>v[100002];
void dfs(int dad, int nod)
{
    ++mm;
    L[nod] = mm;
    euler[mm] = nod;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
    }
    R[nod] = mm;
}
int main()
{
    f >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    Bucket = (int)sqrt(n);
    int pp = 1;
    st[1] = 1;
    for(int i = 1; i <= n; ++i)
    {
        cr[i] = pp;
        if(i % Bucket == 0)
        {
            dr[pp] = i;
            if(i < n)
            {
                ++pp;
                st[pp] = i + 1;
            }
        }
    }
    dr[pp] = n;
    for(int i = 1; i <= n; ++i)
        mp[cr[i]][0] = 1;
    for(int i = 1; i <= q; ++i)
    {
        int tip;
        f >> tip;
        if(tip == 1)
        {
            int a, b;
            f >> a >> b;
            int pz = L[a];
            for(int j = L[a]; j <= min(R[a], dr[cr[L[a]]]); ++j, ++pz)
            {
                mp[cr[j]][ar[j]] = 0;
                ar[j] += b;
            }
            for(int j = st[cr[L[a]]]; j <= dr[cr[L[a]]]; ++j)
                mp[cr[j]][ar[j]] = 1;
            while(pz <= R[a] && dr[cr[pz]] <= R[a])
            {
                sbuk[cr[pz]] += b;
                pz = dr[cr[pz]] + 1;
            }
            if(pz <= n)
            {
                for(int j = pz; j <= R[a]; ++j)
                {
                    mp[cr[j]][ar[j]] = 0;
                    ar[j] += b;
                }
                for(int j = st[cr[pz]]; j <= dr[cr[pz]]; ++j)
                    mp[cr[j]][ar[j]] = 1;
            }
        }
        else
        {
            int b;
            f >> b;
            bool gg = 0;
            for(int j = 1; j <= pp; ++j)
            {
                if(b >= sbuk[j] && mp[j][b - sbuk[j]] == 1)
                {
                    gg = 1;
                    for(int q = st[j]; q <= dr[j]; ++q)
                        if(ar[q] == b - sbuk[j])
                        {
                            g << euler[q] << '\n';
                            break;
                        }
                    break;
                }
            }
            if(!gg)
                g << -1 << '\n';
        }
    }
    return 0;
}

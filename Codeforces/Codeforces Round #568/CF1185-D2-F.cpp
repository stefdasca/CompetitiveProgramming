#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int frq[520];
int mn[520];
struct pizza
{
    int pret;
    int mask;
};
pizza v[100002];
int mnn, mnn2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        int k;
        cin >> k;
        int nr = 0;
        for(int j = 1; j <= k; ++j)
        {
            int p;
            cin >> p;
            nr |= (1<<(p-1));
        }
        frq[nr]++;
    }
    for(int i = 1; i <= m; ++i)
    {
        cin >> v[i].pret;
        int k;
        cin >> k;
        int nr = 0;
        for(int j = 1; j <= k; ++j)
        {
            int p;
            cin >> p;
            nr |= (1<<(p-1));
        }
        if(mn[nr] == 0 || v[mn[nr]].pret > v[i].pret)
            mn[nr] = i;
        if(i == 1)
            mnn = i;
        else
            if(v[i].pret < v[mnn].pret)
                mnn2 = mnn, mnn = i;
            else
                if(mnn2 == 0 || v[i].pret < v[mnn2].pret)
                    mnn2 = i;
        v[i].mask = nr;
    }
    vector<int>ord;
    for(int i = 1; i <= 512; ++i)
        if(mn[i] != 0)
            ord.push_back(mn[i]);
    int MaxCustomers = -1;
    int who1 = 0, who2 = 0;
    for(int i = 0; i < ord.size(); ++i)
    {
        for(int j = i; j < ord.size(); ++j)
        {
            int aaa = ord[i], bbb;
            if(i == j)
            {
                if(mnn == ord[i])
                    bbb = mnn2;
                else
                    bbb = mnn;
            }
            else
                bbb = ord[j];
            int orsum = v[aaa].mask | v[bbb].mask;
            int nrr = 0;
            for(int q = 0; q <= 512; ++q)
                if((orsum & q) == q)
                    nrr += frq[q];
            if(nrr > MaxCustomers)
                MaxCustomers = nrr, who1 = aaa, who2 = bbb;
            else
                if(nrr == MaxCustomers && v[aaa].pret + v[bbb].pret < v[who1].pret + v[who2].pret)
                    who1 = aaa, who2 = bbb;
        }
    }
    cout << who1 << " " << who2 << '\n';
    return 0;
}


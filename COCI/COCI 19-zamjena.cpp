#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
vector<string>a;
vector<string>b;
map<string, int>mp;
map<int, int>sim;
int nr[50002], nr2[50002];
int xx;
vector<int>v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        a.push_back(x);
        int nrr = 0;
        bool gg = 1;
        if(mp[x])
            continue;
        for(int j = 0; j < x.size(); ++j)
        {
            if(!(x[j] >= '0' && x[j] <= '9'))
                gg = 0;
            nrr = nrr * 10 + (x[j] - '0');
        }
        if(gg)
            nr[i] = nrr;
        else
            mp[x] = ++xx;
    }
    for(int i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        b.push_back(x);
        int nrr = 0;
        bool gg = 1;
        if(mp[x])
            continue;
        for(int j = 0; j < x.size(); ++j)
        {
            if(!(x[j] >= '0' && x[j] <= '9'))
                gg = 0;
            nrr = nrr * 10 + (x[j] - '0');
        }
        if(gg)
            nr2[i] = nrr;
        else
            mp[x] = ++xx;
    }
    bool rau = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i-1] == b[i-1])
            continue;
        if(mp[a[i-1]])
            v[mp[a[i-1]]].push_back(i);
        if(mp[b[i-1]])
            v[mp[b[i-1]]].push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        if(nr[i] && nr2[i] && nr[i] != nr2[i])
            rau = 1;
    deque<string>d;
    for(int i = 1; i <= n; ++i)
    {
        if(nr[i] && nr2[i])
            continue;
        if(nr[i] && mp[b[i-1]])
        {
            int val = mp[b[i-1]];
            if(sim[val] && sim[val] != nr[i])
                rau = 1;
            else
                sim[val] = nr[i], d.push_back(b[i-1]);
            continue;
        }
        if(nr2[i] && mp[a[i-1]])
        {
            int val = mp[a[i-1]];
            if(sim[val] && sim[val] != nr2[i])
                rau = 1;
            else
                sim[val] = nr2[i], d.push_back(a[i-1]);
            continue;
        }
        if(sim[mp[a[i-1]]] && sim[mp[b[i-1]]] && sim[mp[a[i-1]]] != sim[mp[b[i-1]]])
        {
            rau = 1;
            continue;
        }
        if(sim[mp[a[i-1]]])
        {
            sim[mp[b[i-1]]] = sim[mp[a[i-1]]];
            d.push_back(b[i-1]);
        }
        if(sim[mp[b[i-1]]])
        {
            sim[mp[a[i-1]]] = sim[mp[b[i-1]]];
            d.push_back(a[i-1]);
        }
    }
    while(!d.empty())
    {
        string p = d[0];
        d.pop_front();
        int val = mp[p];
        for(int j = 0; j < v[val].size(); ++j)
        {
            int pos = v[val][j];
            if(b[pos-1] == p)
            {
                if(!sim[mp[a[pos-1]]])
                    sim[mp[a[pos-1]]] = sim[val], d.push_back(a[pos-1]);
            }
            if(a[pos-1] == p)
            {
                if(!sim[mp[b[pos-1]]])
                    sim[mp[b[pos-1]]] = sim[val], d.push_back(b[pos-1]);
            }
        }
    }
    for(int j = 1; j <= n; ++j)
    {
        if(!sim[mp[a[j-1]]] && !sim[mp[b[j-1]]])
            continue;
        if(!nr[j])
            nr[j] = sim[mp[a[j-1]]];
        if(!nr2[j])
            nr2[j] = sim[mp[b[j-1]]];
        if(nr[j] != nr2[j])
            rau = 1;
    }
    if(rau)
        cout << "NE\n";
    else
        cout << "DA\n";
    return 0;
}

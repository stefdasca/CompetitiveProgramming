#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int root;
int n, rsp[100002], tt[100002];
set<int>s;
vector<int>v[100002];
bool gg[100002];
void dfs(int nod)
{
    gg[nod] = 1;
    if(rsp[nod] == 1)
        gg[nod] = 0;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
        if(rsp[vecin] == 1)
            gg[nod] = 0;
    }
    if(gg[nod] && nod != root)
        s.insert(nod);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a >> rsp[i];
        rsp[i] ^= 1;
        if(a != -1)
            v[a].push_back(i);
        else
            root = i;
        tt[i] = a;
    }
    dfs(root);
    if(s.empty())
        cout << -1;
    else
    {
        while(!s.empty())
        {
            cout << *s.begin() << " ";
            int q = *s.begin();
            s.erase(q);
            for(int i = 0; i < v[q].size(); ++i)
            {
                int vecin = v[q][i];
                tt[vecin] = tt[q];
                if(rsp[vecin])
                    s.erase(tt[q]);
            }
        }
    }
    return 0;
}


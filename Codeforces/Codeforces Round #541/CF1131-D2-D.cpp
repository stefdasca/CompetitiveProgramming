#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m;
vector<int>v[2002], v2[2002];
char a[1002][1002];
int gr[2002], z;
int val[2002], val2[2002];
void dfs(int nod)
{
    val[nod] = z;
    for(int i = 0; i < v2[nod].size(); ++i)
    {
        int vecin = v2[nod][i];
        if(!val[vecin])
            dfs(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> (a[i] + 1);
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '=')
            {
                v2[i].push_back(n + j);
                v2[n + j].push_back(i);
            }
    }
    for(int i = 1; i <= n + m; ++i)
        if(!val[i])
            ++z, dfs(i);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i][j] == '<')
                v[val[i]].push_back(val[n + j]), ++gr[val[n+j]];
            else
                if(a[i][j] == '>')
                    v[val[n + j]].push_back(val[i]), ++gr[val[i]];
    deque<int>d, d2;
    for(int i = 1; i <= z; ++i)
        if(gr[i] == 0)
            d.push_back(i);
    int vv = 0;
    while(!d.empty())
    {
        ++vv;
        while(!d.empty())
        {
            int nod = d[0];
            d.pop_front();
            val2[nod] = vv;
            for(int i = 0; i < v[nod].size(); ++i)
            {
                int vecin = v[nod][i];
                if((--gr[vecin]) == 0)
                    d2.push_back(vecin);
            }
        }
        if(d2.empty())
            break;
        swap(d, d2);
    }
    for(int i = 1; i <= z; ++i)
        if(!val2[i])
        {
            cout << "No";
            return 0;
        }
    cout << "Yes\n";
    for(int i = 1; i <= n; ++i)
        cout << val2[val[i]] << " ";
    cout << '\n';
    for(int i = 1; i <= m; ++i)
        cout << val2[val[n + i]] << " ";
    return 0;
}

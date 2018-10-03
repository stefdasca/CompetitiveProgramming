#include<bits/stdc++.h>
using namespace std;
ifstream f("parb.in");
ofstream g("parb.out");
int n, mx[500002], ddd[500002], lvl[500002], sol[500002];
vector<int>v[500002];
char lit;
string s;
int aa = 0;
void dfs(int dad, int nod)
{
    ddd[nod] = dad;
    mx[nod] = -1;
    lvl[nod] = lvl[dad] + 1;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        mx[nod] = max(mx[nod], s[vecin-1] - 'a');
    }
}
deque<int>dd;
bool cmp(int a, int b)
{
    return lvl[a] < lvl[b];
}
int main()
{
    f >> n;
    f >> s;
    for(int i = 1; i < n; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    for(lit = 'z'; lit >= 'a'; --lit)
    {
        for(int i = 1; i <= n; ++i)
            if(s[i-1] == lit)
                dd.push_back(i);
        if(!dd.empty())
        {
            g << lit;
            break;
        }
    }
    sort(dd.begin(), dd.end(), cmp);
    int amx = 0;
    for(int i = 0; i < dd.size(); ++i)
    {
        sol[dd[i]] = sol[ddd[dd[i]]] + 1;
        amx = max(amx, sol[dd[i]]);
    }
    deque<int>dd2;
    for(int i = 1; i < amx; ++i)
        g << lit;
    for(int i = 0; i < dd.size(); ++i)
        if(sol[dd[i]] == amx)
            dd2.push_back(dd[i]);
    dd.clear();
    for(int i = 0; i < dd2.size(); ++i)
        dd.push_back(dd2[i]);
    while(!dd.empty())
    {
        int mxx = -1;
        for(int i = 0; i < dd.size(); ++i)
            mxx = max(mxx, mx[dd[i]]);
        if(mxx == -1)
            break;
        int a = dd.size();
        for(int i = 0; i < a; ++i)
        {
            if(mx[dd[0]] == mxx)
            {
                for(int j = 0; j < v[dd[0]].size(); ++j)
                {
                    int vecin = v[dd[0]][j];
                    if(ddd[dd[0]] == vecin)
                        continue;
                    if(s[vecin-1] - 'a' == mxx)
                        dd.push_back(vecin);
                }
            }
            dd.pop_front();
        }
        char L = 'a' + mxx;
        g << L;
    }
    return 0;
}

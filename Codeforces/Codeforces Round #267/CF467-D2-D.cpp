#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, m;
vector<string> cuv;

map<int, int> mp;

int sz[200002], nrR[200002];
int nr, tc, wh[200002];
bool viz[200002], viz2[200002];
vector<int> v[200002], tr[200002], ctc[200002];
stack<int>s;
void dfs(int nod)
{
    viz[nod] = 1;
    for(int j = 0; j < v[nod].size(); ++j)
    {
        int vecin = v[nod][j];
        if(!viz[vecin])
            dfs(vecin);
    }
    s.push(nod);
}
void dfs2(int nod)
{
    viz2[nod] = 1;
    ctc[tc].push_back(nod);
    wh[nod] = tc;
    for(int j = 0; j < tr[nod].size(); ++j)
    {
        int vecin = tr[nod][j];
        if(!viz2[vecin])
            dfs2(vecin);
    }
}

int szz[200002];
int countRR[200002];

int source[200002];

string sm(string x)
{
    string ans;
    for(int i = 0; i < x.size(); ++i)
    {
        if(x[i] >= 'a')
            ans += x[i];
        else
            ans += (x[i] + 32);
    }
    return ans;
}

int hsh(string a)
{
    ll h = 0;
    for(int i = 0; i < a.size(); ++i)
        h = (h * 31 + (a[i] - 'a' + 1)) % mod;
    return h;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        x = sm(x);
        cuv.pb(x);
    }
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        string a, b;
        cin >> a >> b;
        a = sm(a);
        b = sm(b);
        int val1 = hsh(a);
        int val2 = hsh(b);
        if(mp.find(val1) == mp.end())
        {
            mp[val1] = ++nr;
            sz[nr] = a.size();
            for(int j = 0; j < a.size(); ++j)
                nrR[nr] += (a[j] == 'R' || a[j] == 'r');
        }
        if(mp.find(val2) == mp.end())
        {
            mp[val2] = ++nr;
            sz[nr] = b.size();
            for(int j = 0; j < b.size(); ++j)
                nrR[nr] += (b[j] == 'R' || b[j] == 'r');
        }
        v[mp[val1]].pb(mp[val2]);
        tr[mp[val2]].pb(mp[val1]);
    }
    for(int i = 1; i <= nr; ++i)
        if(!viz[i])
            dfs(i);
    while(!s.empty())
    {
        int nod = s.top();
        s.pop();
        if(!viz2[nod])
        {
            ++tc;
            dfs2(nod);
        }
    }
    for(int i = tc; i >= 1; --i)
    {
        source[i] = i;
        for(int j = 0; j < ctc[i].size(); ++j)
        {
            int poz = ctc[i][j];
            if(j == 0)
            {
                szz[i] = sz[poz];
                countRR[i] = nrR[poz];
            }
            else
            {
                int countR = countRR[i];
                int countR2 = nrR[poz];
                if(countR2 < countR || countR2 == countR && sz[poz] < szz[i])
                    szz[i] = sz[poz], countRR[i] = countR2, source[i] = i;
            }
            for(int p = 0; p < v[poz].size(); ++p)
            {
                int vec = v[poz][p];
                int pcc = wh[vec];
             //   cout << i << " " << poz << " " << vec << " " << pcc << " " << best[i] << " " << best[pcc] << '\n';
                if(wh[vec] != i)
                {
                    int countR = countRR[source[i]];
                    int countR2 = countRR[source[pcc]];
                    if(countR2 < countR)
                        source[i] = source[pcc], countRR[i] = countR2;
                    else
                         if(countR2 == countR && szz[source[pcc]] < szz[source[i]])
                            source[i] = source[pcc];
                }
             //   cout << best[i] << '\n';
            }
        }
    }
    ll len = 0;
    ll nrR = 0;
    for(int i = 0; i < n; ++i)
    {
        int vx = hsh(cuv[i]);
        if(mp.find(vx) == mp.end())
        {
            for(int j = 0; j < cuv[i].size(); ++j)
                nrR += (cuv[i][j] == 'R' || cuv[i][j] == 'r');
            len += cuv[i].size();
          //  cout << cuv[i] << " ";
        }
        else
        {
            len += szz[source[wh[mp[vx]]]];
            nrR += countRR[source[wh[mp[vx]]]];
        }
    }
    cout << nrR << " " << len << '\n';
    return 0;
}

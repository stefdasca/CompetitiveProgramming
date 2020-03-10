#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

int n, m;
int mat[2002][2002];

int tt[2002], st, dr;
int viz[200002];

pair<int, int> muchii[200002];

vector<pair<int, int> > v[2002];
vector<int> v2[200002], v3[2002];

void dfs(int dad, int nod)
{
    viz[nod] = 1;
    for(int i = 0; i < v2[nod].size(); ++i)
    {
        int vecin = v2[nod][i];
        if(!st && viz[vecin] == 1)
        {
            st = vecin, dr = nod;
            break;
        }
        if(!viz[vecin])
        {
            tt[vecin] = nod;
            dfs(nod, vecin);
        }
    }
    viz[nod] = 2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
         int a, b;
         cin >> a >> b;
         mat[a][b] = mat[b][a] = 1;
         muchii[i] = {a, b};
         v[a].pb({b, i});
         v[b].pb({a, i+m});
    }
    for(int i = 1; i <= m; i++)
    {
         int a = muchii[i].fi, b = muchii[i].se;
         for(int j = 0; j < v[b].size(); ++j)
         {
              int w = v[b][j].fi;
              int e = v[b][j].se;
              if(w != a && w != b && !mat[w][a])
	          v2[i].pb(e);
         }
         for(int j = 0; j < v[a].size(); ++j)
         {
              int w = v[a][j].fi;
              int e = v[a][j].se;
              if(w != a && w != b && !mat[w][b])
                  v2[i+m].pb(e);
      	 }
    }
    for(int i = 1; !st && i <= m+m; i++)
        if(!viz[i])
            dfs(0, i);
    if(!st)
    {
	cout << "no\n";
        return 0;
    }
    int nr = dr;
    vector<int> sol;
    while(1)
    {
        if(nr > m)
            sol.pb(muchii[nr-m].se);
        else
            sol.pb(muchii[nr].fi);
        if(nr == st)
            break;
        nr = tt[nr];
    }
    for(int i = 0; i < sol.size(); ++i)
        cout << sol[i] << " ";
    cout << '\n';
    return 0;
}

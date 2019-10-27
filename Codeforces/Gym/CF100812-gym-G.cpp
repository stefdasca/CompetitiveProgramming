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

ll n, m, dist[3][100002], fw[3][100002];
vector<pair<int, ll> >v[100002];

struct cmp
{
    bool operator()(pair<ll, pair<int, int> > a, pair<ll, pair<int, int> > b)
    {
        return a.first > b.first;
    }
};
priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> >>, cmp>q;
bool was[100002], is[100002];
void djk()
{
    for(int i = 1; i <= n; ++i)
        dist[1][i] = dist[2][i] = (1LL<<60);
    for(int i = 1; i <= n; ++i)
        if(is[i])
        {
            dist[1][i] = 0;
            fw[1][i] = i;
            q.push({0, {i, i}});
        }
    while(!q.empty())
    {
        pair<ll, pair<int, int> > nod = q.top();
        q.pop();
        if(nod.first > dist[2][nod.second.first])
            continue;
        for(int i = 0; i < v[nod.second.first].size(); ++i)
        {
            pair<int, int> vecin = v[nod.second.first][i];
            if(nod.first + vecin.second < dist[1][vecin.first])
            {
                if(fw[1][vecin.first] != nod.second.second)
                {
                    dist[2][vecin.first] = dist[1][vecin.first];
                    fw[2][vecin.first] = fw[1][vecin.first];
                }
                dist[1][vecin.first] = nod.first + vecin.second;
                fw[1][vecin.first] = nod.second.second;
                q.push({dist[1][vecin.first], {vecin.first, nod.second.second}});
            }
            else
            {
                if(nod.first + vecin.second < dist[2][vecin.first])
                {
                    if(nod.second.second != fw[1][vecin.first])
                    {
                        dist[2][vecin.first] = nod.first + vecin.second;
                        fw[2][vecin.first] = nod.second.second;
                        q.push({dist[2][vecin.first], {vecin.first, nod.second.second}});
                    }
                }
            }
        }
    }
    ll mn = (1LL<<60);
    int pz = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dist[1][i] + dist[2][i] < mn)
        {
            pz = i;
            mn = dist[1][i] + dist[2][i];
        }
    }
    if(mn != (1LL<<60))
    {
        cout << mn << '\n';
        cout << fw[1][pz] << " " << fw[2][pz] << '\n';
        exit(0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> is[i];
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].pb({b, c});
        v[b].pb({a, c});
    }
    djk();
    cout << "No luck at all\n";
    return 0;
}

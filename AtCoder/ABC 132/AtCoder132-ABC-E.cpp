#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
vector<int>gr[100002];
bool viz[100002][5];
int mv[100002][5];
int s, t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
    }
    cin >> s >> t;
    deque<pair<int, int> >d;
    d.push_back({s, 0});
    while(!d.empty())
    {
        pair<int, int> p = d[0];
        d.pop_front();
        int nod = p.first;
        int md = p.second;
        viz[nod][md%3] = 1;
        mv[nod][md%3] = md;
        for(int i = 0; i < gr[nod].size(); ++i)
        {
            int vecin = gr[nod][i];
            if(viz[vecin][(md+1)%3])
                continue;
            d.push_back({vecin, md+1});
            viz[vecin][(md+1)%3]=1;
        }
    }
    if(!viz[t][0])
        cout << -1;
    else
        cout << mv[t][0]/3;
    return 0;
}

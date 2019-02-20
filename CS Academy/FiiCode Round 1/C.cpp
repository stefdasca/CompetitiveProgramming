#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m, x, y;
vector<int>v[100002], tr[100002];
int canX[100002], canY[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> x >> y;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        tr[b].push_back(a);
    }
    deque<int>q;
    canX[x] = 1, canY[y] = 1;
    q.push_back(x);
    while(!q.empty())
    {
        int nod = q[0];
        q.pop_front();
        for(int i = 0; i < tr[nod].size(); ++i)
        {
            int vec = tr[nod][i];
            if(canX[vec])
                continue;
            canX[vec] = 1;
            q.push_back(vec);
        }
    }
    q.push_back(y);
    while(!q.empty())
    {
        int nod = q[0];
        q.pop_front();
        for(int i = 0; i < tr[nod].size(); ++i)
        {
            int vec = tr[nod][i];
            if(canY[vec])
                continue;
            canY[vec] = 1;
            q.push_back(vec);
        }
    }
    bool ex = 0;
    for(int i = 1; i <= n; ++i)
        if(canX[i] && canY[i])
            ex = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(canX[i] && canY[i])
            cout << 0 << " ";
        else
        {
            if(canX[i] || canY[i])
                cout << 1 << " ";
            else
                if(ex)
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
        }
    }
    return 0;
}


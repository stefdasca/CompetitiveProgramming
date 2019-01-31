#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
vector<int>v[100002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp>q;
bool viz[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    viz[1] = 1;
    while(!q.empty())
    {
        cout << q.top() << " ";
        int nod = q.top();
        q.pop();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(!viz[vecin])
            {
                viz[vecin] = 1;
                q.push(vecin);
            }
        }
    }
    return 0;
}


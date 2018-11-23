#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, x, y;
long long ans;
long long mod = 1000000007;
struct qx
{
    int st, dr;
};
qx v[100002];
bool cmp(qx a, qx b)
{
    return a.st < b.st;
}
priority_queue<int, vector<int>, greater<int> >q2;
priority_queue<int>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].st >> v[i].dr;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        while(!q2.empty() && q2.top() < v[i].st)
            q.push(q2.top()), q2.pop();
        if(q.empty())
        {
            ans = ans + 1LL * x;
            ans = ans + 1LL * (v[i].dr - v[i].st) * y;
            ans %= mod;
            q2.push(v[i].dr);
        }
        else
        {
            ans = ans + min(1LL * x, (v[i].st - q.top()) * y);
            ans = ans + 1LL * (v[i].dr - v[i].st) * y;
            ans %= mod;
            if(1LL * x >= (v[i].st - q.top()) * y)
                q.pop();
            q2.push(v[i].dr);

        }
    }
    cout << ans;
    return 0;
}

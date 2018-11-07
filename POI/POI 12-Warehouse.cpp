#include<bits/stdc++.h>
using namespace std;
int n, ans, v[250002];
int v2[250002];
long long qt;
bool pus[250002];
struct cmp
{
    bool operator()(int a, int b)
    {
        return v2[a] < v2[b];
    }
};
priority_queue<int, vector<int>, cmp>q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        cin >> v2[i];
        qt += v[i];
        if(qt < v2[i] && !q.empty() && v2[q.top()] > v2[i])
        {
            int x = q.top();
            q.pop();
            pus[x] = 0;
            qt += v2[x];
            --ans;
        }
        if(qt >= v2[i])
        {
            qt -= v2[i];
            pus[i] = 1;
            ++ans;
            q.push(i);
        }
    }
    cout << q.size() << '\n';
    for(int i = 1; i <= n; ++i)
        if(pus[i])
            cout << i << " ";
    return 0;
}

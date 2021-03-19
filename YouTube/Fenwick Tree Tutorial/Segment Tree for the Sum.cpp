#include<bits/stdc++.h>
using namespace std;
int n, q, v[100002];
long long fenwick[100002];
void update(int node, int value)
{
    for(int i = node; i <= n; i += (i & (-i)))
        fenwick[i] += value;
}
long long compute(int node)
{
    long long ans = 0;
    for(int i = node; i > 0; i -= (i & (-i)))
        ans += fenwick[i];
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        update(i, v[i]);
    }
    for(int i = 1; i <= q; ++i)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int a, b;
            cin >> a >> b;
            ++a;
            update(a, b - v[a]);
            v[a] = b;
        }
        if(type == 2)
        {
            int a, b;
            cin >> a >> b;
            ++a;
            cout << compute(b) - compute(a-1) << '\n';
        }
    }
    return 0;
}

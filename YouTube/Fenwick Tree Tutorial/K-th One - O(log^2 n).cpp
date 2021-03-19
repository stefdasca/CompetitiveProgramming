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
 
int solve(int k)
{
	int L = 1;
	int R = n;
	int ans = 0;
	while(L <= R)
	{
		int mid = (L + R) / 2;
		if(compute(mid) >= k)
			ans = mid, R = mid - 1;
		else
			L = mid + 1;
	}
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
            int a;
            cin >> a;
            ++a;
            if(v[a] == 1)
				update(a, -1);
			else
				update(a, 1);
            v[a] ^= 1;
        }
        if(type == 2)
        {
            int k;
            cin >> k;
            ++k;
            cout << solve(k)-1 << '\n';
        }
    }
    return 0;
}

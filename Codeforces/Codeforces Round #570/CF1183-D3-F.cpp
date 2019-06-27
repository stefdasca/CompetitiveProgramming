#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int q, n, a[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	n=unique(a, a+n)-a;
	int ans=a[n-1];
	for(int i=0; i<n; ++i) {
		int j=i-1;
		while(~j&&a[i]%a[j]==0)
			--j;
		if(~j) {
			ans=max(a[i]+a[j], ans);
			int k=j-1;
			while(~k&&(a[i]%a[k]==0||a[j]%a[k]==0))
				--k;
			if(~k)
				ans=max(a[i]+a[j]+a[k], ans);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	while(q--)
		solve();
}

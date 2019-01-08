#include<bits/stdc++.h>
using namespace std;
int n;
int v[1000002];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i < n; ++i)
        sum += max(v[i], v[i+1]);
    cout << sum;
    return 0;
}

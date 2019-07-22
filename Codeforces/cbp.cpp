
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do smth instead of nothing and stay organized
*/

#include<bits/stdc++.h>

using namespace std;

long long v[300002], sp[300002];
int main(){

    ios_base::sync_with_stdio(false), cin.tie(NULL);

    long long n, m, k;

    cin >> n >> m >> k;

    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    for(int mod = 0; mod < m; ++mod){
        long long mn = 0;
        for(int i = 1; i <= n; ++i){
            sp[i] = v[i] + sp[i-1];
            if(i % m == mod){
                sp[i] -= k;
                ans = max(ans, sp[i] - mn);
            }
            mn = min(mn, sp[i]);
        }
    }
    cout << ans;
    return 0;

}

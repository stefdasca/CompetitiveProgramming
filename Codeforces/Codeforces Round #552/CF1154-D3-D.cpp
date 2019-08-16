#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;
int n, v[200002], b, a, fa;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> b >> a;
    fa = a;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        if(!a && !b)
        {
            cout << i-1;
            return 0;
        }
        if(v[i] == 1)
        {
            if(a == fa || b == 0)
                --a;
            else
                --b, ++a;
        }
        else
        {
            if(a)
                --a;
            else
                --b;
        }
    }
    cout << n;
    return 0;
}

#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9
 
using namespace std;
 
typedef long long ll;
 
int n, q, prim[7002], cnt, viz[7002], mu[7002];
bitset<7002> prec[7002], form[100002], pinex[7002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    mu[1] = 1;
    for(int i = 2; i <= 7000; ++i)
    {
        if(!viz[i])
        {
            prim[++cnt] = i;
            mu[i] = -1;
        }
        for(int j = 1; j <= cnt && prim[j] * i <= 7000; ++j)
        {
            viz[i * prim[j]] = 1;
            if(i % prim[j] == 0)
                break;
            mu[i * prim[j]] = -mu[i];
        }
    }
    for(int i = 1; i <= 7000; ++i)
        for(int j = i; j <= 7000; j += i)
            prec[j][i] = 1, pinex[i][j] = (mu[j / i] != 0);
    for(; q; --q)
    {
        int tip;
        cin >> tip;
        if(tip == 1)
        {
            int val, nr;
            cin >> val >> nr;
            form[val] = prec[nr];
        }
        if(tip == 2)
        {
            int nr, a, b;
            cin >> nr >> a >> b;
            form[nr] = form[a] ^ form[b];
        }
        if(tip == 3)
        {
            int nr, a, b;
            cin >> nr >> a >> b;
            form[nr] = form[a] & form[b];
        }
        if(tip == 4)
        {
            int nr, a;
            cin >> nr >> a;
            cout << ((pinex[a] & form[nr]).count() & 1);
        }
    }
    return 0;
}

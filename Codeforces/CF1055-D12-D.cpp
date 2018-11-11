/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct siruri
{
    string a, b;
};
siruri v[3002];
int len[3002];
int L[3002], R[3002];
long long hsh2[3002], hsh[3002], mod = 1000000007;
long long p100003[3002];
int l[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    p100003[0] = 1;
    for(int i = 1; i <= 3000; ++i)
        p100003[i] = (p100003[i-1] * 100003LL) % mod;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].a;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].b;
    int mx = -1;
    int unde = 0;
    for(int i = 1; i <= n; ++i)
    {
        int st = -1;
        int dr = -1;
        for(int j = 0; j < v[i].a.size(); ++j)
            if(v[i].a[j] != v[i].b[j])
            {
                if(st == -1)
                    st = j;
                dr = j;
            }
        if(st != -1)
        {
            len[i] = dr - st;
            if(mx == -1)
                mx = len[i], unde = i;
            else
                if(dr - st > mx)
                {
                    cout << "NO";
                    return 0;
                }
        }
        L[i] = st;
        R[i] = dr;
    }
    while(L[unde] > 0)
    {
        char A = v[unde].a[L[unde]-1];
        char B = v[unde].b[L[unde]-1];
        bool gg = 1;
        for(int j = 1; j <= n; ++j)
            if(L[j] != -1)
            {
                if(L[j] == 0)
                    gg = 0;
                if(v[j].a[L[j]-1] != A)
                    gg = 0;
            }
        if(!gg)
            break;
        for(int j = 1; j <= n; ++j)
            if(L[j] != -1)
                L[j]--;
    }
    while(R[unde] < v[unde].a.size())
    {
        char A = v[unde].a[R[unde]];
        char B = v[unde].b[R[unde]];
        bool gg = 1;
        for(int j = 1; j <= n; ++j)
            if(R[j] != -1)
            {
                if(R[j] == v[j].a.size())
                    gg = 0;
                if(v[j].a[R[j]] != A)
                    gg = 0;
            }
        if(!gg)
            break;
        for(int j = 1; j <= n; ++j)
            if(R[j] != -1)
                R[j]++;
    }
    string ra;
    for(int j = L[unde]; j < R[unde]; ++j)
        ra += v[unde].a[j];
    string rp;
    for(int j = L[unde]; j < R[unde]; ++j)
        rp += v[unde].b[j];
    long long hshr = 0;
    for(int j = 0; j < rp.size(); ++j)
        hshr = (hshr  * 100003 + (ra[j] - 'a')) % mod;
    long long hsh1 = 0;
    for(int j = 0; j < rp.size(); ++j)
        hsh1 = (hsh1  * 100003 + (rp[j] - 'a')) % mod;
    mx = R[unde] - L[unde];
    for(int i = 1; i <= n; ++i)
    {
        bool rau = 0;
        if(L[i] == -1)
            rau = 1;
        for(int j = 0; j < v[i].b.size(); ++j)
        {
            hsh[j + 1] = (hsh[j] * 100003 + (v[i].b[j] - 'a')) % mod;
            hsh2[j + 1] = (hsh2[j] * 100003 + (v[i].a[j] - 'a')) % mod;
        }
        for(int j = 0; j + mx <= v[i].b.size(); ++j)
        {
            long long hshz = hsh[j + mx];
            hshz = (hshz - hsh[j] * p100003[rp.size()] + mod * p100003[rp.size()])%mod;
            long long hshx = hsh2[j + mx];
            hshx = (hshx - hsh2[j] * p100003[rp.size()] + mod * p100003[rp.size()])%mod;
            if(hshx == hshr)
            {
                if(L[i] != j || hshz != hsh1)
                {
                    cout << "NO";
                    return 0;
                }
                rau = 1;
                break;
            }
        }
        if(!rau)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    cout << ra << '\n';
    cout << rp << '\n';
    return 0;
}
}

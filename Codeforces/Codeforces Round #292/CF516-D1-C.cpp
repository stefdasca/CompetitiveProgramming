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

int n, m;

int vd[100002], vh[100002], plc[100002];

ll bst[1002], optL[1002], optR[1002], sp[100002];
ll amL[1002], amR[1002];

ll st[1002], sf[1002];

ll am(ll b, ll a)
{
    if(a == b)
        return 2LL * vh[a];
    if(b >= a)
        return 2LL * (vh[b] + vh[a]) + (b > 0) * sp[b - 1] - (a > 0) * sp[a - 1];
    return 2LL * (vh[b] + vh[a]) + sp[n] - (a > 0) * sp[a - 1] + (b > 0) * sp[b - 1];
}

int d[1002];
int sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> vd[i], sp[i] = sp[i-1] + vd[i];
    for(int i = 1; i <= n; ++i)
        cin >> vh[i];
    int buk = sqrt(n);
    int oo = 1;
    for(int i = 1; i <= n; i += buk)
    {
        for(int j = i; j <= min(n, i + buk - 1); ++j)
        {
            if(!st[oo])
                st[oo] = j;
            sf[oo] = j;
            plc[j] = oo;
            ll dist = 0;
            for(int k = j + 1; k <= min(n, i + buk - 1); ++k)
            {
                dist += vd[k - 1];
                bst[oo] = max(bst[oo], dist + 2 * vh[j] + 2 * vh[k]);
            }
        }
        ll dist = 0;
        for(int k = i; k <= min(n, i + buk - 1); ++k)
        {
            if(k == i)
                optL[oo] = k, amL[oo] = 2 * vh[k];
            else
            {
                dist += vd[k - 1];
                if(dist + 2 * vh[k] >= amL[oo])
                    optL[oo] = k, amL[oo] = dist + 2 * vh[k];
            }
        }
        dist = 0;
        for(int k = min(n, i + buk - 1); k >= i; --k)
        {
            if(k == min(n, i + buk - 1))
                optR[oo] = k, amR[oo] = 2 * vh[k];
            else
            {
                dist += vd[k];
                if(dist + 2 * vh[k] >= amR[oo])
                    optR[oo] = k, amR[oo] = dist + 2 * vh[k];
            }
        }
        ++oo;
    }
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        int st = b + 1;
        int dr = a - 1;
        if(st > n)
            st -= n;
        if(dr <= 0)
            dr += n;
        sz = -1;
        int pp = sf[plc[st]];
        ll mx = 0;
        if(st <= dr)
        {
            while(st <= dr && st <= pp)
            {
                if(sz >= 0)
                    mx = max(mx, am(st, d[0]));
                while(sz >= 0 && 2 * vh[st] >= am(st, d[sz]) - 2 * vh[st])
                    --sz;
                d[++sz] = st;
                ++st;
            }
            while(st <= dr && sf[plc[st]] <= dr)
            {
                mx = max(mx, bst[plc[st]]);
                if(sz >= 0)
                    mx = max(mx, am(optL[plc[st]], d[0]));
                while(sz >= 0 && 2 * vh[optR[plc[st]]] >= am(optR[plc[st]], d[sz]) - 2 * vh[optR[plc[st]]])
                    --sz;
                d[++sz] = optR[plc[st]];
                st = sf[plc[st]] + 1;
            }
            while(st <= dr)
            {
                if(sz >= 0)
                    mx = max(mx, am(st, d[0]));
                while(sz >= 0 && 2 * vh[st] >= am(st, d[sz]) - 2 * vh[st])
                    --sz;
                d[++sz] = st;
                ++st;
            }
        }
        else
        {
            while(st <= pp)
            {
                if(sz >= 0)
                    mx = max(mx, am(st, d[0]));
                while(sz >= 0 && 2 * vh[st] >= am(st, d[sz]) - 2 * vh[st])
                    --sz;
                d[++sz] = st;
                ++st;
            }
            while(st <= n)
            {
                mx = max(mx, bst[plc[st]]);
                if(sz >= 0)
                    mx = max(mx, am(optL[plc[st]], d[0]));
                while(sz >= 0 && 2 * vh[optR[plc[st]]] >= am(optR[plc[st]], d[sz]) - 2 * vh[optR[plc[st]]])
                    --sz;
                d[++sz] = optR[plc[st]];
                st = sf[plc[st]] + 1;
            }
            st = 1;
            while(st <= dr && sf[plc[st]] <= dr)
            {
                mx = max(mx, bst[plc[st]]);
                if(sz >= 0)
                    mx = max(mx, am(optL[plc[st]], d[0]));
                while(sz >= 0 && 2 * vh[optR[plc[st]]] >= am(optR[plc[st]], d[sz]) - 2 * vh[optR[plc[st]]])
                    --sz;
                d[++sz] = optR[plc[st]];
                st = sf[plc[st]] + 1;
            }
            while(st <= dr)
            {
                if(sz >= 0)
                    mx = max(mx, am(st, d[0]));
                while(sz >= 0 && 2 * vh[st] >= am(st, d[sz]) - 2 * vh[st])
                    --sz;
                d[++sz] = st;
                ++st;
            }
        }
        cout << mx << '\n';
    }
    return 0;
}

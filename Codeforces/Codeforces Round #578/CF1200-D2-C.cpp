#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, m, q;

ll cmmdc(ll a, ll b)
{
    ll c = 0;
    while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    ll val = cmmdc(n, m);
    for(int i = 1; i <= q; ++i)
    {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll va, vb;
        ll ea, eb;
        if(sx == 1)
        {
            if(sy % (n / val) == 0)
            {
                va = sy;
                vb = sy - (n / val);
            }
            else
            {
                va = sy + (n / val) - (sy % (n / val));
                vb = sy - (sy % (n / val));
            }
            ea = (va / (n / val)) * (m / val);
            eb = (vb / (n / val)) * (m / val);
            if(va > vb)
                swap(va, vb);
            if(ea > eb)
                swap(ea, eb);
            if(ex == 1)
            {
                if(va < ey && ey <= vb)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
            {
                if(ea < ey && ey <= eb)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
        else
        {
            if(sy % (m / val) == 0)
            {
                va = sy;
                vb = sy - (m / val);
            }
            else
            {
                va = sy + (m / val) - (sy % (m / val));
                vb = sy - (sy % (m / val));
            }
            ea = (va / (m / val)) * (n / val);
            eb = (vb / (m / val)) * (n / val);
             if(va > vb)
                swap(va, vb);
            if(ea > eb)
                swap(ea, eb);
            if(ex == 2)
            {
                if(va < ey && ey <= vb)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else
            {
                if(ea < ey && ey <= eb)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}

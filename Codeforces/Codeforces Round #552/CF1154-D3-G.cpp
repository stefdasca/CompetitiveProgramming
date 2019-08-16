#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;
int n, v[1000002], frq[10000002];
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
ll mini = (1LL<<60);
int a = 0, b = 0;
void ciur()
{
    for(int i = 1; i <= 10000000; i++)
    {
        int ct = 0;
        int va = 0, vb = 0;
        for(int j = i; j <= 10000000; j += i)
        {
            if(frq[j])
            {
                if(va == 0)
                {
                    ct++, va = j;
                    if(frq[j] >= 2)
                    {
                        ct++, vb = j;
                        break;
                    }
                }
                else
                {
                    ct++;
                    vb = j;
                    break;
                }
            }
        }
        if(va && vb)
            if(1LL * va * vb / cmmdc(va, vb) < mini)
                mini = 1LL * va * vb / cmmdc(va, vb), a = va, b = vb;
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], frq[v[i]]++;
    ciur();
    for(int i = 1; i <= n; ++i)
        if(v[i] == a)
            cout << i << " ", a = 0;
        else
            if(v[i] == b)
                cout << i << " ", b = 0;
    return 0;
}

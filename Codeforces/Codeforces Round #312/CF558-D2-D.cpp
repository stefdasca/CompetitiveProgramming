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


int add(int a, int b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int h, m, nq;
ll le, rr, sol;
pair<ll, ll> v[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>h>>m;
    le=1LL<<(h-1);
    rr=(1LL<<h)-1;
    while(m--)
    {
        long long t, x, y;
        int ans;
        cin>>t>>x>>y>>ans;
        x = (x<<(h-t));
        y = ((y+1)<<(h-t))-1;
        if(ans==1)
        {
            le=max(le, x);
            rr=min(rr, y);
        }
        else
            v[++nq]=make_pair(x, y);
    }
    if(le>rr)
    {
        cout<<"Game cheated!\n";
        return 0;
    }
    sort(v+1, v+nq+1);
    int gs=0;
    for(int i=1; i<=nq; ++i)
    {
        if(v[i].first>rr)
            continue;

        if(v[i].first>le+1 || (v[i].first>le && gs==1))
        {
            cout<<"Data not sufficient!\n";
            return 0;
        }
        if(v[i].first==le+1)
        {
            gs=1;
            sol=le;
        }
        le=max(le, v[i].second+1);
    }
    if(le>rr)
    {
        if(gs==1)
            cout<<sol<<"\n";
        else
            cout<<"Game cheated!\n";
    }
    else
    {
        if(le==rr && gs==0)
            cout<<le<<"\n";
        else
            cout<<"Data not sufficient!\n";
    }
    return 0;
}

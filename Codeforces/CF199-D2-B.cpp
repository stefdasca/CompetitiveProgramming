#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define ld long double
#define ll long long
using namespace std;
ld dist(ll x, ll y)
{
    return sqrt(x*x + y*y);
}
bool good(ld d, ld r, ld r1, ld R1)
{
    if(d+r <= r1)return 1; //circle inside ring
    if(d >= r+R1)return 1; //they are too far apart
    if(d+R1 <= r)return 1; //circle outside ring
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x1,y1,x2,y2,r1,R1,r2,R2;
    cin>>x1>>y1>>r1>>R1>>x2>>y2>>r2>>R2;
    ld d = dist(x1-x2,y1-y2);
    int ats = good(d,r1,r2,R2) + good(d,R1,r2,R2) + good(d,r2,r1,R1) + good(d,R2,r1,R1);
    cout<<ats;
    return 0;
}

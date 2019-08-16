#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int n, v[5], a, b, c, d, x, y, z;
int main(){

    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>a>>b>>c>>d;
    v[1]=a;
    v[2]=b;
    v[3]=c;
    v[4]=d;
    sort(v+1, v+5);
    z=v[4]-v[1];
    y=v[3]-z;
    x=v[1]-y;
    cout<<x<<' '<<y<<' '<<z;
    return 0;
}

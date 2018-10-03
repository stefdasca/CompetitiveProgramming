#include<bits/stdc++.h>
using namespace std;
ifstream f("lapte.in");
ofstream g("lapte.out");
int n,l;
struct milk
{
    int a,b;
};
milk v[102];
int dp[102][102],cat[102][102];
bool viz[102][102];
int mx(int t, int i, int p)
{
    return (t-v[i].a*p)/v[i].b;
}
bool check(int maxx)
{
    for(int i = 0; i < 101; ++i)
        for(int j = 0; j < 101; ++j)
            dp[i][j] = -1e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=l && v[i].a*j<=maxx;++j)
            for(int k=j;k<=l;++k)
                if(dp[i][k]<mx(maxx, i, j)+dp[i-1][k-j])
                {
                    dp[i][k]=mx(maxx, i, j)+dp[i-1][k-j];
                    cat[i][k]=j;
                }
    return (dp[n][l]>=l);
}
struct ss
{
    int a,b;
};
ss aaaa[102];
int main()
{
    f>>n>>l;
    for(int i=1;i<=n;++i)
        f>>v[i].a>>v[i].b;
    int b=1;
    int e=101;
    int sol=0;
    while(b<=e)
    {
        int mid=(b+e)/2;
        if(check(mid))
            sol=mid,e=mid-1;
        else
            b=mid+1;
    }
    check(sol);
    g<<sol<<'\n';
    for(int i=n,aa=l;i;aa-=cat[i][aa],--i)
        aaaa[i]={cat[i][aa],mx(sol,i,cat[i][aa])};
    for(int i=1;i<=n;++i)
        g<<aaaa[i].a<<" "<<aaaa[i].b<<'\n';
    return 0;
}

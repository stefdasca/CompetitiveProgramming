#include<bits/stdc++.h>
using namespace std;
ifstream f("pavare2.in");
ofstream g("pavare2.out");
int n,a,b;
char q[50];
int soll[50];
int dp[102][202][52];
int lg[102][202];
int cate[52],L;
int xx(int nr)
{
    return a+nr;
}
void add(int a[], int &l, int b[], int l2)
{
    for(int i=1;i<=l2;++i)
        a[i]+=b[i];
    l=max(l,l2);
    for(int i=1;i<=l;++i)
    {
        if(a[i]>=10)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
            if(i==l)
                ++l;
        }
    }
}
bool bg(int a[], int l, int b[], int l2)
{
    if(l>l2)
        return 1;
    if(l<l2)
        return 0;
    for(int i=l;i>=1;--i)
    {
        if(a[i]>b[i])
            return 1;
        if(a[i]<b[i])
            return 0;
    }
    return 0;
}
void sc(int a[], int &l, int b[], int l2)
{
    for(int i=1;i<=l2;++i)
        a[i]-=b[i];
    for(int i=1;i<=l;++i)
    {
        if(a[i]<0)
        {
            a[i+1]--;
            a[i]+=10;
        }
    }
    while(a[l]==0)
        --l;
}
int main()
{
    f>>n>>a>>b;
    f>>q+1;
    int sz=strlen(q+1);
    for(int i=sz;i>=1;--i)
        soll[sz-i+1]=q[i]-'0';
    /// >=0 => tip B , altfel, tip A
    dp[n][xx(1)][1]=dp[n][xx(-1)][1]=1;
    lg[n][xx(1)]=lg[n][xx(-1)]=1;
    for(int i=n;i>1;--i)
        for(int j=-a;j<=b;++j)
        {
            if(!lg[i][xx(j)])
                continue;
            if(j<0)
            {
                if(j!=-a)
                    add(dp[i-1][xx(j-1)],lg[i-1][xx(j-1)],dp[i][xx(j)],lg[i][xx(j)]);
                add(dp[i-1][xx(1)],lg[i-1][xx(1)],dp[i][xx(j)],lg[i][xx(j)]);
            }
            else
            {
                if(j!=b)
                    add(dp[i-1][xx(j+1)],lg[i-1][xx(j+1)],dp[i][xx(j)],lg[i][xx(j)]);
                add(dp[i-1][xx(-1)],lg[i-1][xx(-1)],dp[i][xx(j)],lg[i][xx(j)]);
            }
        }
    for(int j=-a;j<=b;++j)
        add(cate,L,dp[1][xx(j)],lg[1][xx(j)]);
    for(int j=L;j>=1;--j)
        g<<cate[j];
    g<<'\n';
    int i=1;
    int pr=1;
    while(i<=n)
    {
        int pos;
        if(pr==0)
            pos=1;
        else
            pos=-a;
        while(bg(soll,sz,dp[i][xx(pos)],lg[i][xx(pos)]))
            sc(soll,sz,dp[i][xx(pos)],lg[i][xx(pos)]),++pos;
        if(pos<0)
        {
            pr=0;
            for(int j=pos;j<0;++j)
                g<<0;
            i+=(-pos);
        }
        else
        {
            pr=1;
            for(int j=1;j<=pos;++j)
                g<<1;
            i+=pos;
        }
    }
    return 0;
}

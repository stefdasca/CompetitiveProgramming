#include<bits/stdc++.h>
#define maxN 505
#define maxVal 1010
#define maxCif 100
#define base 1000
using namespace std;
int n,i,j,x;
int dp[maxVal][maxCif],unu[maxCif];
void add(int a[maxCif],int b[maxCif])
{
    int i,t=0;
    for(i=1;i<=a[0] || i<=b[0] || t>0;i++)
        a[i]=a[i]+b[i]+t,
        t=a[i]/base,
        a[i]%=base;
    a[0]=i-1;
}
int main()
{
    freopen("indep.in","r",stdin);
    freopen("indep.out","w",stdout);
    scanf("%d",&n);
    unu[0]=unu[1]=1;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        for(j=1;j<=1000;j++)
            add(dp[__gcd(x,j)],dp[j]);
        add(dp[x],unu);
    }
    printf("%d",dp[1][dp[1][0]]);
    for(i=dp[1][0]-1;i>=1;i--)
        printf("%.3d",dp[1][i]);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("lsort.in");
ofstream g("lsort.out");
int n;
int v[1002],poz[1002];
int dp[1002][1002];
short whol[1002][1002],whor[1002][1002];
short wil[1002][1002],wir[1002][1002];
deque<int>d;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int nr;
        f>>nr;
        v[i]=nr;
        poz[nr]=i;
    }
    for(int i=1;i<=n;++i)
    {
        wil[i][1]=wir[i][1]=poz[i];
        int cts=0,ctd=0;
        for(int j=2;j<=n;++j)
        {
            int el=i-j+1;
            if(el>0)
            {
                ctd+=(poz[el]<poz[i]);
                wir[i][j]=poz[i]-ctd;
            }
            el=i+j-1;
            if(el<=n)
            {
                cts+=(poz[el]<poz[i]);
                wil[i][j]=poz[i]-cts;
            }
        }
    }
    for(int i=1;i<=n;++i)
        dp[i][i]=poz[i];
    for(int i=2;i<=n;++i)
        for(int j=1;j<=n-i+1;++j)
        {
            int L=j;
            int R=j+i-1;
            if(dp[L][R-1]+wir[R][i]*i<=dp[L+1][R]+wil[L][i]*i){
                dp[L][R]=dp[j][R-1]+wir[R][i]*i;
                whol[L][R]=L;
                whor[L][R]=R-1;
            }
            else
            {
                dp[L][R]=dp[L+1][R]+wil[L][i]*i;
                whol[L][R]=L+1;
                whor[L][R]=R;
            }
        }
    g<<dp[1][n]<<'\n';
    int poz=1;
    int poz2=n;
    while(poz2>=poz)
    {
        if(whol[poz][poz2]==poz)
            d.push_front(poz2),--poz2;
        else
            d.push_front(poz),++poz;
    }
    for(int i=0;i<n;++i)
        g<<d[i]<<" ";
    return 0;
}

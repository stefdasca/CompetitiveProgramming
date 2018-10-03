/// 3 burned, 4 left
#include<bits/stdc++.h>
using namespace std;
ifstream f("elimin.in");
ofstream g("elimin.out");
int n,m,r,c;
int solmax;
short mat[602][602];
int sum[602],sum2[602];
short ar[21];
void bkt_lin()
{
    int possum=0;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            sum[i]+=mat[j][i],possum+=mat[j][i];
    for(int i=0;i<(1<<n);++i)
    {
        int poz=0;
        for(int j=0;j<n;++j)
            if(i&(1<<j)){
                ar[++poz]=j+1;
                if(poz>r)
                    break;
            }
        if(poz==r)
        {
            for(int j=1;j<=m;++j)
                sum2[j]=sum[j];
            int possum2=possum;
            for(int q=1;q<=poz;++q)
                for(int j=1;j<=m;++j)
                    sum2[j]-=mat[ar[q]][j],possum2-=mat[ar[q]][j];
            sort(sum2+1,sum2+m+1);
            for(int j=1;j<=c;++j)
                possum2-=sum2[j];
            if(possum2>solmax)
                solmax=possum2;
        }
    }
}
void bkt_col()
{
    int possum=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            sum[i]+=mat[i][j],possum+=mat[i][j];
    for(int i=0;i<(1<<m);++i)
    {
        int poz=0;
        for(int j=0;j<m;++j)
            if(i&(1<<j)){
                ar[++poz]=j+1;
                if(poz>c)
                    break;
            }
        if(poz==c)
        {
            int possum2=possum;
            for(int j=1;j<=n;++j)
                sum2[j]=sum[j];
            for(int q=1;q<=poz;++q)
                for(int j=1;j<=n;++j)
                    sum2[j]-=mat[j][ar[q]],possum2-=mat[j][ar[q]];
            sort(sum2+1,sum2+n+1);
            for(int j=1;j<=r;++j)
                possum2-=sum2[j];
            if(possum2>solmax)
                solmax=possum2;
        }
    }
}
int main()
{
    f>>n>>m>>r>>c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j];
    if(n<m)
        bkt_lin();
    else
        bkt_col();
    g<<solmax;
    return 0;
}

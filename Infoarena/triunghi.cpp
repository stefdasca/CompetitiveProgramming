/// will the grand dream fall apart?
#include<bits/stdc++.h>
using namespace std;
ifstream f("triunghi.in");
ofstream g("triunghi.out");
int n,s;
int mat[19][19];
int hminf[19];
int vect[19];
bool solfound;
void bkt(int nod, int sum)
{
    if(sum<=0 || solfound)
    {
        if(sum==0 && !solfound){
            solfound=1;
            for(int i=1;i<=n;++i)
                mat[n][i]=vect[i];
        }
        return;
    }
    for(int i=nod;i<=n;++i)
    {
        vect[i]++;
        bkt(i,sum-hminf[i]);
        vect[i]--;
    }
}
int main()
{
    f>>n>>s;
    for(int i=1;i<=n;++i)
    {
        memset(mat,0,sizeof(mat));
        mat[n][i]=1;
        for(int j=n-1;j>=1;--j)
            for(int k=1;k<=j;++k)
                mat[j][k]=mat[j+1][k]+mat[j+1][k+1];
        for(int j=1;j<=n;++j)
            for(int k=1;k<=j;++k)
                hminf[i]+=mat[j][k];
    }
    for(int i=1;i<=n;++i)
        vect[i]=1,s-=hminf[i];
    memset(mat,0,sizeof(mat));
    bkt(1,s);
    if(!solfound)
        g<<-1;
    else
    {
        for(int i=n-1;i>=1;--i)
            for(int j=1;j<=i;++j)
                mat[i][j]=mat[i+1][j]+mat[i+1][j+1];
        for(int i=1;i<=n;g<<'\n',++i)
            for(int j=1;j<=i;++j)
                g<<mat[i][j]<<" ";
    }
    return 0;
}

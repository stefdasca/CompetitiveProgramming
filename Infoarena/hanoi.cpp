/// Jrue Moez
#include<bits/stdc++.h>
using namespace std;
ifstream f("hanoi.in");
ofstream g("hanoi.out");
int mat[300][300];
int v[102];
int n,k;
void hanoi3()
{
    v[1]=1;
    int l=1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=l;++j)
            v[j]+=v[j];
        for(int j=1;j<=l;++j)
            if(v[j]>9)
            {
                v[j+1]++;
                v[j]-=10;
                if(j+1>l)
                    ++l;
            }
    }
    --v[1];
    for(int j=l;j>=1;--j)
        g<<v[j];
}
int main()
{
    f>>n>>k;
    if(k==3)
        hanoi3();
    else
    {
        mat[1][3]=1;
        for(int i=2;i<=30;++i)
            mat[i][3]=mat[i-1][3]*2+1;
        for(int j=4;j<=k;++j){
            for(int i=1;i<=n;++i)
            {
                mat[i][j]=2*mat[i-1][j]+mat[1][j-1];
                for(int q=i-2;q>0;--q)
                    if(2*mat[q][j]+mat[i-q][j-1]<mat[i][j])
                        mat[i][j]=2*mat[q][j]+mat[i-q][j-1];
                    else
                        break;
            }
        }
       // for(int j=4;j<=k;g<<'\n',++j)
       //     for(int i=1;i<=n;++i)
         //       g<<mat[i][j]<<" ";
        g<<mat[n][k]<<'\n';
    }
    return 0;
}

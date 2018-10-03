#include<bits/stdc++.h>
using namespace std;
ifstream f("joc15.in");
ofstream g("joc15.out");
int n,m,mat[10][10];
int solmin=1e9,rose=1e3;
void orangepee(int L, int C, int cost)
{
    if(cost>solmin)
        return;
    if(L==n)
    {
         int max1=mat[1][1];
         int min1=mat[1][1];
         for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                if(mat[i][j]>max1)
                    max1=mat[i][j];
                if(mat[i][j]<min1)
                    min1=mat[i][j];
            }
        if(max1==min1)
            solmin=min(solmin,cost);
        return;
    }
    int a=mat[L][C];
    int b=mat[L+1][C];
    int c=mat[L][C+1];
    int d=mat[L+1][C+1];
    int max1=max(a,max(b,max(c,d)));
    if(max1!=rose)
    {
        mat[L][C]=mat[L+1][C]=mat[L][C+1]=mat[L+1][C+1]=rose;
        orangepee(1,1,cost+max1-rose);
    }
    mat[L][C]=a;
    mat[L+1][C]=b;
    mat[L][C+1]=c;
    mat[L+1][C+1]=d;
    if(C+1==m)
        orangepee(L+1,1,cost);
    else
        orangepee(L,C+1,cost);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j],rose=min(rose,mat[i][j]);
    orangepee(1,1,0);
    g<<solmin;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("origami.in");
ofstream g("origami.out");
int n,m,mat[350][350],mat2[350][350],q;
void exe1(int cat)
{
    for(int i=cat,j=cat+1;i>=1;--i,++j)
        for(int k=1;k<=n;++k)
            mat[k][j]+=mat[k][i],mat[k][i]=0;
    for(int i=1;i<=n+n;++i)
        for(int j=1;j<=m+m;++j)
            mat2[i][j]=mat[i][j],mat[i][j]=0;
    int nrl=0;
    int nrc=0;
    for(int i=1;i<=n+n;++i)
    {
        nrc=0;
        for(int j=1;j<=m+m;++j)
            if(mat2[i][j]!=0)
                if(!nrc)
                    mat[++nrl][++nrc]=mat2[i][j];
                else
                    mat[nrl][++nrc]=mat2[i][j];
        if(nrc)
            m=nrc;
    }
    n=nrl;
}
void exe2(int cat)
{
    for(int i=cat,j=cat+1;i>=1;--i,++j)
        for(int k=1;k<=m;++k)
            mat[j][k]+=mat[i][k],mat[i][k]=0;
    for(int i=1;i<=n+n;++i)
        for(int j=1;j<=m+m;++j)
            mat2[i][j]=mat[i][j],mat[i][j]=0;
    int nrl=0;
    int nrc=0;
    for(int i=1;i<=n+n;++i)
    {
        nrc=0;
        for(int j=1;j<=m+m;++j)
            if(mat2[i][j]!=0 && !nrc)
            {
                ++nrl;
                ++nrc;
                mat[nrl][nrc]=mat2[i][j];
            }
            else
                if(mat2[i][j]!=0)
                    mat[nrl][++nrc]=mat2[i][j];
        if(nrc)
            m=nrc;
    }
    n=nrl;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            mat[i][j]=1;
    m=n;
    f>>q;
    for(int i=1;i<=q;++i)
    {
        int tip,cat;
        f>>tip>>cat;
        if(tip==1)
            exe1(cat);
        else
            exe2(cat);
    }
    g<<n<<" "<<m<<" ";
    int maxx=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            maxx=max(maxx,mat[i][j]);
    g<<maxx<<'\n';
    return 0;
}

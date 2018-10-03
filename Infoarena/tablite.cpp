#include<bits/stdc++.h>
#define ssor 60106
using namespace std;
ifstream f("tablite.in");
ofstream g("tablite.out");
int n,s;
int mat[3][1002][10];
bool gut[12][12];
int main()
{
    for(int i=0;i<=9;++i)
        for(int j=i;j<=9;++j)
            if(i<=1)
                gut[i][j]=gut[j][i]=0;
            else
                if(j%i==0)
                    gut[i][j]=gut[j][i]=1;
    f>>n>>s;
    for(int i=1;i<=min(9,s);++i)
        mat[2][i][i]=1;
    int smax=min(s,9);
    for(int i=2;i<=n;++i)
    {
        swap(mat[1],mat[2]);
        for(int j=1;j<=smax;++j)
            for(int k=0;k<=9;++k)
                mat[2][j][k]=0;
        for(int j=1;j<=smax;++j)
            for(int k=0;k<=9;++k)
                for(int p=0;p<=9 && j+p<=s;++p)
                    if(gut[k][p]==0){
                        mat[2][j+p][p]+=mat[1][j][k];
                        if(mat[2][j+p][p]>=ssor)
                            mat[2][j+p][p]-=ssor;
                    }
        if(smax+9<=s)
            smax+=9;
        else
            smax=s;
    }
    int sol=0;
    for(int i=0;i<=9;++i)
        sol+=mat[2][s][i];
    g<<sol%ssor<<'\n';
    return 0;
}

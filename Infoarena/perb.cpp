#include<bits/stdc++.h>
using namespace std;
ifstream f("perb.in");
ofstream g("perb.out");
int n,q;
short minc;
int v[602];
char c[602];
int fr[5];
int zz[602][5];
vector<int>dv[602];
short mat[602][602];
int ftq(char x)
{
    if(x=='A')
        return 1;
    if(x=='C')
        return 2;
    if(x=='G')
        return 3;
    return 4;
}
inline void ftm(int st, int sf, int lp)
{
    short sol=0;
    if(lp==sf-st+1 || lp==1)
    {
        int max1=0;
        for(int i=1;i<=4;++i){
            fr[i]=zz[sf][i]-zz[st-1][i];
            max1=max(max1,fr[i]);
        }
        sol=sf-st+1-max1;
        minc=min(minc,sol);
        return;
    }
    for(int j=st;j<st+lp;++j){
        fr[1]=fr[2]=fr[3]=fr[4]=0;
        int len=0;
        for(int k=j;k<=sf;k+=lp)
            fr[v[k]]++,++len;
        int max1=0;
        for(int i=1;i<=4;++i)
            max1=max(max1,fr[i]);
        sol+=len-max1;
        if(sol>=minc)
            return;
    }
    minc=sol;
}
int main()
{
    f>>n>>q;
    f>>c+1;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            dv[j].push_back(i);
    for(int i=1;i<=n;++i){
        v[i]=ftq(c[i]);
        zz[i][v[i]]++;
        for(int j=1;j<=4;++j)
            zz[i][j]+=zz[i-1][j];
    }
    for(;q;--q)
    {
        int a,b;
        f>>a>>b;
        if(mat[a][b])
            g<<mat[a][b]<<'\n';
        else
        {
            minc=b-a+1;
            for(int j=0;j<dv[b-a+1].size();++j)
                ftm(a,b,dv[b-a+1][j]);
            g<<minc<<'\n';
            mat[a][b]=minc;
        }
    }
    return 0;
}

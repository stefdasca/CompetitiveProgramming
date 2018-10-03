#include<bits/stdc++.h>
using namespace std;
ifstream f("electrica.in");
ofstream g("electrica.out");
int n,m,l;
char a[1002][1002];
int sp[1002][1002],sp2[1002][1002];
bool bif[1002][1002];
int ssp(int rx, int ry, int l)
{
    return sp[rx][ry]-sp[max(0,rx-l)][ry]-sp[rx][max(0,ry-l)]+sp[max(0,rx-l)][max(0,ry-l)];
}
int ssp2(int rx, int ry, int l)
{
    return sp2[rx][ry]-sp2[max(0,rx-l)][ry]-sp2[rx][max(0,ry-l)]+sp2[max(0,rx-l)][max(0,ry-l)];
}
bool check()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            int aa;
            if(a[i][j]=='1')
                aa=1;
            else
                aa=0;
            int val=ssp(i,j,l);
            val&=1;
            if(aa^val==1)
                return 0;
        }
    return 1;
}
int main()
{
    f>>n>>m>>l;
    for(int i=1;i<=n;++i)
        f>>a[i]+1;
    for(int i=l;i<=n;++i)
        for(int j=l;j<=m;++j)
        {
            int val;
            if(a[i-l+1][j-l+1]=='0')
                val=0;
            else
                val=1;
            sp[i][j]=sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
            int nr=ssp(i,j,l);
            nr&=1;
            if(val^nr==1)
                ++sp[i][j],bif[i][j]=1;
        }
    bool good=1;
    for(int i=n;i>=1;--i)
        for(int j=m;j>=1;--j)
        {
            sp2[i][j]+=sp2[i+1][j]+sp2[i][j+1]-sp2[i+1][j+1];
            if(bif[i][j])
            {
                sp2[i][j]++;
                sp2[max(0,i-l)][j]--;
                sp2[i][max(0,j-l)]--;
                sp2[max(0,i-l)][max(0,j-l)]++;
            }
            int nr=sp2[i][j]&1;
            int nr2;
            if(a[i][j]=='1')
                nr2=1;
            else
                nr2=0;
            if(nr^nr2==1)
                good=0;
        }
    if(!good)
        g<<-1;
    else
        g<<sp[n][m]<<'\n';
    return 0;
}

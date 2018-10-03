#include<bits/stdc++.h>
using namespace std;
bool a[152][152];
int d[152][152];
int n,m;
int countRobots(int l)
{
    int r=0;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        {
            if(a[i][j])
            {
                d[i][j]=1;
                if(i>l && j<=m-l)
                    d[i][j]+=d[i-l][j+l];
            }
            else
                d[i][j]=max(d[i][j+1],d[i-1][j]);
            r=max(r,d[i][j]);
        }
    return r;
}
int main()
{
    ifstream f("roboti2.in");
    ofstream g("roboti2.out");
    int p,c;
    f>>p;
    f>>n>>m>>c;
    for(int i=1;i<=c;i++)
    {
        int x,y;
        f>>x>>y;
        a[x][y]=1;
    }
    if(p==1)
    {
        int l;
        f>>l;
        g<<countRobots(l)<<'\n';
    }
    else
    {
        int q;
        f>>q;
        while(q--)
        {
            int k;
            f>>k;
            int st=1, dr=n/k+1, ans=0;
            while(st<=dr)
            {
                int m=(st+dr)/2;
                if(countRobots(m)<=k)
                {
                    ans=m;
                    dr=m-1;
                }
                else
                    st=m+1;
            }
            g<<ans<<'\n';
        }
    }
    return 0;
}

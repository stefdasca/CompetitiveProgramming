#include<bits/stdc++.h>
using namespace std;
ifstream f("kinetic.in");
ofstream g("kinetic.out");
pair<int,int>Point[505];
int a[505],b[505],xx[20005][505],n,x,y,t,m;
int Val(int time, int p)
{
    if(time<20005)
        return xx[time][p];
    return Point[p].second + Point[p].first*time;
}
int Bs(int time, int x)
{
    int st=1,dr=n,sol=0,mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(Val(time,mij)<=x)
        {
            sol=mij;
            st=mij+1;
        }
        else
            dr=mij-1;
    }
    return sol;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>Point[i].second>>Point[i].first;
    sort(Point+1,Point+n+1);
    for(int i=0;i<20005;++i)
    {
        for(int j=1;j<=n;++j)
            xx[i][j]=Point[j].second+Point[j].first*i;
        sort(xx[i]+1,xx[i]+n+1);
    }
    while(m--)
    {
        f>>x>>y>>t;
        if(x>y)
            swap(x,y);
        g<<Bs(t,y)-Bs(t,x-1)<<'\n';
    }
    return 0;
}

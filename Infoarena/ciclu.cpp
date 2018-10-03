#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
ifstream f("ciclu.in");
ofstream g("ciclu.out");
const int nmax=1003;
int n,m;
vector<pair<int,double>>v[nmax];
double d[nmax],st,dr;
bool bellman(double x)
{
    queue<int>q;
    int ciclu[nmax]={0};
    for(int i=1;i<=n;++i)
        d[i]=inf;
    for(int k=1;k<=n;++k)
        if(!ciclu[k])
        {
            q.push(k);
            d[k]=0;
            while(!q.empty())
            {
                int a=q.front();
                q.pop();
                ++ciclu[a];
                if(ciclu[a]>=n)
                    return 1;
                for(int i=0;i<v[a].size();++i)
                {
                    int b=v[a][i].first;
                    double c=(double)v[a][i].second-x;
                    if(d[b]>d[a]+c)
                    {
                        d[b]=d[a]+c;
                        q.push(b);
                    }
                }
            }
        }
    return 0;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        double c;
        f>>a>>b>>c;
        v[a].push_back({b,c});
    }
    st=0,dr=100000;
    while(dr-st>0.01)
    {
        double mid=(st+dr)/2;
        if(bellman(mid))
            dr=mid;
        else
            st=mid;
    }
    g<<fixed<<setprecision(2)<<st;
    return 0;
}

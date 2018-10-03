#include<bits/stdc++.h>
using namespace std;
ifstream f("sortari.in");
ofstream g("sortari.out");
int t,n,m;
vector<pair<int,int>>vv;
bool wput[(1<<18)];
bool v[20];
int main()
{
    f>>t;
    for(;t;--t)
    {
        memset(wput,0,sizeof(wput));
        vv.clear();
        f>>n>>m;
        for(int i=1;i<=m;++i)
        {
            int a,b;
            f>>a>>b;
            vv.push_back(make_pair(a,b));
        }
        int val=(1<<n)-1;
        bool ok=1;
        for(int i=0;i<min(100000,1<<n);++i)
        {
            int q=rand()&val;
            while(wput[q]==1)
                q=rand()&val;
            wput[q]=1;
            for(int j=n-1;j>=0;--j)
                if(q&(1<<j))
                    v[j]=1;
                else
                    v[j]=0;
            for(int j=0;j<m;++j)
                if(v[vv[j].first-1]>v[vv[j].second-1])
                    swap(v[vv[j].first-1],v[vv[j].second-1]);
            bool isGut=1;
            for(int j=1;j<n;++j)
                if(v[j]<v[j-1])
                    isGut=0;
            if(!isGut){
                ok=0;
                break;
            }
        }
        g<<ok<<'\n';
    }
    return 0;
}

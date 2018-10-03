#include<bits/stdc++.h>
using namespace std;
ifstream f("srevni.in");
ofstream g("srevni.out");
int n,m,v[100002],a,b;
vector<int>q[100002];
vector<int>y[100002];
void par(int i)
{
    for(int z=0;z<q[i].size();++z){
        bool ok=1;
        for(int s=0;s<y[i].size();++s)
            if(y[i][s]==q[i][z]){
                ok=0;
                break;
            }
        if(ok==1){
            y[i].push_back(q[i][z]);
            par(q[i][z]);
        }
        v[i]=min(v[i],v[q[i][z]]);
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        q[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        par(i);
    for(int i=1;i<=n;++i)
        g<<v[i]<<" ";
    g<<'\n';
    return 0;
}

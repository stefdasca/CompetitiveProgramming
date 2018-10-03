#include<bits/stdc++.h>
using namespace std;
ifstream f("3color.in");
ofstream g("3color.out");
int n,m,a,b;
int ar[1002];
int c[1002][1002];
struct nods
{
    int a,b;
};
nods v[1002];
bool test(nods a, nods b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}
vector<int>q[101];
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a>>b;
        v[i].a=min(a,b);
        v[i].b=max(a,b);
        c[a][b]=c[b][a]=1;
    }
    for(int i=0;i<n;++i)
        ar[i]=-1;
    sort(v+1,v+m+1,test);
    for(int j=1;j<=m;++j)
    {
        if(ar[v[j].a]==-1)
            for(int z=0;z<=99;++z)
                {
                    bool ok=1;
                    for(int r=0;r<q[z].size();++r)
                        if(c[v[j].a][q[z][r]]==1){
                            ok=0;
                            break;
                        }
                    if(ok==1){
                        ar[v[j].a]=z,q[z].push_back(v[j].a);
                        break;
                    }
                }
            if(ar[v[j].b]==-1){
                for(int z=0;z<=99;++z)
                {
                    bool ok=1;
                    for(int r=0;r<q[z].size();++r)
                        if(c[v[j].b][q[z][r]]==1){
                            ok=0;
                            break;
                        }
                    if(ok==1){
                        ar[v[j].b]=z,q[z].push_back(v[j].b);
                        break;
                    }
                }
            }
    }
    for(int i=0;i<n;++i)
        if(ar[i]==-1)
            g<<0<<" ";
        else
            g<<ar[i]<<" ";
    return 0;
}

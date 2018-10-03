#include<bits/stdc++.h>
using namespace std;
ifstream f("drept3.in");
ofstream g("drept3.out");
int n,st,sf;
struct points
{
    int l,c,len;
};
points v[10002];
int v2[10002];
long long tots;
int main()
{
    f>>n;
    int minL=1e5;
    int maxL=0;
    for(int i=1;i<=n;++i){
        f>>v[i].l>>v[i].c>>v[i].len;
        minL=min(minL,v[i].l);
        maxL=max(maxL,v[i].l+v[i].len);
        tots+=1ll*v[i].len*v[i].len;
    }
    int max1=0;
    for(int i=minL;i<=maxL;++i)
    {
        memset(v2,0,sizeof(v2));
        for(int j=1;j<=n;++j)
            if(v[j].l<=i && v[j].l+v[j].len>i)
                v2[v[j].c]++,v2[v[j].c+v[j].len]--;
        for(int j=0;j<=10000;++j){
            if(j)
                v2[j]+=v2[j-1];
            if(v2[j]>1)
                tots=tots-v2[j]+1;
            max1=max(max1,v2[j]);
        }
    }
    g<<tots<<'\n'<<max1<<'\n';
    return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("infinitywar.in");
ofstream g("infinitywar.out");
int n,q;
short nr,z;
int ans[100002],sum[50002],last[50002],l[50002];
vector<short>v2[50002];
struct queries
{
    int a,b;
};
queries v[100002];
int hmb(int a)
{
    return __builtin_popcount(a);
}
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;++i)
    {
        f>>l[i];
        for(int j=1;j<=l[i];++j)
            f>>z,v2[i].push_back(z);
        sort(v2[i].begin(),v2[i].end());
    }
    for(int i=1;i<=q;++i)
        f>>v[i].a>>v[i].b,--v[i].a;
    for(int i=30;i<=10031;i+=31)
    {
        for(int j=1;j<=n;++j)
        {
            sum[j]=0;
            while(last[j] < l[j] && v2[j][last[j]] <= i)
            {
                sum[j]^=(1<<(i-v2[j][last[j]]));
                ++last[j];
            }
            sum[j]^=sum[j-1];
        }
        for(int j=1;j<=q;++j)
            ans[j]+=hmb(sum[v[j].b]^sum[v[j].a]);
    }
    for(int i=1;i<=q;++i)
        g<<ans[i]<<'\n';
    return 0;
}

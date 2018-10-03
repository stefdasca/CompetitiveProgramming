#include<bits/stdc++.h>
using namespace std;
ifstream f("xmoto.in");
ofstream g("xmoto.out");
int n;
long long L;
struct data
{
    double a,b,k,q;
    int val;
};
data v[50002];
bool test(data a, data b)
{
    return a.val<b.val;
}
double sa,sb,sk,sq;
vector<double>sols;
int main()
{
    f>>n>>L;
    for(int i=1;i<=n;++i){
        f>>v[i].a>>v[i].b>>v[i].k>>v[i].q>>v[i].val;
        sk+=v[i].k;
        sa+=v[i].a;
    }
    sort(v+1,v+n+1,test);
    v[n+1].val=10001;
    for(int i=0;i<=n;++i)
    {
        sb+=v[i].b;
        sq+=v[i].q;
        sa-=v[i].a;
        sk-=v[i].k;
        if(i!=0 && v[i].val==v[i+1].val)
            continue;
        double X=(L+0.0)-sq-sk;
        double sol=X/(sa+sb+0.0);
        if(sol>0.0 && (sol>v[i].val && sol<=v[i+1].val))
            sols.push_back(sol);
    }
    g<<sols.size()<<'\n';
    for(int i=0;i<sols.size();++i)
        g<<fixed<<setprecision(6)<<sols[i]<<'\n';
    return 0;
}

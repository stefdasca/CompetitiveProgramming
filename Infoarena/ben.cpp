/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
/// #define MOD 46337
#define MOD 32173
/// I'm so ignorant sometimes
using namespace std;
ifstream f("ben.in");
ofstream g("ben.out");
int n;
int nxtfree[30002];
int hmc[30002],mxi,A[30002],a[30002];
struct in
{
    int a,b;
};
in v[30002];
bool test(in a, in b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}
struct cmp
{
    bool operator()(int a, int b)
    {
        return nxtfree[a]>nxtfree[b];
    }
};
deque<int>d;
priority_queue<int,vector<int>,cmp>q;
long long arj(int n, int k)
{
    long long prd=1;
    for(int i=n-k+1;i<=n;++i)
        prd=(prd*i)%MOD;
    return prd;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>v[i].a>>v[i].b;
        hmc[v[i].a]++;
        mxi=max(mxi,v[i].b);
        A[v[i].a]++;
        A[v[i].b+1]--;
    }
    sort(v+1,v+n+1,test);
    d.push_back(1);
    int minp=1;
    for(int i=1;i<=n;++i)
    {
        while(!q.empty() && nxtfree[q.top()]<=v[i].a)
        {
            nxtfree[q.top()]=0;
            d.push_back(q.top());
            q.pop();
        }
        if(d.empty())
            d.push_back(++minp);
        int qq=d.front();
        d.pop_front();
        nxtfree[qq]=v[i].b;
        q.push(qq);
    }
    for(int i=1;i<=mxi;++i)
        A[i]+=A[i-1];
    g<<minp<<" ";
    long long mod=1;
    for(int i=1;i<=mxi;++i)
        mod=(mod*arj(minp+hmc[i]-A[i],hmc[i]))%MOD;
    g<<mod<<'\n';
    return 0;
}

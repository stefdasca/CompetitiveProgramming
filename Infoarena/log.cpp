#include<bits/stdc++.h>
using namespace std;
ifstream f("log.in");
ofstream g("log.out");
int n;
int t1,t2,t3;
struct logs
{
    int base, value;
};
logs v[10002];
int dp[10002];
int main()
{
    f>>n;
    f>>t1>>t2>>t3;
    for(int i=1;i<=n;++i)
        f>>v[i].base>>v[i].value;
    dp[1]=t3*(v[1].base-v[1].value)*(v[1].base-v[1].value);
    for(int i=2;i<=n;++i)
    {
        dp[i]=1e9;
        int B=v[i].base;
        int V=v[i].value;
        int poz=i-1;
        int coe=0;
        while(poz>=0)
        {
            int val=dp[poz]+(poz>0)*t1+t3*(B-V)*(B-V)+coe;
            if(val<dp[i])
                dp[i]=val;
            if(v[poz].value==B)
                B=v[poz].base,coe+=t2;
            else
                break;
            --poz;
        }
    }
    g<<dp[n];
    return 0;
}

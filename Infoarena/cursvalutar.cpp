#include<bits/stdc++.h>
using namespace std;
ifstream f("cursvalutar.in");
ofstream g("cursvalutar.out");
int t;
double s;
int n,z;
double a,b;
double dp[26];
void solve_the_rose()
{
    double max1=s;
    for(int j=1;j<=z;++j)
        dp[j]=1;
    for(int i=1;i<=n;++i)
    {
        f>>a;
        for(int j=2;j<=z;++j)
        {
            f>>b;
            dp[j]=max(dp[j],b/a);
            a=b;
        }
    }
    for(int i=2;i<=z;++i)
        max1*=dp[i];
    g<<fixed<<setprecision(6)<<max1<<'\n';
}
void read_the_rose()
{
    f>>t;
    for(;t;--t)
    {
        f>>s>>n>>z;
        solve_the_rose();
    }
}
int main()
{
    read_the_rose();
    return 0;
}

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("nkl.in");
ofstream g("nkl.out");
int n;
vector<int>prime;
void divi()
{
    for(int i=2;i*i<=n;++i)
        if(n%i==0)
        {
            prime.push_back(0);
            while(n%i==0)
                n/=i,++prime.back();
        }
    if(n>1)
        prime.push_back(1);
}
int q,k,l;
int comb[1004][1004];
int pw[36][1002];
void proc()
{
    for(int i=0;i<=1002;++i)
    {
        comb[i][0]=1;
        for(int j=1;j<=i;++j)
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
    }
    for(int i=1;i<=35;++i)
    {
        pw[i][0]=1;
        for(int j=1;j<=1002;++j)
            pw[i][j]=(1LL*pw[i][j-1]*i)%mod;
    }
}
int main()
{
    f>>n;
    divi();
    proc();
    f>>q;
    for(;q;--q)
    {
        f>>k>>l;
        long long sol=1;
        for(int i=0;i<prime.size();++i)
        {
            long long sol2=0;
            for(int j=l-1;j>=0;--j)
            {
                long long sol3=comb[k][j];
                sol3=(sol3*pw[prime[i]][j])%mod;
                sol2=(sol2+sol3)%mod;
            }
            sol=(sol*sol2)%mod;
        }
        g<<sol<<'\n';
    }
    return 0;
}

#include<fstream>
using namespace std;
ifstream f("kperm.in");
ofstream g("kperm.out");
long long n,k,nr1,nr2,cnt1,cnt2,fact[5001],ans1,ans2;
long long power(long long a, int b)
{
    if(!b)
        return 1;
    if(b&1)
        return a * power(a*a%666013, b>>1) %666013;
    return power(a*a%666013, b>>1);
}
int main()
{
    f>>n>>k;
    if(k%2==0)
        g<<0;
    else
    {
        nr1 = n%k;
        nr2 = k-nr1;
        cnt1 = n/k+1;
        cnt2 = n/k;

        fact[0] = 1;
        for(int i=1; i<=n; ++i)
            fact[i] = fact[i-1]*i%666013;

        ans1 = fact[nr1] * power(fact[cnt1], nr1) %666013;
        ans2 = fact[nr2] * power(fact[cnt2], nr2) %666013;
        g<<(ans1*ans2)%666013;
    }
    return 0;
}


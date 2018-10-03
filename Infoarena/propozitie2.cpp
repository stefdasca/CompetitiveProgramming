#include<bits/stdc++.h>
#define mod 666019
using namespace std;
ifstream f("propozitie2.in");
ofstream g("propozitie2.out");
int dp[5002];
char c[5002],q,y;
short frq[27],L,n;
string c3,c2;
unordered_map<string,int>m;
unordered_map <string,int>::iterator it;
string::iterator p;
int main()
{
    f>>(c+1);
    dp[0]=1;
    f>>n;
    for(int j=0;j<=51;++j)
        c3.push_back('0');
    for(int i=1;i<=n;++i)
    {
        f>>c2;
        sort(c2.begin(),c2.end());
        m[c2]++;
    }
    L=strlen(c+1);
    for(int i=1;i<=L;++i)
    {
        string b;
        for(int j=i;j && i-j<100;j--)
        {
            p=upper_bound(b.begin(),b.end(),c[j]);
            b.insert(p,c[j]);
            it=m.find(b);
            if(it!=m.end())
                dp[i]=(dp[i]+1LL*dp[j-1]*it->second)%mod;
        }
    }
    g<<dp[L];
    return 0;
}

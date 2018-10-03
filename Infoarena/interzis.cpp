#include <bits/stdc++.h>
#define MOD 101267
using namespace std;
ifstream f ("interzis.in");
ofstream g ("interzis.out");
int n,lu,i,phi[1010],k,ha[1010],ans,dp[15010],dpp[15010],j;
char st[1010],stt[1010];
int main()
{
    f>>n>>lu;
    f>>st+1;
    strcpy(stt+1,st+1);
    for(i=2; i<=lu; ++i)
    {
        while(k>0&&st[i]!=st[k+1])
            k=phi[k];
        if(st[i]==st[k+1])
            ++k;
        phi[i]=k;
    }
    for(i=2; i<=lu; ++i)
    {
        k=phi[i-1];
        if(stt[i]=='a')
            stt[i]='b';
        else
            stt[i]='a';
        while(k>0&&stt[i]!=st[k+1])
            k=phi[k];
        if(stt[i]==st[k+1])
            ++k;
        ha[i]=k;
        if(stt[i]=='a')
            stt[i]='b';
        else
            stt[i]='a';
    }
    dp[0]=1;
    for(i=2; i<=n+1; ++i)
    {
        for(j=0; j<lu; ++j)
        {
            dpp[j+1]+=dp[j];
            dpp[j+1]%=MOD;
            dpp[ha[j+1]]+=dp[j],dpp[ha[j+1]]%=MOD;
        }
        for(j=0; j<=i; ++j)
            dp[j]=dpp[j],dpp[j]=0;
    }
    for(j=0; j<lu; ++j)
    {
        ans+=dp[j];
        ans%=MOD;
    }
    g<<ans;
    return 0;
}

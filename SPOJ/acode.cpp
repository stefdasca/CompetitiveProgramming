/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
long long dp[5002];
char c[5002];
int main()
{
    while(cin>>(c+1))
    {
        if(c[1]=='0')
            return 0;
        else
        {
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            int L=strlen(c+1);
            for(int i=1;i<=L;++i){
                if(c[i]!='0')
                    dp[i]+=dp[i-1];
                if(i>1 && c[i-1]!='0')
                {
                    int nr=(c[i-1]-'0')*10+c[i]-'0';
                    if(nr<=26)
                        dp[i]+=dp[i-2];
                }
            }
            cout<<dp[L]<<'\n';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
ifstream f("karma.in");
ofstream g("karma.out");
int n,m;
char a[22][22];
int dp[(1<<20)+5];
int nrB[22];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i]+1;
    dp[0]=1;
    for(int i=0;i<(1<<m)-1;++i)
    {
        //g<<dp[i]<<" ";
        if(!dp[i])
            continue;
        memset(nrB,0,sizeof(nrB));
        for(int j=0;j<m;++j)
            if(i&(1<<j))
                for(int k=1;k<=n;++k)
                {
                    if(a[k][j+1]=='(')
                        nrB[k]++;
                    else
                        nrB[k]--;
                }
        for(int j=0;j<m;++j)
            if(!(i&(1<<j)))
            {
                bool gut=1;
                int nr=i+(1<<j);
                for(int k=1;k<=n;++k)
                {
                    if(a[k][j+1]=='('){
                       if(nr==(1<<m)-1){
                           gut=0;
                           break;
                       }
                    }
                    else{
                        if(nrB[k]==0){
                            gut=0;
                            break;
                        }
                        if(nr==(1<<m)-1 && nrB[k]!=1){
                            gut=0;
                            break;
                        }
                    }
                }
                if(gut){
                    dp[nr]=(dp[nr]+dp[i]);
                    if(dp[nr]>=mod)
                        dp[nr]-=mod;
                }
            }
    }
    g<<dp[(1<<m)-1];
    return 0;
}

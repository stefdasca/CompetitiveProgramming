/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define mod 30103
using namespace std;
ifstream f("diviz.in");
ofstream g("diviz.out");
int k,a,b,L;
char c[202];
int dp[3][202][102],last[12];
int first[12][202];
void reset(int t)
{
    for(int i=1;i<=L;++i)
        for(int j=0;j<k;++j)
            dp[t][i][j]=0;
}
int main()
{
    f>>k>>a>>b;
    f>>c+1;
    L=strlen(c+1);
    for(int i=L;i>=1;--i){
        last[c[i]-'0']=i;
        for(int j=0;j<=9;++j)
            first[j][i]=last[j];
    }
    int sol=0;
    for(int i=1;i<=9;++i)
        dp[1][first[i][1]][i%k]=1;
    int t=1;
    for(int j=1;j<=b;++j)
    {
        for(int i=1;i<=L;++i)
        {
            for(int r=0;r<k;++r)
                if(dp[t][i][r])
                    for(int q=0;q<=9;++q)
                    {
                        dp[1-t][first[q][i+1]][(r*10+q)%k]+=dp[t][i][r];
                        dp[1-t][first[q][i+1]][(r*10+q)%k]%=mod;
                    }
            if(j>=a)
                sol=(sol+dp[t][i][0])%mod;
        }
        reset(t);
        t=1-t;
    }
    g<<sol;
    return 0;
}

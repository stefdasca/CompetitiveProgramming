#include<bits/stdc++.h>
#define mod 1000003
using namespace std;
ifstream f("text2.in");
ofstream g("text2.out");
int sz,n,dp[202][202];
int minh[202][202];
int fw[202][202];
char c[202];
int nrv[202];
deque<int>s;
int main()
{
    f>>c+1;
    f>>n;
    sz=strlen(c+1);
    for(int i=1;i<=sz;++i)
    {
        nrv[i]=nrv[i-1];
        if(strchr("aeiouy",c[i]))
            ++nrv[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=sz;++i)
        for(int j=max(0,i-20);j<i;++j)
            if(nrv[i]-nrv[j])
                for(int k=0;k<=min(n-1,j);++k){
                    if(!dp[j][k])
                        continue;
                    dp[i][k+1]=(dp[i][k+1]+dp[j][k])%mod;
                    if(!minh[i][k+1]){
                        minh[i][k+1]=minh[j][k]+(i-j)*(i-j);
                        fw[i][k+1]=j;
                    }
                    else
                        if(minh[j][k]+(i-j)*(i-j)<minh[i][k+1]){
                            minh[i][k+1]=min(minh[i][k+1],minh[j][k]+(i-j)*(i-j));
                            fw[i][k+1]=j;
                        }
                }
    g<<dp[sz][n]<<'\n';
    g<<minh[sz][n]<<'\n';
    s.push_back(sz);
    int nr=sz,l=n;
    while(l)
    {
        nr=fw[nr][l];
        --l;
        s.push_front(nr);
    }
    for(int i=0;i<s.size()-1;++i){
        for(int j=s[i]+1;j<=s[i+1];++j)
            g<<c[j];
        g<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream fi("stalpi2.in");
ofstream fo("stalpi2.out");
int n, e;
int v[52], dp[52][10002];
bool viz[52][10002];
bool check(int maxd)
{
    memset(dp, 0, sizeof(dp));
    memset(viz, 0, sizeof(viz));
    viz[1][0]=1;
    int prevmx=0;
    for(int i=2; i<n; ++i)
    {
        deque<int>poss;
        for(int j=0; j<=min(prevmx+maxd,v[n]); ++j)
        {
            if(!poss.empty() && poss[0]==j-maxd-1)
                poss.pop_front();
            if(j<=prevmx)
            {
                while(!poss.empty() && dp[i-1][j]<=dp[i-1][poss.back()])
                    poss.pop_back();
                poss.push_back(j);
            }
            dp[i][j]=dp[i-1][poss[0]]+abs(v[i]-j), viz[i][j]=1;
        }
        prevmx=min(prevmx+maxd,v[n]);
    }
    for(int j=v[n]-maxd; j<=v[n]; ++j)
    {
        if(!viz[n-1][j])
            continue;
        if(dp[n-1][j]<=e)
            return 1;
    }
    return 0;
}
int main()
{
    fi>>n>>e;
    for(int i=2; i<=n; ++i)
        fi>>v[i];
    int b=0;
    int e=v[n];
    int sol=0;
    while(b<=e)
    {
        int mi=(b+e)/2;
        if(check(mi))
            sol=mi, e=mi-1;
        else
            b=mi+1;
    }
    fo<<sol;
    return 0;
}

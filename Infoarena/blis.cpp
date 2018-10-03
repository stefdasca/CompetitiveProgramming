#include<bits/stdc++.h>
using namespace std;
ifstream fi("blis.in");
ofstream fo("blis.out");
int n,k,i,j,rez,Upd[100005][35],Val[100005][35],Dp[100005];
char S[100005];
int f(int x)
{
    int ind=0;
    for(int i=16; i>=0; i--)
        if(ind+(1<<i)<=rez && Dp[ind+(1<<i)]<x)
            ind=ind+(1<<i);
    return (ind+1);
}

int main()
{
    fi>>k;
    fi>>(S+1);
    n=strlen(S+1);
    rez=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=min(k,n-i+1); j++)
            Val[i][j]=Val[i][j-1]*2+(S[i+j-1]-'0');
        rez=max(rez,Val[i][min(k,n)]);
        Dp[i]=2000000000;
    }
    fo<<rez<<"\n";
    Dp[0]=-1;
    rez=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=min(k,n-i+1); j++)
            Upd[i+j-1][j]=f(Val[i][j]);
        for(j=1; j<=min(k,i); j++)
        {
            rez=max(Upd[i][j],rez);
            Dp[Upd[i][j]]=min(Dp[Upd[i][j]],Val[i-j+1][j]);
        }
    }
    fo<<rez<<"\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
ifstream f("slide.in");
ofstream g("slide.out");
int n,i,st[1<<20],Cost[1<<20],U[1<<20];
long long sol;
char S[1<<20];
int main()
{
    f>>(S+1);
    n=strlen(S+1);
    st[0]=1<<30;
    for(i=1;i<=n;++i)
        if(S[i]==S[i-1]) st[i]=st[i-1]+1;
        else st[i]=1;
    for(i=1;i<=n;++i)
        if(S[i]!='.')
        {
            if(S[i-1]=='.'||i==1) st[i]=1,U[i]=i-1;
            else if(S[i]==S[i-1]) st[i]=st[i-1],U[i]=U[i-1];
            else st[i]=st[i-1]+1,U[i]=U[i-1];
        }
    int curr,ind,runde;
    for(i=n;i;--i)
    {
        Cost[i]=1<<30;
        if(S[i]=='.')
        {
            Cost[i]=0;
            continue;
        }
        if(S[i+1]!=S[i])
        {
            curr=0;
            ind=U[i];
            runde=st[i];
        }
        while(S[ind]!='.'&&ind>0)
        {
            runde+=st[ind];
            ind=U[ind];
        }
        curr+=runde;
        ind--;
        Cost[i]=min(Cost[i],curr);
    }
    reverse(S+1,S+n+1);
    for(i=1;i<=n;++i)
        if(S[i]==S[i-1]) st[i]=st[i-1]+1;
        else st[i]=1;
    for(i=1;i<=n;++i)
        if(S[i]!='.')
        {
            if(S[i-1]=='.'||i==1) st[i]=1,U[i]=i-1;
            else if(S[i]==S[i-1]) st[i]=st[i-1],U[i]=U[i-1];
            else st[i]=st[i-1]+1,U[i]=U[i-1];
        }
    for(i=n;i;--i)
    {
        if(S[i]=='.')
        {
            Cost[n-i+1]=0;
            continue;
        }
        if(S[i+1]!=S[i])
        {
            curr=0;
            ind=U[i];
            runde=st[i];
        }
        while(S[ind]!='.'&&ind>0)
        {
            runde+=st[ind];
            ind=U[ind];
        }
        curr+=runde;
        ind--;
        Cost[n-i+1]=min(Cost[n-i+1],curr);
    }
    for(i=1;i<=n;++i)
        sol+=Cost[i];
    g<<sol;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("cbinput.in");
ofstream g("cbinput.out");
int v[1010],t,n,k,cnt,st,dr;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n>>k;
        memset(v,0,sizeof(v));
        cnt=k,st=1,dr=n;
        while(st<=dr && cnt)
        {
            int mid=(st+dr)/2;
            v[mid]=cnt--;
            dr=mid-1;
        }
        v[0]=1;
        for(int i=1;i<=n;i++)
            if(v[i]==0)
                v[i]=v[i-1];
        if(cnt>0)
        {
            for(int i=1;i<=n;i++)
                v[i]-=cnt;
            for(int i=n;i>=1 && v[i]!=k;i--)
                v[i]=k--;
        }
        for(int i=1;i<=n;i++)
            g<<v[i]<<" ";
        g<<'\n';
    }
    return 0;
}

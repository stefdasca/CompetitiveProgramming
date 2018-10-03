#include<bits/stdc++.h>
using namespace std;
ifstream f("copaci4.in");
ofstream g("copaci4.out");
int n,v[200002],m;
int s[200002],d[200002];
char c;
int nr;
void build()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=2;i<=n;++i)
        if(v[i]<=v[i-1])
            s[i]=i-1;
        else{
            s[i]=s[i-1];
            while(v[s[i]]<v[i] && s[i])
                s[i]=s[s[i]];
        }
    d[n]=n+1;
    for(int i=n-1;i>=1;--i)
        if(v[i]<=v[i+1])
            d[i]=i+1;
        else{
            d[i]=d[i+1];
            while(v[d[i]]<v[i] && d[i]!=n+1)
                d[i]=d[d[i]];
        }
    d[n+1]=n+2;
}
int main()
{
    build();
    int sol=0;
    for(int i=1;i<=n;++i)
    {
        int p=s[i];
        int q=d[i];
        if(p==0 || q==n+1);
        else
            if(s[i] <= p && d[i] >= q && d[p] >= q && s[q] <= p)
                   sol ++;

    }
    g<<sol;
    return 0;
}

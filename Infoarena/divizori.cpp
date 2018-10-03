#include<bits/stdc++.h>
using namespace std;
ifstream f("divizori.in");
ofstream g("divizori.out");
int D,a,b,n,P,d,i,k,e[1000001];
int main()
{   f>>n;
    e[1]=1;
    k=1;
    for(d=2;d*d<=n;d++)
        if(n%d==0){
            int k1=k+1;
            for(i=k;i>=1;i--)
                e[++k]=d*e[i];
            n=n/d;
            while(n%d==0){
                int p=k1;
                k1=k+1;
                for(i=k;i>=p;i--)
                    e[++k]=d*e[i];
                n=n/d;
            }
        }
    if(n!=1)
        for(i=k;i>=1;i--)
            e[++k]=n*e[i];
    g<<k<<'\n';
    for(i=1;i<=k;i++)
        g<<e[i]<<' ';
    return 0;
}

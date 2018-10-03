#include<bits/stdc++.h>
using namespace std;
ifstream f("superstring.in");
ofstream g("superstring.out");
int n,k,m,q,t,pi[1000002],lmax;
char N[1000002],M[1000002];
int smin;
int main()
{
    f>>t;
    for(;t;--t){
        f>>(N+1);
        f>>(M+1);
        n=strlen(N+1);
        m=strlen(M+1);
        k=0;
        pi[1]=0;
        for(int i=2;i<=n;++i){
            while(k && (N[k + 1] != N[i]))
                k=pi[k];
            if(N[k + 1]==N[i])
                ++k;
            pi[i]=k;
        }
        q=0;
        for(int i=1;i<=m;++i){
            while(q  && (N[q + 1] != M[i]))
                q=pi[q];
            if(N[q + 1] ==M[i])
                ++q;
            if(q==n) break;
        }
        smin=n+m-q;
        k=0;
        pi[1]=0;
        for(int i=2;i<=m;++i){
            while(k && (M[k + 1] != M[i]))
                k=pi[k];
            if(M[k + 1]==M[i])
                ++k;
            pi[i]=k;
        }
        q=0;
        for(int i=1;i<=n;++i){
            while(q  && (M[q + 1] != N[i]))
                q=pi[q];
            if(M[q + 1] ==N[i])
                ++q;
            if(q==m) break;
        }
        smin=min(smin,n+m-q);
        g<<smin<<'\n';
    }
    return 0;
}

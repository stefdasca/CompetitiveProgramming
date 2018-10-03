#include<bits/stdc++.h>
using namespace std;
ifstream f("rk.in");
ofstream g("rk.out");
int N;
long long val;
long long R,K;
int Q;
long long V[200005];
int main()
{
    f>>N;
    for(int i=1;i<=N;i++)
    {
        f>>val;
        long long nr=0;
        for(int j=0;j<32;j++)
        {
            nr=nr*2+(val&1);
            val>>=1;
        }
        V[i]=nr;
    }
    sort(V+1,V+1+N);
    f>>Q;
    for(int i=1;i<=Q;i++)
    {
        f>>R>>K;
        long long nr=0;
        for(int j=0;j<32;j++)
        {
            nr=nr*2+(R&1);
            R>>=1;
        }
        int st,dr;
        st=lower_bound(V+1,V+1+N,nr)-V;
        dr=upper_bound(V+1,V+1+N,nr+(1LL<<(32-K))-1)-V;
        g<<dr-st<<'\n';
    }
    return 0;
}

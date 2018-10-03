#include<bits/stdc++.h>
using namespace std;
const int N=100005, MOD=100003;
ifstream fin("spion.in");
ofstream fout("spion.out");
int fact[N],p;
char a[N];
int pw(int x, int y)
{
    int ret=1;
    for(;y;y>>=1)
    {
        if(y&1)
            ret=(1LL*ret*x)%MOD;
        x=(1LL*x*x)%MOD;
    }
    return ret;
}
void init(int n)
{
    int i;
    fact[1]=1;
    for(i=2;i<=n;i++) fact[i]=(1LL*fact[i-1]*i)%MOD;
}
int comb(int n, int k)
{
    if(!n||!k) return 1;
    return 1LL*fact[n]*pw(1LL*fact[k]*fact[n-k]%MOD, MOD-2)%MOD;
}
int main()
{
    int i, n, x=0, y=0;
    fin>>p;fin.get();
    fin.getline(a,N);
    n=strlen(a);
    init(n);
    for(i=0;i<n;i++)
    {
        if(a[i]=='E') y++;
        x++;
    }
    if(p==1)
    fout<<y+1<<"\n";
    else fout<<comb(x, y)<<"\n";
}

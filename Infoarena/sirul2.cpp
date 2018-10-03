#include <bits/stdc++.h>
using namespace std;
ifstream f("sirul2.in");
ofstream g("sirul2.out");
int P,N,X;
const int MOD = 20173333;
inline int InversModular(int x)
{
	int put=MOD-2,rez=1;
	while(put)
	{
		if(put%2)
			rez=(1LL*rez*x)%MOD;
		x=(1LL*x*x)%MOD;
		put/=2;
	}
	return rez;
}
//calc comb(n,k)=n! * (inv k!) * inv (n-k)!)
 inline int fact(int p)
{
 int sol=1;
 for(int i=2;i<=p;++i)
   sol=(1ll*sol*i)%MOD;
 return sol;
}
int comb(int n, int k)
{
 int w=(1ll*fact(n)*InversModular(fact(k)))%MOD;
 w=(1ll*w*InversModular(fact(n-k)))%MOD;
 return w;
}


int p1()
{
    return comb(N-1,X-1);
}

int p2()
{
    vector <int> a;
    for(int i=0;i<=N;++i) a.push_back(0);
    int S=1;
    a[0]=1;
    for(int i=1; i<=N; ++i)
    {
        a[i]=S;
        if(i>=X)
            S=((S+a[i]-a[i-X]+MOD))%MOD;
        else
            S=(S+a[i])%MOD;
    }
    return a[N];
}

int main()
{
    f>>P>>N>>X;
    if(P==1)
            g<<p1()<<"\n";
    else
            g<<p2()<<"\n";
    return 0;
}

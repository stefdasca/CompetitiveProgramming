/// 4 burned, 3 left
#include<bits/stdc++.h>
using namespace std;
ifstream f("popularitate.in");
ofstream g("popularitate.out");
int n,k,gr,poz,nr;
int maxp,who;
struct fact
{
    int nr,pw;
};
fact v[35];
int vv[35];
int main()
{
    f>>k;
    for(int i=2;i*i<=k;++i)
        if(k%i==0)
        {
            v[++poz].nr=i;
            while(k%i==0)
                k/=i,++v[poz].pw;
        }
    if(k>1)
        v[++poz].nr=k,v[poz].pw=1;
    f>>gr;
    for(int i=1;i<=gr;++i)
    {
        memset(vv,0,sizeof(vv));
        f>>n;
        for(int j=1;j<=n;++j)
        {
            f>>nr;
            for(int q=1;q<=poz;++q)
                while(nr%v[q].nr==0)
                    nr/=v[q].nr,++vv[q];
        }
        int p=vv[1]/v[1].pw;
        for(int j=2;j<=poz;++j)
            p=min(p,vv[j]/v[j].pw);
        if(p>maxp)
            maxp=p,who=i;
    }
    g<<maxp<<" "<<who;
    return 0;
}

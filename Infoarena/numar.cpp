#include<bits/stdc++.h>
using namespace std;
ifstream f("numar.in");
ofstream g("numar.out");
long long n,nrs;
struct sol
{
    long long b,l;
};
sol v[100002];
bool test(sol a, sol b)
{
    return a.b>b.b;
}
int main()
{
    f>>n;
    for(long long i=2;i*(i-1)<=n*2;++i)
    {
        if(i%2==1)
            if(n%i==0)
            {
                ++nrs;
                v[nrs].b=n/i-i/2;
                v[nrs].l=i;
                ++nrs;
                v[nrs].b=-v[nrs-1].b+1;
                if(v[nrs].b>0)
                    v[nrs].l=v[nrs-1].l+v[nrs].b*2+1;
                else
                    v[nrs].l=v[nrs-1].l-v[nrs].b*2+1;

            }
        if(i%2==0)
            if(n%i==i/2)
            {
                ++nrs;
                v[nrs].b=n/i-(i/2-1);
                v[nrs].l=i;
                ++nrs;
                v[nrs].b=-v[nrs-1].b+1;
                if(v[nrs].b>0)
                    v[nrs].l=v[nrs-1].l+v[nrs].b*2+1;
                else
                    v[nrs].l=v[nrs-1].l-v[nrs].b*2+1;
            }
    }
    sort(v+1,v+nrs+1,test);
    for(int i=1;i<=nrs;++i)
        g<<v[i].b<<" "<<v[i].l<<'\n';
    g<<-n+1<<" "<<n*2<<'\n';
}

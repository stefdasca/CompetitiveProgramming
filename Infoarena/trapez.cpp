/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("trapez.in");
ofstream g("trapez.out");
int n;
struct punct
{
    long long x,y;
};
punct v[1002];
double ar[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].x>>v[i].y;
    int nr=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
        {
            ++nr;
            ar[nr]=(v[j].y-v[i].y+0.00)/(v[j].x-v[i].x+0.00);
        }
    sort(ar+1,ar+nr+1);
    long long neq=1;
    long long sol=0;
    for(int i=2;i<=nr;++i)
    {
        if(ar[i]==ar[i-neq])
            ++neq;
        else
        {
            sol=sol+neq*(neq-1)/2;
            neq=1;
        }
    }
    sol=sol+neq*(neq-1)/2;
    g<<sol;
    return 0;
}

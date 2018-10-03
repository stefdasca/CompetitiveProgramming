/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define INF 1e18
using namespace std;
ifstream f("z.in");
ofstream g("z.out");
long long n,k;
long long x,y;
long long divimp(long long lst,long long cst,long long ldr,long long cdr,long long stn,long long drn)
{
   // g<<lst<<" "<<cst<<" "<<ldr<<" "<<cdr<<" "<<stn<<" "<<drn<<'\n';
    if(stn==drn)
        return stn;
    if(x<=(lst+ldr)/2)
        if(y<=(cst+cdr)/2)
            return divimp(lst,cst,(lst+ldr)/2,(cst+cdr)/2,stn,stn+(drn-stn+1)/4);
        else
            return divimp(lst,(cst+cdr)/2+1,(lst+ldr)/2,cdr,stn+(drn-stn+1)/4,stn+(drn-stn+1)/2);
    else
        if(y<=(cst+cdr)/2)
            return divimp((lst+ldr)/2+1,cst,ldr,(cst+cdr)/2,stn+(drn-stn+1)/2,stn+3*(drn-stn+1)/4);
        else
            return divimp((lst+ldr)/2+1,(cst+cdr)/2+1,ldr,cdr,stn+3*(drn-stn+1)/4,drn);
}
int main()
{
    f>>n>>k;
    for(;k;--k)
    {
        f>>x>>y;
        g<<divimp(1,1,(1<<n),(1<<n),1,1LL*(1LL<<n)*(1LL<<n))<<'\n';
    }
    return 0;
}

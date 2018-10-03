/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("gard5.in");
ofstream g("gard5.out");
int sol;
int n,v[102],max1,poz,sum,gut[102];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    v[n+1]=n+1;
    for(int i=1;i<=n;++i)
        if(v[i]>max1)
        {
            max1=v[i];
            sort(v+poz+1,v+i);
            if(i-poz>2)
                ++sol;
            poz=i;
            gut[i]=1;
        }
    if(n+1-poz>2)
        ++sol;
    sort(v+poz+1,v+n+1);
    for(int i=1;i<=n;++i)
        if(!gut[i])
            sum=sum+abs(v[i]-v[i-1])+abs(v[i]-v[i+1]);
    g<<sum<<" "<<(1LL<<sol)<<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("criza.in");
ofstream g("criza.out");
int n,max1;
struct s
{
    long long p,am;
};
s v[100002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].p>>v[i].am;
    int b=1;
    int e=1e9;
    while(b<=e)
    {
        int K=(b+e)/2;
        long long carry=0, x;
        for (int i=1; i<n; i++)
          {
           x=v[i].am+carry;
           if (x<K)
              carry=x-K-(v[i+1].p-v[i].p);
              else // if( x >= K )
              {
               carry = x-K-(v[i+1].p-v[i].p);
               if (carry<0) carry = 0;
              }
           }
        if(v[n].am+carry>=K)
            b=K+1;
        else
            e=K-1;
    }
    int K=b;
    long long carry=0, x;
    for (int i=1; i<n; i++)
          {
           x=v[i].am+carry;
           if (x<K)
              carry=x-K-(v[i+1].p-v[i].p);
              else // if( x >= K )
              {
               carry = x-K-(v[i+1].p-v[i].p);
               if (carry<0) carry = 0;
              }
           }
    if(v[n].am+carry>=K)
        g<<b;
    else
        g<<e;
    return 0;
}

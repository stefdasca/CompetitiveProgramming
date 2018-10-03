#include<bits/stdc++.h>
using namespace std;
ifstream f("echipe2.in");
ofstream g("echipe2.out");
int n;
int max1,min1=1e9+1;
int max2,min2=1e9+1;
int a,b;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>a;
        f>>b;
        if(a>=b)
        {
            max1=max(max1,b);
            max2=max(max2,a);
            min1=min(min1,b);
            min2=min(min2,a);
        }
        else
        {
            max1=max(max1,a);
            max2=max(max2,b);
            min1=min(min1,a);
            min2=min(min2,b);
        }
    }
    g<<max(max1-min1,max2-min2);
    return 0;
}

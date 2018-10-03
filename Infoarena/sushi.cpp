#include<bits/stdc++.h>
using namespace std;
ifstream f("sushi.in");
ofstream g("sushi.out");
int n,v[1000002],max1,p1;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>v[i];
        if(v[i]>max1)
            max1=v[i],p1=i;
    }
    g<<p1<<" ";
    while(v[p1+1]==v[p1])
        ++p1;
    g<<p1<<" ";
    g<<2*v[p1];
}

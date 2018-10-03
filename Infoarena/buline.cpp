#include<bits/stdc++.h>
using namespace std;
ifstream f("buline.in");
ofstream g("buline.out");
int i,n,maxi,l,poz,x,s[400001],v[400001];
deque<int>d;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i]>>x;
        if(x==0)
            v[i]*=-1;
    }
    for(i=1;i<=n;i++)
        v[i+n]=v[i];
    for(i=1;i<=2*n;i++)
        s[i]=s[i-1]+v[i];
    d.push_back(1);
    int sz=0;
    for(i=2;i<=2*n;i++)
    {
        if(i-d[0]>n)
            d.pop_front(),--sz;
        if(s[i]-s[d[0]]>maxi)
        {
            maxi=s[i]-s[d.front()];
            poz=d.front()+1;
            l=i-d.front();
        }
        while(!d.empty() && s[i]<s[d.back()])
            d.pop_back(),--sz;
        d.push_back(i),++sz;
    }
    g<<maxi<<' '<<poz<<' '<<l;
    return 0;
}

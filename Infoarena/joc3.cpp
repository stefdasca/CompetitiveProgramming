#include<bits/stdc++.h>
using namespace std;
ifstream f("joc3.in");
ofstream g("joc3.out");
int n,v[100002];
int xs=0,p,q;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1+n%2;i<n;i+=2)
        xs^=v[i];
    for(int i=n-1;i;--i)
    {
        int x;
        if((n-i)&1)
            x=v[i]-(xs^v[i]);
        else
            x=(xs^v[i+1])-v[i+1];
        if(x>0 && x<=v[i])
            p=i,q=x;
    }
    if(p==0)
        g<<-1;
    else
        g<<p<<" "<<q;
}

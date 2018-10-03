#include<iostream>
using namespace std;
long long a,b,p,q;
long long rp(long long b,long long e)
{
    if(e==0)
        return 1;
    else
        if(e==1)
            return b;
        else
            if(e%2==1)
                return (rp(b,e-1)%q*b%q)%q;
            else
                return (rp(b,e/2)%q*rp(b,e/2)%q)%q;
}
int main()
{
    cin>>a>>b>>p;
    q=1;
    for(int i=1;i<=p;++i)
        q*=10;
    cout<<rp(a,b);
}

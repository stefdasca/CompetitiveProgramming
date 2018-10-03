#include<bits/stdc++.h>
using namespace std;
ifstream f("simpla.in");
ofstream g("simpla.out");
int hmp=500,hmi=500;
int a,b,sol;
int main()
{
    f>>a>>b;
    if(b-a<5000)
    {
        for(int i=a;i<=b;++i)
        {
            int nr=i;
            int s=0;
            while(nr)
                s+=nr%10,nr/=10;
            if(s%2==0)
                ++sol;
        }
        g<<sol<<'\n';
    }
    else
    {
        while(b%1000!=999)
        {
            int nr=b;
            int s=0;
            while(nr)
                s+=nr%10,nr/=10;
            if(s%2==0)
                ++sol;
            --b;
        }
        while(a%1000!=0)
        {
            int nr=a;
            int s=0;
            while(nr)
                s+=nr%10,nr/=10;
            if(s%2==0)
                ++sol;
            ++a;
        }
        g<<sol+500*(b-a+1)/1000;
    }
    return 0;
}

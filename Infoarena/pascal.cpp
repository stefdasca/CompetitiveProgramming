#include<bits/stdc++.h>
using namespace std;
ifstream f("pascal.in");
ofstream g("pascal.out");
int n,d;
int v1[5000002],v2[5000002];
int main()
{
    f>>n>>d;
    if(d!=4 && d!=6)
    {
        for(int i=d;i<=n;i+=d)
        {
            int z=i;
            while(z%d==0)
            {
                ++v1[i];
                z/=d;
            }
        }
        for(int i=1;i<=n;++i)
            v1[i]+=v1[i-1];
        int sol=0;
        int max1=n/2+n%2;
        for(int i=0;i<max1;++i)
            if(v1[n]-v1[i]-v1[n-i])
                sol+=2;
        if(n%2==0)
            if(v1[n]-v1[n/2]*2)
                ++sol;
        g<<sol;
    }
    else
        if(d==4)
        {
            for(int i=2;i<=n;i+=2)
            {
                int z=i;
                while(z%2==0)
                {
                    ++v1[i];
                    z/=2;
                }
            }
            for(int i=1;i<=n;++i)
                v1[i]+=v1[i-1];
            int sol=0;
            int max1=n/2+n%2;
            for(int i=0;i<max1;++i)
            {
                int nr=v1[n]-v1[i]-v1[n-i];
                if(nr>=2)
                    sol+=2;
            }
            int nr=v1[n]-2*v1[n/2];
            if(n%2==0)
                if(nr>=2)
                    ++sol;
            g<<sol;
        }
        else
        {
            for(int i=2;i<=n;i+=2)
            {
                int z=i;
                while(z%2==0)
                {
                    ++v1[i];
                    z/=2;
                }
            }
            for(int i=3;i<=n;i+=3)
            {
                int z=i;
                while(z%3==0)
                {
                    ++v2[i];
                    z/=3;
                }
             }
            for(int i=1;i<=n;++i)
                v1[i]+=v1[i-1];
            for(int i=1;i<=n;++i)
                v2[i]+=v2[i-1];
            int sol=0;
            int max1=n/2+n%2;
            for(int i=0;i<max1;++i)
            {
                int nr=v1[n]-v1[i]-v1[n-i];
                int nr1=v2[n]-v2[i]-v2[n-i];
                if(nr>0 && nr1>0)
                    sol+=2;
            }
            int nr=v1[n]-2*v1[n/2];
            int nr1=v2[n]-2*v2[n/2];
            if(n%2==0)
                if(nr>0 && nr1>0)
                    ++sol;
            g<<sol;
        }
    return 0;
}

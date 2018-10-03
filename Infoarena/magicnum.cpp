#include<bits/stdc++.h>
using namespace std;
ifstream f("magicnum.in");
ofstream g("magicnum.out");
int a,b;
bool p[1000002];
int nrd[1000002];
void ciur()
{
    nrd[2]=2;
    for(int i=4;i<=1000000;i+=2)
    {
        p[i]=1;
        int q=0;
        int nr=i;
        while(nr%2==0)
            nr/=2,++q;
        nrd[i]*=(q+1);
    }
    for(int i=3;i<=1000000;i+=2)
        if(p[i]==0)
        {
            nrd[i]++;
            for(int j=i+i;j<=1000000;j+=i)
            {
                p[j]=1;
                int q=0;
                int nr=j;
                while(nr%i==0)
                    nr/=i,++q;
                nrd[j]*=(q+1);
            }
        }
}
int main()
{
    f>>a>>b;
    for(int i=1;i<=1000000;++i)
        nrd[i]=1;
    ciur();
    int sol=0;
    for(int i=a;i<=b;++i)
        if(i%nrd[i]==0)
            ++sol;
    g<<sol;
    return 0;
}

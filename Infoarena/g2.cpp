#include<bits/stdc++.h>
using namespace std;
ifstream f("g2.in");
ofstream g("g2.out");
int n;
int fr[12];
int main()
{
    f>>n;
    if(n==1)
        g<<1;
    else
    {
        for(int i=9;i>=2;--i)
            while(n%i==0)
                n/=i,++fr[i];
        if(n>1)
            g<<0;
        else
            for(int i=2;i<=9;++i)
                for(int j=1;j<=fr[i];++j)
                    g<<i;
    }
    return 0;
}

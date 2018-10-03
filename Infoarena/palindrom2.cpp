#include<bits/stdc++.h>
using namespace std;
ifstream f("palindrom2.in");
ofstream g("palindrom2.out");
char c1[3002];
int nrmax,pmax;
int main()
{
    f>>c1;
    int l=strlen(c1);
    for(int i=l/2;i<l;++i)
    {
        int z=1;
        while(c1[i-z]==c1[i+z])
        {
            ++z;
            if(z>i || i+z==l)
            {
                if(z>nrmax)
                    nrmax=z,pmax=i;
                break;
            }
        }
    }
    for(int i=l/2;i<l;++i)
    {
        int z=1;
        while(c1[i-z+1]==c1[i+z])
        {
            ++z;
            if(z>i || i+z==l)
            {
                if(z-1>nrmax)
                    nrmax=z-1,pmax=i;
                break;
            }
        }
    }
  //  g<<nrmax<<" "<<pmax<<'\n';
    int r=l;
    if(nrmax==0)
        for(int i=l-2;i>=0;--i)
            c1[r++]=c1[i];
    else{
        r=pmax-nrmax;
        for(int i=l;r>=0;++i,--r)
            c1[i]=c1[r];
    }
    g<<c1;
    return 0;
}

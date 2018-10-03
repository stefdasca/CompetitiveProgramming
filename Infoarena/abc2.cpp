#define ross 90907
#include<bits/stdc++.h>
using namespace std;
ifstream f("abc2.in");
ofstream g("abc2.out");
unsigned int nrcur;
char c[10000003];
int len,ln,sol;
int R;
vector<unsigned int>rest[ross];
char q[25];
inline void init()
{
    f>>c;
    R=strlen(c);
    while(f>>q)
    {
        unsigned int p3=1;
        nrcur=0;
        if(ln==0)
            ln=strlen(q);
        for(int j=ln-1;j>=0;--j)
            nrcur+=p3*(q[j]-'a'),p3*=3;
        rest[nrcur%ross].push_back(nrcur);
    }
}
inline void fin()
{
    unsigned int p3=1;
    nrcur=0;
    for(int k=ln-1;k>=0;--k)
        nrcur+=p3*(c[k]-'a'),p3*=3;
    p3/=3;
    for(int j=0;j<=R-ln;++j)
    {
        if(j>0)
        {
            nrcur=nrcur-p3*(c[j-1]-'a');
            nrcur=nrcur*3;
            nrcur=nrcur+1ll*(c[j+ln-1]-'a');
        }
        int iozr=nrcur%ross;
        for(int i=0;i<rest[iozr].size();++i)
            if(rest[iozr][i]==nrcur)
            {
                ++sol;
                break;
            }
    }
    g<<sol;
}
int main()
{
    init();
    fin();
    return 0;
}

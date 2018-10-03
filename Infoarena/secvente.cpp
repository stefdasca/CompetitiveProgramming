#include<bits/stdc++.h>
using namespace std;
ifstream f("secvente.in");
ofstream g("secvente.out");
int q[5];
int ls,nr,s;
int main()
{
    for(int i=1;i<=3;++i)
    {
        f>>ls;
        q[0]=q[1]=q[2]=0;
        s=0;
        for(int j=1;j<=ls;++j)
            f>>nr,q[nr%3]++,s+=nr%3;
        if(s%3==0)
            g<<ls<<'\n';
        if(s%3==1)
            if(q[1])
                g<<ls-1<<'\n';
            else
                if(q[2]>=2)
                    g<<ls-2<<'\n';
        if(s%3==2)
            if(q[2])
                g<<ls-1<<'\n';
            else
                if(q[1]>=2)
                    g<<ls-2<<'\n';
    }
    return 0;
}

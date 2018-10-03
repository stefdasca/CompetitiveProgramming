#include<bits/stdc++.h>
using namespace std;
ifstream f("mcript.in");
ofstream g("mcript.out");
int n,nr,bb,t,nc,cpy;
char c[12];
int v[1000002];
inline bool bin_search(int n)
{
    int b=1;
    int e=nr;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(v[m]==n)
            return 1;
        if(v[m]>n)
            e=m-1;
        else
            b=m+1;
    }
    return 0;
}
int main()
{
    f>>n;
    f>>c+1;
    f>>nr;
    for(int i=1;i<=nr;++i)
        f>>v[i];
    sort(v+1,v+nr+1);
    f>>t;
    for(;t;--t)
    {
        bool Hmmm=1;
        f>>nc;
        for(;nc;--nc)
        {
            f>>bb;
            if(!Hmmm)
                continue;
            cpy=0;
            int ex=1;
            while(bb)
            {
                cpy+=ex*(c[bb%10]-'0');
                ex*=10;
                bb/=10;
            }
            if(!bin_search(cpy))
                Hmmm=0;
        }
        g<<Hmmm<<'\n';
    }
    return 0;
}

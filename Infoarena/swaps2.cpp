#include<bits/stdc++.h>
using namespace std;
ifstream f("swaps2.in");
ofstream g("swaps2.out");
int n,nrm,nr0,nr1;
char c[1002];
struct s
{
    int ex,ds;
};
s v[1002];
int main()
{
    f>>n;
    f>>c+1;
    for(int i=1;i<=n;++i)
        if(c[i]=='0')
            ++nr0;
        else
            ++nr1;
    int p1=1;
    int p2=nr0+1;
    for(;p1<=nr0;++p1)
        if(c[p1]=='1')
        {
            while(c[p2]=='1')
                ++p2;
            ++nrm;
            v[nrm].ds=p1;
            v[nrm].ex=p2;
            ++p2;
        }
    g<<nrm<<'\n';
    for(int i=1;i<=nrm;++i)
        g<<v[i].ds<<" "<<v[i].ex<<'\n';
    return 0;
}

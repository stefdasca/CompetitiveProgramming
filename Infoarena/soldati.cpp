#include<bits/stdc++.h>
using namespace std;
ifstream f("soldati.in");
ofstream g("soldati.out");
int n;
char c1[100002];
bool v1[100002];
int ls;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>c1;
        ls=strlen(c1)-1;
        int c0=0,nr1=0;
        for(int j=0;j<=ls;++j)
            if(c1[j]=='>')
                v1[j]=1;
            else
                v1[j]=0;
        while(v1[ls]==1)
            --ls;
        int dmax=0,dest=ls,nr0=0;
        for(int j=ls;j>=0;--j){
            if(v1[j]==1)
                {
                    dmax=max(dmax,c0+dest-j);
                    --dest;
                    ++c0;
                }
            else
                c0--,nr0++;
            c0=max(c0,0);
        }
        g<<dmax<<'\n';
    }
    return 0;
}

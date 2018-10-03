#include<bits/stdc++.h>
using namespace std;
ifstream f("joc5.in");
ofstream g("joc5.out");
int n,mat[102][102],minl[102],minc[102];
int main()
{
    while(f>>n)
    {
        if(n==0)
            return 0;
        for(int i=1;i<=n;++i)
            minl[i]=10000000;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                f>>mat[i][j];
                minl[i]=min(minl[i],mat[i][j]);
            }
        int xA=0;
        for(int i=1;i<=n;++i)
            xA^=minl[i];
        if(xA==0)
            g<<2<<'\n';
        else
            g<<1<<'\n';
    }
    return 0;
}

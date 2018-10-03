#include<bits/stdc++.h>
using namespace std;
ifstream f("piese.in");
ofstream g("piese.out");
int l,c,v[12];
int nrm;
int a[501][501];
int main()
{
    f>>l>>c;
    for(int i=256;i>=1;i>>=1)
        if(l>=i && c>=i)
            for(int j=1;j<=l;++j)
                for(int k=1;k<=c;++k)
                    if(a[j][k]==0)
                        if(j+i-1<=l && k+i-1<=c)
                        {
                            ++nrm;
                            for(int x=j;x<j+i;++x)
                                for(int y=k;y<k+i;++y)
                                    a[x][y]=nrm;
                        }
    g<<nrm<<'\n';
    for(int i=1;i<=l;g<<'\n',++i)
        for(int j=1;j<=c;++j)
            g<<a[i][j]<<" ";
    return 0;
}

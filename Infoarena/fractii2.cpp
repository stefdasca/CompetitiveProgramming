#define MOD 100003
#include<bits/stdc++.h>
using namespace std;
ifstream f("fractii2.in");
ofstream g("fractii2.out");
int c,n,sol[2010][2010],from;
int main()
{
    f>>c;
    f>>n;
    if(c==1){
        int i=1;
        for(;i<n;++i)
            g<<i<<" ";
        g<<i-1;
    }
    else
    {
        sol[2][1]=1;
        for(int i=3;i<=n;i++)
            for(int j=1;j<=i/2;j++)
            {
                from=i-j;
                int left=(j+1)/2-1;
                int right=(i-j)/2;
                sol[i][j]=(MOD+sol[i][j-1]+sol[i-j][right]-sol[i-j][left])%MOD;
            }
        g<<sol[n][n/2]<<'\n';
    }
    return 0;
}

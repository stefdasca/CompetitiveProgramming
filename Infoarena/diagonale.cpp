/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("diagonale.in");
ofstream g("diagonale.out");
long long n,a[1002][1002];
long long sum,summax=-1e18;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>a[i][j];
    for(int i=1,j=n;i<=n;)
    {
        sum=0;
        for(int q=i,p=j;q<=n && p<=n;++q,++p)
            sum+=a[q][p];
        if(j>1)
            --j;
        else
            ++i;
        summax=max(summax,sum);
    }
    for(int i=n,j=n;j>=1;)
    {
        sum=0;
        for(int q=i,p=j;q<=n && p;++q,--p)
            sum+=a[q][p];
        if(i>1)
            --i;
        else
            --j;
        summax=max(summax,sum);
    }
    g<<summax;
    return 0;
}

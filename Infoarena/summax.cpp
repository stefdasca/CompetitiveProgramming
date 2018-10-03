/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define nmax 2005
using namespace std;
ifstream f("summax.in");
ofstream g("summax.out");
unsigned cer,n,st,dr,*a[nmax],*cnt[nmax],i,j;
void parcurge(int k)
{
    int j=1;
    for(int i=1;i<=n;++i)
    {
        g<<j<<" ";
        if(i==n)
            break;
        if (a[i+1][j]==a[i+1][j+1])
        {
            if (k>cnt[i+1][j])
                k-=cnt[i+1][j],j++;
        }
        else
            if(a[i+1][j+1]>a[i+1][j])
                j++;
    }
    g<<'\n';
}
int main() {
    f>>cer>>n>>st>>dr;
    for(i=1;i<=n;i++)
    {
        a[i]=new unsigned[i+1];
        cnt[i]=new unsigned[i+1];
        for (j=1;j<=i;j++)
        {
            f>>a[i][j];
            if(i==n)
                cnt[i][j]=1;
        }
    }
    for (i = n-1; i >= 1; i--)
        for (j = 1; j <= i; j++)
        {
            if (a[i+1][j] > a[i+1][j+1])
            {
                a[i][j] += a[i+1][j];
                cnt[i][j] = cnt[i+1][j];
            }
            else
                if (a[i+1][j] < a[i+1][j+1])
                {
                    a[i][j] += a[i+1][j+1];
                    cnt[i][j] = cnt[i+1][j+1];
                }
            else
            {
                a[i][j] += a[i+1][j];
                cnt[i][j] = cnt[i+1][j] + cnt[i+1][j+1];
            }
            if(cnt[i][j] > 2e9)
                cnt[i][j] = 2e9+1;
        }
    if (cer == 1)
        g<<cnt[1][1];
    else
        for (i = st; i <= dr; i++)
            parcurge(i);
    return 0;
}

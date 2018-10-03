#include<bits/stdc++.h>
using namespace std;
ifstream f("petrecere.in");
ofstream g("petrecere.out");
int n;
int v1[3002];
int la=1,lb=1;
int v2[3002];
int v3[3002];
int main()
{
    f>>n;
    if(n<=2)
        g<<n;
    else
    {
        v1[1]=1;
        v2[1]=2;
        for(int i=3;i<=n;++i)
        {
            for(int j=1;j<=lb;++j)
                v3[j]=v2[j];
            for(int j=1;j<=la;++j)
                v3[j]+=(i-1)*v1[j];
            int lc=lb;
            for(int j=1;j<=lc;++j)
                if(v3[j]>9)
                {
                    v3[j+1]+=v3[j]/10;
                    v3[j]%=10;
                    if(j==lc)
                        ++lc;
                }
            for(int j=1;j<=lb;++j)
                v1[j]=v2[j];
            la=lb;
            for(int j=1;j<=lc;++j)
                v2[j]=v3[j];
            lb=lc;
            memset(v3,0,sizeof(v3));
        }
        for(int i=lb;i>=1;--i)
            g<<v2[i];
    }
    return 0;
}

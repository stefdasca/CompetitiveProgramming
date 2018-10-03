#include<bits/stdc++.h>
using namespace std;
ifstream fin("stiva3.in");
ofstream fout("stiva3.out");
int n,a[50003],i,j,st[50003],k,max1,min1,p,b[50003],maxst,maxdr,start;
bool ok1;
int main()
{
    fin>>n;
    for (i=1;i<=5;++i)
    {
        for (j=1;j<=50000;++j)
            b[j]=0;
        max1=0;min1=2000000000;
        for(j=1;j<=n;++j)
        {
            fin>>a[j];
            if (a[j]>max1)
                max1=a[j];
            if (a[j]<min1)
                min1=a[j];
        }
        maxst=0;
        maxdr=0;
        ok1=false;
        for (j=1;j<=n;++j)
        {
            a[j]=a[j]-min1+1;
            b[a[j]]=1;
            if (a[j]==1)
                ok1=true;
            if (not ok1)
                if (a[j]>maxst)
                    maxst=a[j];
        }
        max1=max1-min1+1;
        start=1;
        for (j=maxst;j>1;j--)
            if (b[j]==0)
            {
                start=(start+49999)%50000;
                a[start]=j;
            }
        p=n;
        for (j=max1;j>=maxst;--j)
            if (b[j]==0)
                a[++p]=j;
        k=0;p=start;
        for(j=1;j<=max1;++j)
        {
            st[++k]=j;
            while(k>0 and st[k]==a[p])
            {
                p=(p+1)%50000;
                --k;
            }
        }
        if (k==0) fout<<1<<"\n";
        else fout<<0<<"\n";
    }
    return 0;
}

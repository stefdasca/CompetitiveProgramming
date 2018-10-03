#include <iostream>
#include <fstream>
using namespace std;
ifstream in("magic2.in");
ofstream out("magic2.out");
int a[102][102],sl[102][102],sc[102][102],n,sem,fr[10001],maxx,maxi,i1,i2,j1,j2,aux;
int main()
{in>>n;
for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)in>>a[i][j];
for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)sl[i][j]=sl[i][j-1]+a[i][j];
for(int j=1;j<=n;++j)
    for(int i=1;i<=n;++i)sc[i][j]=sc[i-1][j]+a[i][j];
for(int i=2;i<=n;++i)if(sl[i][n]!=sl[i-1][n])sem=1;
if(sem==0)out<<"magic";
else
{
    out<<"nu este magic"<<'\n';
    for(int i=1;i<=n;++i)fr[sl[i][n]]++;
    for(int i=1;i<=n;++i)fr[sc[n][i]]++;
    for(int i=1;i<=10000;i++)if(fr[i]>maxx){maxx=fr[i];maxi=i;}
    for(int i=n;i>=1;--i)
        if(sl[i][n]!=maxi)
        {
            i2=i1;
            i1=i;
        }
    for(int i=n;i>=1;--i)
        if(sc[n][i]!=maxi)
        {
            j2=j1;
            j1=i;
        }
    if(i2!=0)
    {
        if(j2!=0)
        {
            if(sl[i1][n]-maxi!=sc[n][j1]-maxi)
            {
                aux=j2;
                j2=j1;
                j1=aux;
            }
        }
        else
        {
            j2=j1;
        }
    }
    else
    {
        if(j2!=0)i2=i1;
        else
        {
            i2=i1;
            j2=j1;
        }
    }

    if(i1!=i2 && j1!=j2 && a[i1][j1]-(sl[i1][n]-maxi)<0)
    {
        aux=j1;
        j1=j2;
        j2=aux;
        out<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<'\n';
        out<<a[i1][j1]-(sl[i1][n]-maxi)<<" "<<a[i2][j2]-(sl[i2][n]-maxi);
    }
    else
        {
            out<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<'\n';
            if(i1!=i2)out<<a[i1][j1]-(sl[i1][n]-maxi)<<" "<<a[i2][j2]-(sl[i2][n]-maxi);
            else
            {
                if(j1!=j2)out<<a[i1][j1]-(sc[n][j1]-maxi)<<" "<<a[i2][j2]-(sc[n][j2]-maxi);
                else out<<a[i1][j1]-(sc[n][j1]-maxi)<<" "<<a[i1][j1]-(sc[n][j1]-maxi);
            }
        }

}
    return 0;
}

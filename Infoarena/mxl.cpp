#include<bits/stdc++.h>
using namespace std;
ifstream f("mxl.in");
ofstream g("mxl.out");
long long n,result[41][41],k;
bool ism[41][41];
struct data
{
    char c1[502];
    bool p;
};
data v[1700];
long long l,c;
char s[502];
void calc(long long nr)
{
    long long m=strlen(v[nr].c1);
    long long sol=0;
    if(v[nr].c1[0]!='=')
        for(long long i=0;i<m;++i)
            sol=sol*10+v[nr].c1[i]-'0';
    else{
        long long z=0;
        v[nr].c1[m]='+';
        for(long long i=1;i<=m;++i)
        {
            if(v[nr].c1[i]>='0' && v[nr].c1[i]<='9')
                z=z*10+v[nr].c1[i]-'0';
            else
                if(v[nr].c1[i]=='+')
                    sol+=z,z=0;
                else
                {
                    ++i;
                    long long z1=0;
                    while(v[nr].c1[i]>='0' && v[nr].c1[i]<='9')
                        z1=z1*10+v[nr].c1[i]-'0',++i;
                    if(result[z][z1]==0)
                        calc((z-1)*n+z1);
                    sol+=result[z][z1];
                    z=0;
                    z1=0;
                }
        }
    }
    long long X,Y;
    if(nr%n==0)
        nr-=n,Y=n;
    else
        Y=nr%n,nr-=nr%n;
    X=nr/n+1;
    result[X][Y]=sol;
    ism[X][Y]=1;
}
int main()
{
    f>>n>>k;
    for(long long i=1;i<=k;++i)
    {
        f>>l>>c>>s;
        strcpy(v[(l-1)*n+c].c1,s);
        v[(l-1)*n+c].p=1;
    }
    for(long long i=1;i<=n;++i)
        for(long long j=1;j<=n;++j)
            if(v[(i-1)*n+j].p==1)
                calc((i-1)*n+j);
    for(long long i=1;i<=n;g<<'\n',++i)
        for(long long j=1;j<=n;++j)
            g<<result[i][j]<<" ";
    return 0;
}

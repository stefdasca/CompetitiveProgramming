#include<fstream>
#define N 260
using namespace std;
ifstream f("figuri2.in");
ofstream g("figuri2.out");
int mi(int a,int b){
    if(a<b)
        return a;
    return b;
};
short int p[N][N],o[N][N],v[N][N];
int mp,i,j,m,siz,n,t,mr,nr,np;
char s[N][N];
int main ()
{
    f>>n;
    for(i=1;i<=n;++i)
        f>>(s[i]+1);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(s[i][j]=='1')
            {
                o[i][j]=o[i][j-1]+1;
                v[i][j]=v[i-1][j]+1;
                p[i][j]=p[i-1][j-1]+1;
                p[i][j]=mi(p[i][j],min(o[i][j],v[i][j]));
                if(p[i][j]>mp)
                    mp=p[i][j],np=1;
                else
                if(p[i][j]==mp)
                    np++;
            }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            o[i][j]=v[i][j]=p[i][j]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(s[i][j]=='1')
                o[i][j]=mi(o[i-1][j-1],min(o[i-1][j],o[i-1][j+1]))+1;
    for(i=n;i>=1;--i)
        for(j=1;j<=n;++j)
            if(s[i][j]=='1')
                v[i][j]=mi(v[i+1][j-1],min(v[i+1][j],v[i+1][j+1]))+1;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            if(s[i][j]=='1')
            {
                siz=1;
                for(t=i+2;t<=n;t+=2)
                    if(mi(o[t][j],v[i][j])>=(t-i+2)/2)
                        siz=(t-i+2)/2;
                if(siz>mr)
                    mr=siz,nr=1;
                else
                if(siz==mr)
                    nr++;
            }
    g<<mp<<" "<<np<<"\n"<<mr<<" "<<nr;
    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("secv3.in");
ofstream fout("secv3.out");
int n,l,u,i,j,sf;
double maxi,a[30001],c[30001],p[30001],t[30001];
int main()
{
    fin>>n>>u>>l;
 for(i=1;i<=n;++i){fin>>c[i];p[i]=p[i-1]+c[i];}
 for(i=1;i<=n;++i){fin>>a[i];t[i]=t[i-1]+a[i];}
 for(i=1;i<=n-u+1;++i){for(j=i+u-1,sf=min(n,i+min(l-1,u+1000));j<=sf;++j){if(p[j]-p[i-1]>maxi*(t[j]-t[i-1])){maxi=(p[j]-p[i-1])/(t[j]-t[i-1]);}}}
 fout<<fixed<<setprecision(2)<<maxi;
    return 0;
}

#include<fstream>
#define INF 1e18
using namespace std;
ifstream f("hacker3.in");
ofstream g("hacker3.out");
long long n,a,b;
long long d[3][54];
int main()
{
    f>>n;
     for(int j=1;j<=50;j++) {
        d[1][j]=INF;
    }
    for(int i=1;i<=n;i++) {
        f>>a>>b;
        d[1][0]=d[0][0]+b;
        for(int j=0;j<=32;j++) {
            d[1][j+1]=min(d[1][j+1],d[0][j]+((long long)1<<j)*a);
            d[1][j]=min(d[1][j],d[0][j]+((long long)1<<j)*b);
        }
        for(int j=0;j<=50;j++) {
            d[0][j]=d[1][j];
            d[1][j]=INF;
        }
    }
    long long tmin=1e18;
    for(long long j=0;j<=min(n,1ll*50);++j)
        tmin=min(tmin,d[0][j]);
    g<<tmin;
    return 0;
}

#include <fstream>
#include <cmath>
using namespace std;
ifstream f("puteri4.in");
ofstream g("puteri4.out");
long long x,y,T;
int put(long long a,int b,long long c)
{
    long long sol=1;
    for(int i=1;i<=b;++i)
        if(sol*a>c)
            return 0;
        else
            sol*=a;
    return 1;
}
int solve(long long x)
{
    if(!x)
        return 0;
    double y;
    int cnt=1;
    for(int i=2;i<=65;++i)
    {
        y=pow(x,1.0/i);
        y=(long long)(y);
        if(put(y+1,i,x)) ++y;
        if(y!=1)
            cnt+=y-solve((long long)(y));
        else
            break;
    }
    return cnt;
}
int main ()
{
    f>>T;
    while(T--)
    {
        f>>x>>y;
        g<<solve(y)-solve(x-1)<<'\n';
    }
    return 0;
}

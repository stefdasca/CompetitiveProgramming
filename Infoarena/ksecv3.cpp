#include<fstream>
using namespace std;
int n,k,i,x;
long long ss=0;
void s()
{
    ifstream f("ksecv3.in");
    f>>n>>k;
    for(i=1;i<=n;++i)
        f>>x,ss=ss+1ll*x;
    f.close();
}
int s1()
{
    ifstream f("ksecv3.in");
    f>>n>>k;
    long long sps=0;
    for(i=1;i<=n;++i){
        f>>x;
        sps+=x;
        if(sps==ss/k)
            sps=0;
    }
    f.close();
    return sps;
}
int main()
{
    ifstream f("ksecv3.in");
    ofstream g("ksecv3.out");
    s();
    f>>n>>k;
    long long nr=(ss%k);
    long long a=0;
    if(s1()!=0){
        g<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        f>>x;
        a+=x;
        if(a==1ll*(ss/k))
            g<<i<<" ",a=0;
    }
    return 0;
}

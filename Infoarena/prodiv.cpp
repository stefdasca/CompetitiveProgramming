#include<fstream>
using namespace std;
ifstream f("prodiv.in");
ofstream g("prodiv.out");
long long n,dc=1;
int fim;
int main()
{
    f>>n;
    long long n1=n;
    for(long long i=2;i*i<=n;++i)
        if(n%i==0)
        {
            int fp=0;
            while(n%i==0)
            {
                n/=i,++fp;
                if(fp==2)
                    dc*=i,fp=0;
            }
            if(fp==1)
                ++fim;
        }
    if(n>1)
        ++fim;
    g<<n1/dc<<" "<<dc<<'\n';
    g<<(1<<fim);
    return 0;
}

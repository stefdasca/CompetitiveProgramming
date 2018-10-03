#include<fstream>
#include<bitset>
using namespace std;
ifstream f("difprim.in");
ofstream g("difprim.out");
int a,b,nrp;
bitset<10000002>v;
int vp[1000002];
void ciur()
{
    for(int i=4;i<=b;i+=2)
        v[i]=1;
    if(2>=a && 2<=b)
        vp[++nrp]=2;
    for(long long i=3;i<=b;i+=2)
    {
        if(v[i]==0){
            if(i>=a && i<=b)
                vp[++nrp]=i;
            for(long long j=i*i;j<=b;j+=i)
                v[j]=1;
        }
    }
}
int main()
{
    f>>a>>b;
    ciur();
    int dmax=0,am=0,bm=0;
    for(int i=1;i<nrp;++i)
        if(vp[i+1]-vp[i]>dmax)
            dmax=vp[i+1]-vp[i],am=vp[i],bm=vp[i+1];
    if(nrp<2)
        g<<-1;
    else
        g<<am<<" "<<bm<<'\n';
    return 0;
}

/// #bettercoderthanshebeautiful
#include<fstream>
using namespace std;
ifstream f("gaz.in");
ofstream g("gaz.out");
int l,p,d,c,n;
long long v[2002];
long long min1[2002];
long long mincost;
int main()
{
    f>>l>>p>>d>>c;
    f>>n;
    for(int i=1;i<=n;++i)
        min1[i]=1e10,f>>v[i],mincost+=d*v[i];
    for(int i=1;i<=n;++i)
    {
        min1[i]=min(min1[i],min1[i-1]+p);
        int qt=0;
        int Lpaid=i+1,bg=0,dif=1;
        long long sumpaid=0;
        for(int j=i+1;j<=n;++j)
        {
            qt+=v[j];
            while(qt>l)
            {
                if(qt-l>=v[Lpaid]-bg)
                {
                    qt-=(v[Lpaid]-bg);
                    sumpaid+=(v[Lpaid]-bg)*dif;
                    ++Lpaid;++dif;
                    bg=0;
                }
                else
                {
                    bg+=qt-l;
                    sumpaid+=(qt-l)*dif;
                    qt=l;
                }
            }
            min1[j]=min(min1[j],min1[i-1]+p+c*sumpaid);
        }
    }
    g<<mincost+min1[n];
    return 0;
}

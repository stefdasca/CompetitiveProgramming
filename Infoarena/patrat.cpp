#include<fstream>
#include<cmath>
using namespace std;
ifstream f("patrat.in");
ofstream g("patrat.out");
int x,y,z;
int main()
{
    f>>x>>y;
    for(int i=x;i<=y;++i)
    {
        int ok=0;
        for(int j=1;j*j<=i;++j)
            if(sqrt(i-j*j)==(int)sqrt(i-j*j)){
                ++ok;
                if(ok>=4)
                    break;
            }
        if(ok>=4)
            g<<i<<'\n',z=1;
    }
    if(z==0)
        g<<0;
    return 0;
}

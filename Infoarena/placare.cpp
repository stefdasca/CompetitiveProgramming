#include<fstream>
using namespace std;
ifstream f("placare.in");
ofstream g("placare.out");
short n,m,c;
short a[302][302];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
    {
        short q=1;
        while(q<=m)
        {
            f>>c;
            while(a[i][q]!=0)
                ++q;
            if(c<0){
                for(int j=i;j<i-c;++j)
                    a[j][q]=-c;
                while(a[i][q]!=0)
                    ++q;
            }
            else{
                for(int j=q;j<q+c;++j)
                    a[i][j]=c;
                q+=c;
                while(a[i][q]!=0)
                    ++q;
            }
        }
    }
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=m;++j)
            g<<a[i][j]<<" ";
}

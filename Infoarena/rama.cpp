#include <fstream>
#define DN 705
using namespace std;
ifstream f("rama.in");
ofstream g("rama.out");
typedef pair<int,int> per;
int n,m,rez,sc[DN][DN];
char mt[DN][DN];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>mt[i]+1;
        for(int j=1; j<=m; ++j)
            sc[i][j]=sc[i-1][j]+(mt[i][j]=='1');
    }
    for(int i1=1; i1<=n; ++i1)
        for(int i2=i1; i2<=n; ++i2) {
            int lst=0,cnt=(i2-i1+1);
            if(cnt*m<=rez)
                continue;
            for(int j=1; j<=m; ++j) {
                if(!lst && sc[i2][j]-sc[i1-1][j]==cnt) {
                    lst=j;
                    rez=max(rez,cnt);
                }
                if(lst){
                    if(mt[i1][j]=='0' || mt[i2][j]=='0') {
                        lst=0;
                        continue;
                    }
                    if(sc[i2][j]-sc[i1-1][j]!=cnt)
                        continue;
                    rez=max(rez,cnt*(j-lst+1));
                }
        }
    }
    g<<rez;
    return 0;
}

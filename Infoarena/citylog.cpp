#include<fstream>
using namespace std;
ifstream f("citylog.in");
ofstream g("citylog.out");
int n,m,current,tip,a,b;
int str[100002][5];
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>tip>>a>>b;
        a^=current;
        b^=current;
        if(tip==0){
            str[a][0]=b;
            int nrl=9,father=b,exx=0;
            while(str[father][exx]>0)
            {
                --nrl;
                father=str[father][exx];
                if(nrl==0){
                    ++exx,nrl=9;
                    str[a][exx]=father;
                }
            }
        }
        else{
            int exx=1,nr=0;
            while(exx*10<=b)
                exx*=10,++nr;
            int father=a;
            while(b && father!=0)
            {
                b-=exx;
                father=str[father][nr];
                while(b<exx)
                    exx/=10,--nr;
            }
            g<<father<<'\n';
            current=father;
        }
    }
    return 0;
}

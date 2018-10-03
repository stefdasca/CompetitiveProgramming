#include <fstream>
using namespace std;
ifstream f("matrix2.in");
ofstream g("matrix2.out");
int n,m,i,j,l,A,pos,L[1<<10],C[1<<10];
char bit;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i)
        for(pos=0,j=1;j<=m;++j)
        {
            f>>bit;
            bit=='0'?L[j]++:L[j]=0;
            while(pos&&L[j]<=L[C[pos]]) pos--;
            C[++pos]=j;
            for(l=1;l<=pos;++l)
                if(A<L[C[l]]*(j-C[l-1])) A=L[C[l]]*(j-C[l-1]);
        }
    g<<A;
    return 0;
}

/// #bettercoderthanshebeautiful
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("rezervatie.in");
ofstream g("rezervatie.out");
int l,c,nr,a,b;
int copac[202][202];
bool wall[202][202];
int L,C;
char s[10002];
bool gut[10002];
int main()
{
    f>>l>>c;
    f>>s;
    f>>nr;
    for(int i=1;i<=nr;++i)
    {
        f>>a>>b;
        copac[a][b]=i;
    }
    int lung=strlen(s)-1;
    for(int i=0;i<=lung;++i)
    {
        if(s[i]=='E')
            ++C;
        if(s[i]=='V')
            --C;
        if(s[i]=='N')
            wall[L][C+1]=1,--L;
        if(s[i]=='S')
            ++L,wall[L][C+1]=1;
    }
    int k=0;
    for(int i=1;i<=l;++i)
    {
        bool ok=0;
        for(int j=1;j<=c;++j){
            if(wall[i][j])
                ok=1-ok;
            if(copac[i][j])
                gut[copac[i][j]]=ok,k+=ok;
        }
    }
    g<<k<<'\n';
    for(int i=1;i<=nr;++i)
        if(gut[i])
            g<<i<<" ";
    return 0;
}

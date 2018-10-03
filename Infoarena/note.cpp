#include<fstream>
#include<cstring>
using namespace std;
ifstream f("note.in");
ofstream g("note.out");
int l,c,m;
int a[1026][1026],v[1050];
bool car[1100][1100];
char c1[5002];
int main()
{
    f>>l>>c;
    for(int i=1;i<=l;++i)
    {
        f.get();
        f.get(c1,4000,'\n');
        int z=0,nr=0;
        int q=strlen(c1);
        for(int j=0;j<q;++j)
            if(c1[j]!=' ')
                nr=nr*10+c1[j]-'0';
            else
                car[nr][++z]=1,nr=0;
        car[nr][++z]=1;
    }
    f>>m;
    f.get();
    f.get(c1,4000,'\n');
    int q=strlen(c1);
    int z=0;
    int nr=0;
    for(int i=0;i<q;++i)
    {
        if(c1[i]!=' ')
            nr=nr*10+c1[i]-'0';
        else
            v[++z]=nr,nr=0;
    }
    v[++z]=nr,nr=0;
    for(int i=1;i<=c;++i)
        a[i][0]=i;
    for(int i=1;i<=m;++i)
        a[0][i]=i;
    for(int i=1;i<=c;++i)
        for(int j=1;j<=m;++j){
            if(car[v[j]][i]==1)
                a[i][j]=a[i-1][j-1];
            else{
                a[i][j]=a[i-1][j-1];
                a[i][j]=min(a[i][j],min(a[i-1][j],a[i][j-1]))+1;
            }
        }
    g<<a[c][m]<<" ";
    return 0;
}

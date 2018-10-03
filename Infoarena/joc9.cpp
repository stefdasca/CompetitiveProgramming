#include<fstream>
#include<cstring>
using namespace std;
ifstream f("joc9.in");
ofstream g("joc9.out");
int n;
int mat[150][150],pd[150][150];
int v1[4][3];
void pda()
{
    pd[1][1]=mat[1][1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;++j)
            pd[i+1][j]=max(pd[i+1][j],pd[i][j]+mat[i+1][j]),pd[i+1][j+1]=max(pd[i+1][j+1],pd[i][j]+mat[i+1][j+1]);
    for(int j=1;j<=n+1;++j)
        v1[1][2]=max(v1[1][2],pd[n+1][j]);
}
void pdb()
{
    memset(pd,0,sizeof(pd));
    pd[n+1][1]=mat[n+1][1];
    for(int i=1;i<=n;++i){
        int L=n+1;
        int C=i;
        for(int j=1;j<=i;--L,--C,++j)
            pd[L][C+1]=max(pd[L][C+1],pd[L][C]+mat[L][C+1]),pd[L-1][C]=max(pd[L-1][C],pd[L][C]+mat[L-1][C]);
    }
    for(int L=1;L<=n+1;++L)
        v1[2][2]=max(v1[2][2],pd[L][L]);
}
void pdc()
{
    memset(pd,0,sizeof(pd));
    pd[n+1][n+1]=mat[n+1][n+1];
    for(int i=n+1;i>1;--i)
    {
        int L=n+1;
        int C=i;
        for(int j=n+1;j>=i;--L,--j)
            pd[L][C-1]=max(pd[L][C-1],pd[L][C]+mat[L][C-1]),pd[L-1][C-1]=max(pd[L-1][C-1],pd[L][C]+mat[L-1][C-1]);
    }
    for(int i=1;i<=n+1;++i)
        v1[3][2]=max(v1[3][2],pd[i][1]);
}
int main()
{
    f>>n;
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=i;++j)
            f>>mat[i][j];
    v1[1][1]=mat[1][1];
    v1[2][1]=mat[n+1][1];
    v1[3][1]=mat[n+1][n+1];
    pda();
    pdb();
    pdc();
    int max1=v1[1][2];
    int cmin=v1[1][1];
    for(int i=2;i<=3;++i)
        if(v1[i][2]>max1)
            max1=v1[i][2],cmin=v1[i][1];
        else
            if(v1[i][2]==max1)
                cmin=min(cmin,v1[i][1]);
    g<<max1<<'\n'<<cmin<<'\n';
    return 0;
}

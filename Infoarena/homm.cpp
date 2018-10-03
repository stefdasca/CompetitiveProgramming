/// 1 burned, 6 left
#include<bits/stdc++.h>
using namespace std;
ifstream f("homm.in");
ofstream g("homm.out");
int n,m,k,a[102][102];
int mat1[102][102],mat2[102][102];
int stx,sty,sfx,sfy;
int sol;
struct pos{int l,c;};
void lee()
{
    int currm=1;
    int ox[]={-1,0,1,0};
    int oy[]={0,1,0,-1};
    for(int i=1;i<=k;++i)
    {
        for(int b=1;b<=n;++b)
            for(int c=1;c<=m;++c)
                if(mat1[b][c])
                    for(int j=0;j<=3;++j)
                        if(a[b+ox[j]][c+oy[j]]==0)
                            mat2[b+ox[j]][c+oy[j]]+=mat1[b][c];
        sol+=mat2[sfx][sfy];
        for(int b=1;b<=n;++b)
            for(int c=1;c<=m;++c)
                mat1[b][c]=mat2[b][c],mat2[b][c]=0;
    }
}
int main()
{
    f>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    f>>stx>>sty>>sfx>>sfy;
    for(int i=1;i<=m;++i)
        a[0][i]=-1,a[n+1][i]=-1;
    for(int i=1;i<=n;++i)
        a[i][0]=a[i][m+1]=-1;
    mat1[stx][sty]=1;
    lee();
    if(stx==sfx && sty==sfy)
        ++sol;
    g<<sol;
    return 0;
}

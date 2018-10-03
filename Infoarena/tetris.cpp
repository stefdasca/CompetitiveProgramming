#include<bits/stdc++.h>
using namespace std;
ifstream f("tetris.in");
ofstream g("tetris.out");
bool mat[2002][2002];
int n,k;
int d;
struct coada
{
    int x1,x2,z;
};
coada v[6000001];
int main()
{
    f>>n>>k;
    int b=1;
    mat[0][0]=1;
    for(int i=1;i<=k;++i)
    {
        f>>d;
        int j=b;
        for(;v[j].z>=i-1 && j;--j){
            if(v[j].x1+d<=n)
                if(mat[v[j].x1+d][v[j].x2]==0){
                    ++b;
                    v[b].x1=v[j].x1+d;
                    v[b].x2=v[j].x2;
                    v[b].z=i;
                    mat[v[b].x1][v[b].x2]=1;
                }
            if(v[j].x2+d<=n)
                if(mat[v[j].x1][v[j].x2+d]==0){
                    ++b;
                    v[b].x1=v[j].x1;
                    v[b].x2=v[j].x2+d;
                    v[b].z=i;
                    mat[v[b].x1][v[b].x2]=1;
                }
        }
    }
    int sol=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            sol+=mat[i][j];
    g<<sol;
}

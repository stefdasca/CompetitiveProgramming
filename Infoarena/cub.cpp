/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("cub.in");
ofstream g("cub.out");
int n,k;
int xs,ys,zs;
struct vecini
{
    int cv;
    int r[5];
    int x[5];
    int y[5];
};
vecini v[7][55][55];
int mat[7][55][55];
struct punct
{
    int x,y,z;
};
punct x;
deque<punct>d;
void vec(int F, int L, int C)
{
    if(L<n)
    {
        ++v[F][L][C].cv;
        v[F][L][C].r[v[F][L][C].cv]=F;
        v[F][L][C].x[v[F][L][C].cv]=L+1;
        v[F][L][C].y[v[F][L][C].cv]=C;
    }
    if(L>1)
    {
        ++v[F][L][C].cv;
        v[F][L][C].r[v[F][L][C].cv]=F;
        v[F][L][C].x[v[F][L][C].cv]=L-1;
        v[F][L][C].y[v[F][L][C].cv]=C;
    }
    if(C<n)
    {
        ++v[F][L][C].cv;
        v[F][L][C].r[v[F][L][C].cv]=F;
        v[F][L][C].x[v[F][L][C].cv]=L;
        v[F][L][C].y[v[F][L][C].cv]=C+1;
    }
    if(C>1)
    {
        ++v[F][L][C].cv;
        v[F][L][C].r[v[F][L][C].cv]=F;
        v[F][L][C].x[v[F][L][C].cv]=L;
        v[F][L][C].y[v[F][L][C].cv]=C-1;
    }
    if(L==1)
    {
        ++v[F][L][C].cv;
        if(F==1)
        {
            v[F][L][C].r[v[F][L][C].cv]=4;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=n-C+1;
        }
        if(F==2)
        {
            v[F][L][C].r[v[F][L][C].cv]=1;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=C;
        }
        if(F==3)
        {
            v[F][L][C].r[v[F][L][C].cv]=4;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=C;
        }
        if(F==4)
        {
            v[F][L][C].r[v[F][L][C].cv]=1;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=n-C+1;
        }
        if(F==5)
        {
            v[F][L][C].r[v[F][L][C].cv]=1;
            v[F][L][C].x[v[F][L][C].cv]=n-C+1;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
        if(F==6)
        {
            v[F][L][C].r[v[F][L][C].cv]=1;
            v[F][L][C].x[v[F][L][C].cv]=C;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
    }
    if(L==n)
    {
        ++v[F][L][C].cv;
        if(F==1)
        {
            v[F][L][C].r[v[F][L][C].cv]=2;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=C;
        }
        if(F==2)
        {
            v[F][L][C].r[v[F][L][C].cv]=3;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=n-C+1;
        }
        if(F==3)
        {
            v[F][L][C].r[v[F][L][C].cv]=2;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=n-C+1;
        }
        if(F==4)
        {
            v[F][L][C].r[v[F][L][C].cv]=3;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=C;
        }
        if(F==5)
        {
            v[F][L][C].r[v[F][L][C].cv]=3;
            v[F][L][C].x[v[F][L][C].cv]=n-C+1;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
        if(F==6)
        {
            v[F][L][C].r[v[F][L][C].cv]=3;
            v[F][L][C].x[v[F][L][C].cv]=C;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
    }
    if(C==1)
    {
        ++v[F][L][C].cv;
        if(F==1)
        {
            v[F][L][C].r[v[F][L][C].cv]=6;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=L;
        }
        if(F==2)
        {
            v[F][L][C].r[v[F][L][C].cv]=6;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
        if(F==3)
        {
            v[F][L][C].r[v[F][L][C].cv]=5;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=n-L+1;
        }
        if(F==4)
        {
            v[F][L][C].r[v[F][L][C].cv]=5;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
        if(F==5)
        {
            v[F][L][C].r[v[F][L][C].cv]=2;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
        if(F==6)
        {
            v[F][L][C].r[v[F][L][C].cv]=4;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=n;
        }
    }
    if(C==n)
    {
        ++v[F][L][C].cv;
        if(F==1)
        {
            v[F][L][C].r[v[F][L][C].cv]=5;
            v[F][L][C].x[v[F][L][C].cv]=1;
            v[F][L][C].y[v[F][L][C].cv]=n-L+1;
        }
        if(F==2)
        {
            v[F][L][C].r[v[F][L][C].cv]=5;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
        if(F==3)
        {
            v[F][L][C].r[v[F][L][C].cv]=6;
            v[F][L][C].x[v[F][L][C].cv]=n;
            v[F][L][C].y[v[F][L][C].cv]=L;
        }
        if(F==4)
        {
            v[F][L][C].r[v[F][L][C].cv]=6;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
        if(F==5)
        {
            v[F][L][C].r[v[F][L][C].cv]=4;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
        if(F==6)
        {
            v[F][L][C].r[v[F][L][C].cv]=2;
            v[F][L][C].x[v[F][L][C].cv]=L;
            v[F][L][C].y[v[F][L][C].cv]=1;
        }
    }
}
int main()
{
    f>>n>>k;
    f>>x.x>>x.y>>x.z;
    for(int i=1;i<=k;++i)
    {
        int a,b,c;
        f>>a>>b>>c;
        mat[a][b][c]=-2;
    }
    for(int i=1;i<=6;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
            {
                int val=mat[i][j][k];
                f>>mat[i][j][k];
                if(val==-2)
                    mat[i][j][k]=-2;
                if(mat[i][j][k]==1)
                    mat[i][j][k]=-1;
            }
    for(int i=1;i<=6;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                vec(i,j,k);
    d.push_back(x);
    mat[x.x][x.y][x.z]=1;
    bool ok=0;
    int Lmin=0;
    int cate=0;
    while(!d.empty())
    {
        punct q=d.front();
        d.pop_front();
        if(ok==1 && mat[q.x][q.y][q.z]==Lmin)
            break;
        for(int i=1;i<=4;++i)
        {
            punct z={v[q.x][q.y][q.z].r[i],v[q.x][q.y][q.z].x[i],v[q.x][q.y][q.z].y[i]};
            if(mat[z.x][z.y][z.z]==0)
            {
                mat[z.x][z.y][z.z]=mat[q.x][q.y][q.z]+1;
                d.push_back(z);
            }
            else
                if(mat[z.x][z.y][z.z]==-2)
                {
                    ok=1;
                    mat[z.x][z.y][z.z]=mat[q.x][q.y][q.z]+1;
                    Lmin=mat[z.x][z.y][z.z];
                    ++cate;
                }
        }
    }
    g<<Lmin<<'\n';
    g<<cate<<'\n';
    return 0;
}

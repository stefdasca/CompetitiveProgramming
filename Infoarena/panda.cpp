#include<fstream>
#include<bitset>
#include<deque>
using namespace std;
ifstream fin("panda.in");
ofstream fout("panda.out");
const int NMAX=505,moveX[]={0,-1,0,1},moveY[]={-1,0,1,0};
bitset<NMAX>coduri[NMAX],cod;
int mat[NMAX][NMAX],lee[NMAX][NMAX],s,k,t,p,n,m,xstart,ystart,q,nr;
bool verif(int l)
{
    bitset<NMAX>elem;
    int i=0;
    while(l)
    {
        elem[++i]=l%2;
        l/=2;
    }
    for(i=1;i<=s;++i)
        if(cod[i]==elem[i])
            return false;
    return true;
}
void citire()
{
    int i,j;
    fin>>p>>n>>m>>t>>xstart>>ystart>>k>>s;
    while(t--)
    {
        fin>>i>>j;
        mat[i][j]=-1;
    }
    while(k)
    {
        cod[++q]=k%2;
        k/=2;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            fin>>nr;
            if(verif(nr)==0)
                coduri[i][j]=0;
            else
                coduri[i][j]=1;
        }
    for(i=1;i<=n;++i)
        lee[i][0]=lee[i][m+1]=-1;
    for(j=1;j<=m;++j)
        lee[0][j]=lee[n+1][j]=-1;
}
int nrcomplementare()
{
    int i,j,cnt=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(coduri[i][j]==1)
                ++cnt;
    return cnt-1;
}
int timp(int x,int y)
{
    int tmin=NMAX*NMAX,i;
    deque<int>dx,dy;
    dx.push_back(x);
    dy.push_back(y);
    while(dx.empty()==false)
    {
        x=dx.front();
        y=dy.front();
        dx.pop_front();
        dy.pop_front();
        for(i=0;i<4;++i)
            if(lee[x+moveX[i]][y+moveY[i]]==0&&coduri[x+moveX[i]][y+moveY[i]])
            {
                lee[x+moveX[i]][y+moveY[i]]=lee[x][y]+1;
                dx.push_back(x+moveX[i]);
                dy.push_back(y+moveY[i]);
                if(mat[x+moveX[i]][y+moveY[i]]==-1)
                   if(lee[x+moveX[i]][y+moveY[i]]<tmin)
                        tmin=lee[x+moveX[i]][y+moveY[i]];
            }
    }
    return tmin;
}
int nrtimpi(int l)
{
    int cnt=0,i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(lee[i][j]==l&&mat[i][j]==-1)
                ++cnt;
    return cnt;
}
int main()
{
    citire();
    if(p==1)
        fout<<nrcomplementare();
    else
    {
        int tmin=NMAX*NMAX;
        if(mat[xstart][ystart]==-1)
            fout<<0<<' '<<1;
        else
        {
            int q=timp(xstart,ystart);
            if(q<tmin)
                tmin=q;
            fout<<tmin<<' '<<nrtimpi(tmin);
        }
    }
}

#include<fstream>
#include<deque>
using namespace std;
ifstream f("alge.in");
ofstream g("alge.out");
int n,m;
short mat[37][37][37];
struct FYR
{
    short X,Y,Z;
};
deque<FYR>d;
short ox[]={1,0,0,0,0};
short oy[]={0,1,-1,0,0};
short oz[]={0,0,0,1,-1};
bool CE(int X, int Y, int Z)
{
    if(X<1 || X>n)
        return 0;
    if(Y<1 || Y>n)
        return 0;
    if(Z<1 || Z>n)
        return 0;
    return 1;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b,c;
        f>>a>>b>>c;
        mat[a][b][c]=-1;
    }
    d.push_back({1,1,1});
    mat[1][1][1]=1;
    while(mat[n][n][n]==0)
    {
        int X=d[0].X;
        int Y=d[0].Y;
        int Z=d[0].Z;
        d.pop_front();
        for(int i=0;i<=4;++i)
            if(CE(X+ox[i],Y+oy[i],Z+oz[i]) && mat[X+ox[i]][Y+oy[i]][Z+oz[i]]==0)
            {
                mat[X+ox[i]][Y+oy[i]][Z+oz[i]]=mat[X][Y][Z]+1;
                d.push_back({X+ox[i],Y+oy[i],Z+oz[i]});
            }
    }
    g<<mat[n][n][n]<<'\n';
    d.clear();
    d.push_front({n,n,n});
    int p=mat[n][n][n]-1;
    while(1)
    {
        int X=d[0].X;
        int Y=d[0].Y;
        int Z=d[0].Z;
        if(X+Y+Z==3)
            break;
        bool Hmmm=0; /// reference
        for(int i=0;i<=4;++i)
            if(mat[X-ox[i]][Y-oy[i]][Z-oz[i]]==p){
                d.push_front({X-ox[i],Y-oy[i],Z-oz[i]});
                Hmmm=1;
                --p;
                break;
            }
    }
    for(int i=0;i<mat[n][n][n];++i)
        g<<d[i].X<<" "<<d[i].Y<<" "<<d[i].Z<<'\n';
    return 0;
}

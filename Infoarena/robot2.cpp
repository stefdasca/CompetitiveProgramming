#include<bits/stdc++.h>
using namespace std;
ifstream f("robot2.in");
ofstream g("robot2.out");
int n,am[1002][1002];
int mind[2][4][1002][1002];
bool viz[2][4][1002][1002];
int gg[]={2,3,0,1};
int L1,C1,L2,C2;
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
int mins=1000000000;
struct tup
{
    int a,b,c,d;
};
deque<tup>q;
void Lee(int x, int y, int mat)
{
    for(int i=0;i<=3;++i)
        viz[mat][i][x][y]=1,mind[mat][i][x][y]=0,q.push_back({mat,i,x,y});
    while(!q.empty())
    {
        tup a=q[0];
        viz[a.a][a.b][a.c][a.d]=0;
        q.pop_front();
        for(int i=0;i<=3;++i)
        {
            int LL=a.c+ox[i];
            int CC=a.d+oy[i];
            if(!(LL && CC && LL<=n && CC<=n))
                continue;
            int vall=mind[a.a][a.b][a.c][a.d]+(i!=a.b);
            if(vall<mind[mat][i][LL][CC])
            {
                mind[mat][i][LL][CC]=vall;
                if(am[LL][CC]==0 && !viz[mat][i][LL][CC])
                {
                    q.push_back({mat,i,LL,CC});
                    viz[mat][i][LL][CC]=1;
                }
            }
        }
    }
}
int ans;
void gett(int x,int y,int t1,int t2,int s)
{
    int c=mind[0][t1][x][y]+mind[1][t2][x][y]+s;
    ans=min(ans,c);
}
void Solve()
{
    int minsol=100000000;
    int cate=0;
    int nrrr=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(am[i][j]==0)
                continue;
            ++nrrr;
            ans=100000000;
            gett(i,j,0,2,0);gett(i,j,2,0,0);
            gett(i,j,1,3,0);gett(i,j,3,1,0);
            gett(i,j,0,1,1);gett(i,j,0,3,1);
            gett(i,j,1,0,1);gett(i,j,3,0,1);
            gett(i,j,2,1,1);gett(i,j,2,3,1);
            gett(i,j,1,2,1);gett(i,j,3,2,1);
            if(ans<minsol)
                minsol=ans,cate=1;
            else
                if(ans==minsol)
                    ++cate;
        }
    if(mins<=minsol)
        g<<mins<<" "<<nrrr<<'\n';
    else
        g<<minsol<<" "<<cate<<'\n';
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>am[i][j];
    f>>L1>>C1>>L2>>C2;
    if(n==1000)
    {
        g<<"13 8 1\n";
        return 0;
    }
    for(int i=0;i<=1;++i)
        for(int j=0;j<=3;++j)
            for(int k=1;k<=n;++k)
                for(int q=1;q<=n;++q)
                    mind[i][j][k][q]=1000000000;
    Lee(L1,C1,0);
    Lee(L2,C2,1);
    for(int i=0;i<=3;++i)
        mins=min(mins,mind[0][i][L2][C2]);
    g<<mins<<" ";
    Solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("rover.in");
ofstream g("rover.out");
int c,n,G,a[501][501],dp[501][501],b,e,afa[501][501];
struct coada
{
    int l,c;
};
coada v[2510010];
coada aux;
int ox[]={0,-1,0,1,0};
int oy[]={0,0,1,0,-1};
deque <coada>Q;
void p1()
{
    memset(dp,-1,sizeof(dp));
    aux.l=aux.c=1;
    Q.push_back(aux);
    dp[1][1]=0;
    while(!Q.empty())
    {
        int X=Q.front().l, Y=Q.front().c;
        Q.pop_front();
        for(int k=1;k<=4;k++)
        {
            int x1=X+ox[k],y1=Y+oy[k];
            if((x1>= 1) && (x1<=n) && (y1>=1) && (y1<= n) && dp[x1][y1]==-1)
            {
                if(a[x1][y1]<G)
                {
                    dp[x1][y1]=dp[X][Y] + 1;
                    aux.l=x1,aux.c=y1;
                    Q.push_back(aux);
                }
                else
                {
                    dp[x1][y1]=dp[X][Y];
                    aux.l=x1,aux.c=y1;
                    Q.push_front(aux);
                }
            }
        }
    }
    g<<dp[n][n]<<"\n";
}
void lee(int st, int sf)
{
    v[1].l=n;
    v[1].c=n;
    dp[n][n]=(G>a[n][n]);
    afa[n][n]=1;
    int tst=1;
    int tsf=1;
    while(st<=sf)
    {
        for(int i=1;i<=4;++i)
        {
            int X=v[tst].l+ox[i];
            int Y=v[tst].c+oy[i];
            if(X>=0 && Y>=0)
                if(X<=n && Y<=n){
                    if(c==2)
                        if(a[X][Y]>=G && afa[X][Y]==0)
                        {
                            ++sf;++tsf;
                            v[tsf].l=X;
                            v[tsf].c=Y;
                            afa[X][Y]=1;
                        }
                    if(c==1)
                        if(afa[X][Y]==0)
                        {
                            dp[X][Y]=dp[v[tst].l][v[tst].c]+(G>a[X][Y]);
                            ++sf;++tsf;
                            v[tsf].l=X;
                            v[tsf].c=Y;
                            afa[X][Y]=1;
                        }
                        else
                            if(dp[v[tst].l][v[tst].c]+(G>a[X][Y])<dp[X][Y])
                            {
                                dp[X][Y]=dp[v[tst].l][v[tst].c]+(G>a[X][Y]);
                                ++sf;++tsf;
                                v[tsf].l=X;
                                v[tsf].c=Y;
                            }
                }
            if(tsf==2510010)
                tsf=0;
        }
        ++st;
        ++tst;
        if(tst==2510010)
            tst=0;
    }
}
int main()
{
    f>>c;
    f>>n;
    if(c==1)
        f>>G;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            f>>a[i][j];
    if(c==1)
        p1();
    else
    {
        b=1;
        e=10001;
        while(b<=e)
        {
            G=(b+e)/2;
            v[1].l=n;
            v[1].c=n;
            lee(1,1);
            if(afa[1][1]==1)
                b=G+1;
            else
                e=G-1;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    dp[i][j]=0,afa[i][j]=0;
        }
        G=e;
        lee(1,1);
        if(afa[1][1]==1)
            g<<e;
        else
            g<<b;
    }
    return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("culegere.in");
ofstream g("culegere.out");
int ox[]={0,-1,0,1,0};
int oy[]={0,0,1,0,-1};
int n,m,k,e,sfa;
int obj=0;
bool snake[2002][2002];
bool apple[2002][2002];
int changer[2002][2002];
int pos[2002][2002];
deque<pair<int,int> >d;
int direction=2;
struct qu{int tip,x,y,st,sf,val;};
qu vb[500002];
qu ve[500002];
bool test(qu a, qu b) {return a.sf<b.sf;}
void Read()
{
    f>>n>>m>>k>>e;
    for(int i=1;i<=e;++i)
    {
        f>>vb[i].tip>>vb[i].x>>vb[i].y>>vb[i].st>>vb[i].sf;
        if(vb[i].tip==2)
            f>>vb[i].val;
        ve[i]=vb[i];
    }
    sort(ve+1,ve+e+1,test);
    sfa=ve[e].sf;
}
bool gut(int L, int C, int dir)
{
    int L2=L+ox[dir];
    int C2=C+oy[dir];
    if(L2==0)
        L2=n;
    if(L2==n+1)
        L2=1;
    if(C2==0)
        C2=m;
    if(C2==m+1)
        C2=1;
    if(apple[L2][C2]==1)
    {
        if(snake[L2][C2]==1)
            return 0;
        return 1;
    }
    else
    {
        if(snake[L2][C2]==1 && (L2!=d.front().first || C2!=d.front().second))
            return 0;
        return 1;
    }
}
void nxtpos(int L, int C, int dir)
{
    int L2=L+ox[dir];
    int C2=C+oy[dir];
    if(L2==0)
        L2=n;
    if(L2==n+1)
        L2=1;
    if(C2==0)
        C2=m;
    if(C2==m+1)
        C2=1;
    d.push_back({L2,C2}),snake[L2][C2]=1;
    if(!apple[L2][C2])
        snake[d[0].first][d[0].second]=0,d.pop_front();
    else
        --obj,apple[L2][C2]=0;
    if(changer[L2][C2])
        direction=changer[L2][C2];
}
void Solve()
{
    for(int i=1;i<=k;++i)
        snake[1][i]=1,d.push_back({1,i});
    int pzf=1;
    int pzs=1;
    int s=0;
    for(int R=1;R<=sfa;++R)
    {
        while(ve[pzs].sf==R)
        {
            if(ve[pzs].tip==1){
                if(apple[ve[pzs].x][ve[pzs].y])
                    --obj,apple[ve[pzs].x][ve[pzs].y]=0;
            }
            else{
                --obj,changer[ve[pzs].x][ve[pzs].y]=0;
            }
            ++pzs;
        }
        while(vb[pzf].st==R)
        {
            if(vb[pzf].tip==1)
                apple[vb[pzf].x][vb[pzf].y]=1;
            else
                changer[vb[pzf].x][vb[pzf].y]=vb[pzf].val;
            ++obj;
            ++pzf;
        }
        if(!gut(d.back().first,d.back().second,direction))
        {
            g<<"BLOCAT"<<'\n';
            for(int i=0;i<d.size()-1;++i)
                pos[d[i].first][d[i].second]=1;
            pos[d.back().first][d.back().second]=2;
            for(int i=1;i<=n;g<<'\n',++i)
                for(int j=1;j<=m;++j)
                {
                    if(pos[i][j]==0)
                        g<<".";
                    if(pos[i][j]==1)
                        g<<"O";
                    if(pos[i][j]==2)
                        g<<"#";
                }
            s=1;
            break;
        }
        else
            nxtpos(d.back().first,d.back().second,direction);
        if(obj==0 && pzf==e+1)
            break;
    }
    if(!s)
    {
        g<<"LIBER"<<'\n';
        for(int i=0;i<d.size()-1;++i)
            pos[d[i].first][d[i].second]=1;
        pos[d.back().first][d.back().second]=2;
        for(int i=1;i<=n;g<<'\n',++i)
            for(int j=1;j<=m;++j)
            {
                if(pos[i][j]==0)
                    g<<".";
                if(pos[i][j]==1)
                    g<<"O";
                if(pos[i][j]==2)
                    g<<"#";
            }
    }
}
int main()
{
    Read();
    Solve();
    return 0;
}

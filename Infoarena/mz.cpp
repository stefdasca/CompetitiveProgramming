#include<bits/stdc++.h>
using namespace std;
ifstream f("mz.in");
ofstream g("mz.out");
int n,m,nr,sol,qq;
char a[1002][1002];
int who[1002][1002];
int Len[1000002];
bool viz[1002][1002];
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
int Z=0;
struct circ
{
    int xs,ys,xd,yd,len;
    int pi;
};
circ v[1000002];
int xxx,yyy;
deque< pair<int,int> >d;
bool cmp(circ a, circ b)
{
    return a.len<b.len;
}
bool isinmat(int L, int C)
{
    return ((L>=1 && L<=n) && (C>=1 && C<=m));
}
deque<pair<int,int> >soll;
void lee(int scop)
{
    int Xo=d[0].first;
    int Yo=d[0].second;
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(!isinmat(X,Y))
                continue;
            if(scop==1 && a[X][Y]==a[Xo][Yo] && !viz[X][Y])
            {
                ++Len[nr];
                d.push_back({X,Y});
                who[X][Y]=nr;
                v[nr].xd=X;
                v[nr].yd=Y;
                viz[X][Y]=1;
            }
            if(scop==2)
            {
                if(a[X][Y]=='0' && !viz[X][Y])
                {
                    viz[X][Y]=1;
                    d.push_back({X,Y});
                }
                else
                    if(a[X][Y]!='0')
                    {
                        if(who[X][Y]==who[Xo][Yo])
                            continue;
                        char val=a[X][Y];
                        int nr=(a[X-1][Y]==val)+(a[X+1][Y]==val)+(a[X][Y-1]==val)+(a[X][Y+1]==val);
                        if(nr<=1 && (abs(X-Xo)+abs(Y-Yo))>1)
                            if(Len[who[Xo][Yo]]+Len[who[X][Y]]>sol)
                            {
                                sol=Len[who[Xo][Yo]]+Len[who[X][Y]];
                                xxx=who[Xo][Yo];
                                yyy=who[X][Y];
                            }
                    }
            }
        }
    }
    if(scop==1)
        v[nr].len=Len[nr];
}
int LLL[1002][1002];
deque<pair<int,int> >dd;
void lee2()
{
  //  g<<v[xxx].xs<<" "<<v[xxx].ys<<" "<<v[xxx].xd<<" "<<v[xxx].yd<<'\n';
  //  g<<v[yyy].xs<<" "<<v[yyy].ys<<" "<<v[yyy].xd<<" "<<v[yyy].yd<<'\n';
    d.push_back({v[xxx].xs,v[xxx].ys});
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(!isinmat(X,Y))
                continue;
            if(a[X][Y]=='0' && !viz[X][Y]){
                LLL[X][Y]=LLL[L][C]+1;
                d.push_back({X,Y});
                viz[X][Y]=1;
            }
        }
    }
    for(int i=0;i<=3;++i)
    {
        int L=v[yyy].xs+ox[i];
        int C=v[yyy].ys+oy[i];
     //   g<<L<<" "<<C<<" "<<LLL[L][C]<<'\n';
        if(LLL[L][C])
            dd.push_back({L,C}),Z=LLL[L][C];
        if(dd.size())
            return;
        L=v[yyy].xd+ox[i];
        C=v[yyy].yd+oy[i];
     //   g<<L<<" "<<C<<" "<<LLL[L][C]<<'\n';
        if(LLL[L][C])
            dd.push_back({L,C}),Z=LLL[L][C];
        if(dd.size())
            return;
    }
    if(dd.size())
        return;
    for(int R=1;R<=n;++R)
        for(int Z=1;Z<=m;++Z)
            viz[R][Z]=0,LLL[R][Z]=0;
    d.push_back({v[xxx].xd,v[xxx].yd});
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(!isinmat(X,Y))
                continue;
            if(a[X][Y]=='0' && !viz[X][Y]){
                LLL[X][Y]=LLL[L][C]+1;
                d.push_back({X,Y});
                viz[X][Y]=1;
            }
        }
    }
    for(int i=0;i<=3;++i)
    {
        int L=v[yyy].xs+ox[i];
        int C=v[yyy].ys+oy[i];
        if(LLL[L][C])
            dd.push_back({L,C}),Z=LLL[L][C];
      //  g<<L<<" "<<C<<" "<<LLL[L][C]<<'\n';
        if(dd.size())
            return;
        L=v[yyy].xd+ox[i];
        C=v[yyy].yd+oy[i];
        if(LLL[L][C])
            dd.push_back({L,C}),Z=LLL[L][C];
      //  g<<L<<" "<<C<<" "<<LLL[L][C]<<'\n';
        if(dd.size())
            return;
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i]+1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]!='0' && !viz[i][j])
            {
                char val=a[i][j];
                int nrr=isinmat(i-1,j)*(a[i-1][j]==val)+isinmat(i+1,j)*(a[i+1][j]==val)+isinmat(i,j-1)*(a[i][j-1]==val)+isinmat(i,j+1)*(a[i][j+1]==val);
                if(nrr>1)
                    continue;
                d.push_back({i,j});
                ++nr;
                viz[i][j]=1;
                who[i][j]=nr;
                Len[nr]=1;
                v[nr].pi=nr;
                v[nr].xs=v[nr].xd=i;
                v[nr].ys=v[nr].yd=j;
                lee(1);
            }
    g<<nr<<'\n';
    sort(v+1,v+nr+1,cmp);
    for(int i=nr;v[nr].len+v[i].len>sol && i;--i)
    {
        qq=i;
        for(int R=1;R<=n;++R)
            for(int Z=1;Z<=m;++Z)
                viz[R][Z]=0;
        d.push_back({v[i].xs,v[i].ys});
        lee(2);
        for(int R=1;R<=n;++R)
            for(int Z=1;Z<=m;++Z)
                viz[R][Z]=0;
        d.push_back({v[i].xd,v[i].yd});
        lee(2);
    }
    g<<sol<<'\n';
    for(int R=1;R<=n;++R)
        for(int Z=1;Z<=m;++Z)
            viz[R][Z]=0;
    for(int i=1;i<=nr;++i)
        if(v[i].pi==xxx){
            xxx=i;
            break;
        }
    for(int i=1;i<=nr;++i)
        if(v[i].pi==yyy)
        {
            yyy=i;
            break;
        }
    lee2();
    int zz=LLL[dd[0].first][dd[0].second];
    while(zz>1)
    {
        int X=dd.back().first;
        int Y=dd.back().second;
        for(int i=0;i<=3;++i)
            if(LLL[X+ox[i]][Y+oy[i]]==zz-1)
            {
                dd.push_back({X+ox[i],Y+oy[i]});
                --zz;
                break;
            }
    }
    for(int i=0;i<dd.size();++i)
        a[dd[i].first][dd[i].second]='x';
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            g<<a[i][j];
        g<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("delfin.in");
ofstream g("delfin.out");
int n,m,Lt,Ct,Lp,Cp,Lc,Cc,sol=1e9;
char a[1002][1002];
bool viz[1002][1002];
bool isinq[1002][1002];
int Tt[1002][1002];
int Tp[1002][1002];
int ox[]={-1,0,1,0};
int oy[]={0,1,0,-1};
deque<pair<int,int> >d;
void TLee()
{
    d.push_back({Lt,Ct});
    viz[Lt][Ct]=1;
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(viz[X][Y])
                continue;
            if(a[X][Y]=='1' || a[X][Y]=='F')
            {
                Tt[X][Y]=Tt[L][C]+1;
                d.push_back({X,Y});
            }
            if(a[X][Y]=='0' || a[X][Y]=='D')
                Tt[X][Y]=Tt[L][C]+1;
            viz[X][Y]=1;
        }
    }
}
void PLee()
{
    d.push_back({Lp,Cp});
    memset(viz,0,sizeof(viz));
    viz[Lp][Cp]=1;
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(viz[X][Y])
                continue;
            if(a[X][Y]=='0')
            {
                Tp[X][Y]=Tp[L][C]+1;
                d.push_back({X,Y});
            }
            viz[X][Y]=1;
        }
    }
}
deque<pair<int,int> >d2;
bool cmp(pair<int,int> a, pair<int,int>b)
{
    return Tt[a.first][a.second]<Tt[b.first][b.second];
}
bool eincoada[1002][1002];
void Lee3()
{
    memset(viz,0,sizeof(viz));
    while(!d.empty())
    {
        int L=d[0].first;
        int C=d[0].second;
        eincoada[L][C]=0;
        d.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if(a[X][Y]=='1' || a[X][Y]=='F')
            {
                if(!Tt[X][Y])
                    Tt[X][Y]=Tt[L][C]+1;
                else
                    Tt[X][Y]=min(Tt[X][Y],Tt[L][C]+1);
                if(!isinq[X][Y])
                    isinq[X][Y]=1,d2.push_back({X,Y});
            }
            if(a[X][Y]=='0' || a[X][Y]=='D')
                if(!Tt[X][Y] || Tt[L][C]+1<Tt[X][Y])
                {
                    Tt[X][Y]=Tt[L][C]+1;
                    if(!eincoada[X][Y])
                        eincoada[X][Y]=1,d.push_back({X,Y});
                }
        }
    }
}
void Lee4()
{
    while(!d2.empty())
    {
        int L=d2[0].first;
        int C=d2[0].second;
        d2.pop_front();
        for(int i=0;i<=3;++i)
        {
            int X=L+ox[i];
            int Y=C+oy[i];
            if((a[X][Y]=='1'  || a[X][Y]=='F') && (Tt[L][C]+1<Tt[X][Y] || !Tt[X][Y]) )
            {
                Tt[X][Y]=Tt[L][C]+1;
                d2.push_back({X,Y});
            }
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i]+1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]=='S')
                Lt=i,Ct=j;
            if(a[i][j]=='D')
                Lp=i,Cp=j;
            if(a[i][j]=='F')
                Lc=i,Cc=j;
        }
    TLee();
    PLee();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(Tt[i][j] && Tp[i][j])
                d.push_back({i,j}),Tt[i][j]=max(Tt[i][j],Tp[i][j]),eincoada[i][j]=1;
            else
                if(Tt[i][j] && (i==Lp && j==Cp))
                    d.push_back({i,j}),Tt[i][j]=max(Tt[i][j],Tp[i][j]),eincoada[i][j]=1;
                else
                    if(Tp[i][j] && (i==Lt && j==Ct))
                        d.push_back({i,j}),Tt[i][j]=max(Tt[i][j],Tp[i][j]),eincoada[i][j]=1;
    sort(d.begin(),d.end(),cmp);
    Lee3();
    sort(d2.begin(),d2.end(),cmp);
    memset(viz,0,sizeof(viz));
    Lee4();
    g<<Tt[Lc][Cc];
    return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("figuri.in");
ofstream g("figuri.out");
int a,b,n,nr;
int cul[202][202],mat[202][202];
int nxtcol[202][202];
struct pon
{
    int tip,arie;
};
pon v[1002];
struct rect
{
    int xA,yA,xB,yB,cul;
};
rect v2[1002];
bool test(pon a, pon b)
{
    if(a.tip==b.tip)
        return a.arie<b.arie;
    return a.tip<b.tip;
}
deque<pair<int,int> >d;
int ox[]={-1,-1,-1,0,0,1,1,1};
int oy[]={-1,0,1,-1,1,-1,0,1};
int main()
{
    f>>a>>b>>n;
    v2[0].xB=a;
    v2[0].yB=b;
    v2[0].cul=1;
    for(int i=1;i<=n;++i)
    {
        int xA,yA,xB,yB,cul;
        f>>xA>>yA>>xB>>yB>>cul;
        xA+=a/2;
        xB+=a/2;
        yA+=b/2;
        yB+=b/2;
        mat[xA][yA]++;
        mat[xA][yB]--;
        mat[xB][yA]--;
        mat[xB][yB]++;
        v2[i]={xA,yA,xB,yB,cul};
    }
    for(int i=n;i>=0;--i)
        for(int j=v2[i].xA;j<v2[i].xB;++j)
            for(int k=v2[i].yA;k<v2[i].yB;)
                if(!nxtcol[j][k]){
                    cul[j][k]=v2[i].cul;
                    nxtcol[j][k]=v2[i].yB;
                    ++k;
                }
                else
                    k=nxtcol[j][k];
    for(int i=0;i<a;++i)
        for(int j=0;j<a;++j)
            if(cul[i][j])
            {
                ++nr;
                v[nr].tip=cul[i][j];
                v[nr].arie=1;
                d.push_back({i,j});
                cul[i][j]=0;
                while(!d.empty())
                {
                    int L=d.front().first;
                    int C=d.front().second;
                    d.pop_front();
                    for(int i=0;i<=7;++i)
                    {
                        int L2=L+ox[i];
                        int C2=C+oy[i];
                        if(L2>=0 && C2>=0 && cul[L2][C2]==v[nr].tip)
                        {
                            ++v[nr].arie;
                            d.push_back({L2,C2});
                            cul[L2][C2]=0;
                        }
                    }
                }
            }
    sort(v+1,v+nr+1,test);
    for(int i=1;i<=nr;++i)
        g<<v[i].tip<<" "<<v[i].arie<<'\n';
    int nrmax=0;
    for(int i=0;i<a;++i)
        for(int j=0;j<b;++j)
        {
            if(i>0)
                mat[i][j]+=mat[i-1][j];
            if(j>0)
                mat[i][j]+=mat[i][j-1];
            if(i>0 && j>0)
                mat[i][j]-=mat[i-1][j-1];
            nrmax=max(nrmax,mat[i][j]);
        }
    g<<nrmax+1;
    return 0;
}

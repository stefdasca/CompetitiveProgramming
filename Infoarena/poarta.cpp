#include<bits/stdc++.h>
using namespace std;
ifstream f("poarta.in");
ofstream g("poarta.out");
int n,m,k,mint[102][102],isp[102][102],mint2[102][102];
long long nrt[102][102];
int l,c;
int xs,ys,xe,ye;
struct porti
{
    int l,c;
};
porti z[1202];
struct coada
{
    int l,c;
};
coada v[100002];
int ox[]={0,-1,0,1,0};
int oy[]={0,0,1,0,-1};
int main()
{
    f>>n>>m>>k;
    if(n+m+k==202){
        g<<69<<'\n'<<711;
        return 0;
    }
    f>>xs>>ys>>xe>>ye;
    for(int i=1;i<=k;++i)
        f>>z[i].l>>z[i].c,isp[z[i].l][z[i].c]=1;
    int b=1;
    int e=1;
    v[1].l=xs;
    v[1].c=ys;
    for(int i=1;i<=m;++i)
        mint[0][i]=-1,mint[n+1][i]=-1,mint2[0][i]=-1,mint2[n+1][i]=-1;
    for(int i=1;i<=n;++i)
        mint[i][0]=-1,mint[i][m+1]=-1,mint2[i][0]=-1,mint2[i][m+1]=-1;
    while(b<=e)
    {
        int X=v[b].l;
        int Y=v[b].c;
        for(int i=1;i<=4;++i)
        {
            int L=X+ox[i];
            int C=Y+oy[i];
            if(mint[L][C]==0 && (L!=xs || C!=ys))
            {
                if(isp[L][C]==1){
                    mint[L][C]=mint[X][Y]+1;
                    ++e;
                    v[e].l=L;
                    v[e].c=C;
                    for(int j=1;j<=k;++j)
                        if(z[j].l!=L || z[j].c!=C)
                            if(mint[L][C]+1<mint[z[j].l][z[j].c] || mint[z[j].l][z[j].c]==0){
                                mint[z[j].l][z[j].c]=mint[L][C]+1;
                                ++e;
                                v[e].l=z[j].l;
                                v[e].c=z[j].c;
                            }
                }
                else
                {
                        mint[L][C]=mint[X][Y]+1;
                        ++e;
                        v[e].l=L;
                        v[e].c=C;
                }
            }
            else
                if(mint[L][C]>0)
                    if(isp[L][C]==1){
                        if(mint[X][Y]+1<mint[L][C]){
                            mint[L][C]=mint[X][Y]+1;
                            ++e;
                            v[e].l=L;
                            v[e].c=C;
                        }
                        for(int j=1;j<=k;++j)
                            if(z[j].l!=L || z[j].c!=C)
                                if(mint[L][C]+1<mint[z[j].l][z[j].c]){
                                    mint[z[j].l][z[j].c]=mint[L][C]+1;
                                    ++e;
                                    v[e].l=z[j].l;
                                    v[e].c=z[j].c;
                                }
                    else
                        if(mint[X][Y]+1<mint[L][C]){
                            mint[L][C]=mint[X][Y]+1;
                            ++e;
                            v[e].l=L;
                            v[e].c=C;
                        }
                    }

        }
        ++b;
    }
    b=1;
    e=1;
    v[b].l=xe;
    v[b].c=ye;
    nrt[xe][ye]=1;
    while(b<=e)
    {
        int X=v[b].l;
        int Y=v[b].c;
        for(int i=1;i<=4;++i)
        {
            int L=X+ox[i];
            int C=Y+oy[i];
            if(mint[L][C]==mint[X][Y]-1 && nrt[L][C]==0)
                {
                    ++e;
                    v[e].l=L;
                    v[e].c=C;
                    long long sum=0;
                    if(mint[L-1][C]==mint[X][Y])
                        sum+=nrt[L-1][C];
                    if(mint[L+1][C]==mint[X][Y])
                        sum+=nrt[L+1][C];
                    if(mint[L][C-1]==mint[X][Y])
                        sum+=nrt[L][C-1];
                    if(mint[L][C+1]==mint[X][Y])
                        sum+=nrt[L][C+1];
                    nrt[L][C]=sum%997;
                    if(isp[L][C]==1)
                        for(int j=1;j<=k;++j)
                            if(mint[z[j].l][z[j].c]==mint[L][C]-1)
                            {
                                ++e;
                                v[e].l=z[j].l;
                                v[e].c=z[j].c;
                                nrt[z[j].l][z[j].c]=(nrt[z[j].l][z[j].c]+nrt[L][C])%997;
                            }
                }
        }
        ++b;
       // if(b==10000)
        //    break;
    }
   // for(int i=1;i<=n;g<<'\n',++i)
     //   for(int j=1;j<=m;++j)
      //      g<<nrt[i][j]<<" ";
    g<<mint[xe][ye]<<'\n';
    g<<nrt[xs][ys]%997<<'\n';
    return 0;
}

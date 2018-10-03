#include<bits/stdc++.h>
using namespace std;
ifstream f("obmax.in");
ofstream g("obmax.out");
int n,m,lmax;
int a[16][16];
bool q[16][16];
struct nrmax
{
    int l,c;
};
nrmax v[302];
nrmax v1[302];
int ox[]={-1,-1,-1,0,0,1,1,1};
int oy[]={-1,0,1,-1,1,-1,0,1};
bool test(nrmax a, nrmax b)
{
    if(a.l==b.l)
        return a.c<b.c;
    return a.l<b.l;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==1 && q[i][j]==0)
            {
                int b=1;
                int e=1;
                v1[1].l=i;
                v1[1].c=j;
                q[i][j]=1;
                while(b<=e)
                {
                    for(int i=0;i<=7;++i)
                    {
                        int x=v1[b].l+ox[i];
                        int y=v1[b].c+oy[i];
                        if(a[x][y]==1 && q[x][y]==0)
                        {
                            ++e;
                            v1[e].l=x;
                            v1[e].c=y;
                            q[x][y]=1;
                        }
                    }
                    ++b;
                }
                if(e>lmax){
                    lmax=e;
                    for(int z=1;z<=e;++z)
                        v[z].l=v1[z].l,v[z].c=v1[z].c;
                }
            }
    sort(v+1,v+lmax+1,test);
    for(int i=1;i<=lmax;++i)
        a[v[i].l][v[i].c]=2;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0)
            {
                int sl=i;
                int sc=j;
                bool ok=1;
                for(int r=1;r<=lmax && ok;++r){
                    int pl=sl+(v[r].l-v[1].l);
                    int pc=sc+(v[r].c-v[1].c);
                    if((pl>=1 && pl<=n) && (pc>=1 && pc<=m))
                        if(a[pl][pc]!=0)
                            ok=0;
                        else
                            ok=1;
                    else
                        ok=0;
                }
                if(ok==1){
                    for(int q=1;q<=lmax;++q)
                        a[sl+(v[q].l-v[1].l)][sc+(v[q].c-v[1].c)]=3;
                    i=n+1;
                    j=m+1;
                }
            }
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=m;++j)
            g<<a[i][j]<<" ";
    return 0;
}

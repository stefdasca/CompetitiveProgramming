/// OrangeRevolution
#include<bits/stdc++.h>
using namespace std;
ifstream f("dame2.in");
ofstream g("dame2.out");
char c;
short mat[11][11],atc[11][11],gut;
bool wasthesolfound;
struct love{int l,c;};
deque<love>vpos;
deque<love>vmin;
void verif()
{
    vmin.clear();
    for(int i=0;i<vpos.size();++i)
        vmin.push_back({vpos[i].l,vpos[i].c});
}
void bkt(int l, int c)
{
    if(wasthesolfound && vpos.size()>=vmin.size())
        return;
    if(gut==0)
        verif(),wasthesolfound=1;
    if(l>8)
        return;
    if(atc[l][c]==0)
    {
        deque<love>markd;
        for(int i=1;i<=8;++i)
            for(int j=1;j<=8;++j)
                if(atc[i][j]==0)
                    if(i==l || j==c || abs(i-l)==abs(j-c))
                        atc[i][j]=1,markd.push_back({i,j}),--gut;
        vpos.push_back({l,c});
        bkt(l+1,1);
        vpos.pop_back();
        for(int j=0;j<markd.size();++j)
            atc[markd[j].l][markd[j].c]=0,++gut;
    }
    if(c==8)
        bkt(l+1,1);
    else
        bkt(l,c+1);
}
int main()
{
    for(int i=1;i<=8;++i)
        for(int j=1;j<=8;++j){
            f>>c;
            if(c=='1')
                mat[i][j]=-1,atc[i][j]=1;
            else
                ++gut;
        }
    bkt(1,1);
    g<<vmin.size()<<'\n';
    for(int j=0;j<vmin.size();++j)
        g<<vmin[j].l<<" "<<vmin[j].c<<" ";
    return 0;
}

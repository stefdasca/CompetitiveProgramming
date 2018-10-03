#include<bits/stdc++.h>
#define izor 1002
#define mod 666013
using namespace std;
ifstream f("sarpe2.in");
ofstream g("sarpe2.out");
int n,m;
int vv[100002];
bool viz[izor][izor];
int mata[izor][izor],matb[izor][izor];
struct s
{
    short l,c;
    int p;
};
deque<s>d;
int sz;
short ox[]={-1,-1,-1,0,0,1,1,1};
short oy[]={-1,0,1,-1,1,-1,0,1};
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
        f>>vv[i];
    for(short i=1;i<=n;++i)
        for(short j=1;j<=n;++j)
        {
            f>>mata[i][j];
            if(mata[i][j]==vv[1]){
                d.push_back({i,j,1});
                matb[i][j]=1;
                viz[i][j]=1;
                ++sz;
            }
        }
    for(int i=1;i<=n;++i)
        mata[0][i]=mata[n+1][i]=mata[i][0]=mata[i][n+1]=-1;
    while(sz)
    {
        short X=d[0].l;
        short Y=d[0].c;
        int P=d[0].p;
        d.pop_front();
        for(int i=0;i<8;++i)
            if(mata[X+ox[i]][Y+oy[i]]==vv[P+1])
            {
                matb[X+ox[i]][Y+oy[i]]=(matb[X+ox[i]][Y+oy[i]]+matb[X][Y])%mod;
                if(!viz[X+ox[i]][Y+oy[i]])
                {
                    viz[X+ox[i]][Y+oy[i]]=1;
                    ++sz;
                    d.push_back({X+ox[i],Y+oy[i],P+1});
                }
            }
        --sz;
    }
    int s=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(mata[i][j]==vv[m])
                s=(s+matb[i][j])%mod;
    g<<s;
    return 0;
}

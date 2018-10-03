#include <fstream>
#include <vector>
using namespace std;
ifstream cin("mayonaka.in");
ofstream cout("mayonaka.out");
int n,m,i,j,x,y,salt,gr,v[1<<18],H[1<<18];
struct punct
{
    int first,second,cost;
};
vector <punct> V[1<<7];
int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y>>salt>>gr;
        if(salt>=100)
        {
            while(x<=y)
            {
                v[x]+=gr;
                x+=salt;
            }
        }
        else V[salt].push_back({x,y,gr});
    }
    for(i=1;i<=100;++i)
    {
        int d=V[i].size();
        if(d==1)
        {
            x=V[i][d-1].first;
            y=V[i][d-1].second;
            gr=V[i][d-1].cost;
            salt=i;
            while(x<=y)
            {
                v[x]+=gr;
                x+=salt;
            }
        }
        else if(d>1)
        {
            for(j=0;j<d;++j)
            {
                x=V[i][j].first;
                y=V[i][j].second;
                gr=V[i][j].cost;
                H[x]+=gr;
                H[((y-x)/i+1)*i+x]-=gr;
            }
            for(j=i+1;j<=n;++j)
                H[j]+=H[j-i];
            for(j=1;j<=n;++j)
            {
                v[j]+=H[j];
                H[j]=0;
            }
        }
    }
    for(i=1;i<=n;++i) cout<<v[i]<<" ";
    return 0;
}

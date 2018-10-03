#include<vector>
#include<fstream>
#define Hmmm 30011
#define ll long long
using namespace std;
ifstream f("iepuri2.in");
ofstream g("iepuri2.out");
int n,k;
int lvl[102],drev[102];
ll mat[102][102];
bool isSon[102],isFlower[102];
int dad[102];
vector<int>v[102];
void ftl(int nod)
{
    for(int i=0;i<v[nod].size();++i)
    {
        lvl[v[nod][i]]=lvl[nod]+1;
        ftl(v[nod][i]);
    }
}
void rev_ftl(int nod, int son)
{
    if(nod==0)
        return;
    drev[nod]=max(drev[nod],drev[son]+1);
    rev_ftl(dad[nod],nod);
}
void dfs(int nod)
{
    if(!v[nod].size()){
        for(int i=k;i>=lvl[nod];--i)
            mat[nod][i]=mat[nod][i+1]+1;
        return;
    }
    for(int i=0;i<v[nod].size();++i)
        dfs(v[nod][i]);
    for(int i=k-drev[nod]+1;i>=lvl[nod];--i){
        mat[nod][i]=1;
        for(int j=0;j<v[nod].size();++j)
            mat[nod][i]=(mat[nod][i]*mat[v[nod][j]][i+1])%Hmmm;
        mat[nod][i]=(mat[nod][i]+mat[nod][i+1])%Hmmm;
    }
}
int main()
{
    f>>n>>k;
    for(int i=1;i<n;++i)
    {
        int a,b;
        f>>a>>b;
        dad[b]=a;
        v[a].push_back(b);
        isSon[b]=1;
    }
    int root=0;
    for(int i=1;i<=n;++i)
        if(!isSon[i]){
            lvl[i]=1;
            ftl(i);
            root=i;
            break;
        }
    for(int i=1;i<=n;++i)
        if(!v[i].size())
            rev_ftl(i,0);
    dfs(root);
    g<<mat[root][1];
    return 0;
}

#include<fstream>
#include<cmath>
using namespace std;
ifstream f("countsub.in");
ofstream g("countsub.out");
int val[1002];
int st[1002],dr[1002],m,nod,sol,n;
int dad[1002];
void desc(int tata)
{
    ++sol;
    if(st[tata])
        desc(st[tata]);
    if(dr[tata])
        desc(dr[tata]);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>val[i]>>st[i]>>dr[i];
        if(st[i])
            dad[st[i]]=i;
        if(dr[i])
            dad[dr[i]]=i;
    }
    f>>m;
    for(int i=1;i<=m;++i)
    {
        f>>nod;
        sol=0;
        desc(nod);
        g<<sol<<'\n';
    }
    return 0;
}

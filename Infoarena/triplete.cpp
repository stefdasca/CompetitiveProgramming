#include<bits/stdc++.h>
using namespace std;
ifstream f("triplete.in");
ofstream g("triplete.out");
int n,m;
struct z
{
    int a,b;
};
z a[66002];
bitset<4102>v[4102];
vector<int>q[4102];
int main()
{
    f>>n>>m;
    for(int i=1;i<=m;++i)
    {
        f>>a[i].a>>a[i].b;
        v[a[i].a][a[i].b]=1;
        v[a[i].b][a[i].a]=1;
        q[a[i].a].push_back(a[i].b);
        q[a[i].b].push_back(a[i].a);
    }
    long long sol=0;
    for(int i=1;i<=m;++i)
    {
       for(int j=0;j<q[a[i].a].size();++j)
            if(q[a[i].a][j]!=a[i].b)
                if(v[a[i].a][q[a[i].a][j]]==1 && v[a[i].b][q[a[i].a][j]]==1)
                    ++sol;
    }
    g<<sol/3;
    return 0;
}

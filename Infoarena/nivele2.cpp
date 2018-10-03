#include<bits/stdc++.h>
using namespace std;
ifstream f("nivele2.in");
ofstream g("nivele2.out");
int n;
int a,b;
bool sol[100002];
vector<int>v[100002];
struct coada
{
    int q,lvl;
};
coada z[100002];
int main()
{
    f>>n;
    while(f>>a>>b){
        v[a].push_back(b);
        v[b].push_back(a);
    }
    z[1].q=1;
    z[1].lvl=1;
    sol[1]=1;
    g<<"nivelul "<<1<<": "<<z[1].q;
    int b=1;
    int e=1;
    while(b<=e)
    {
        for(int i=0;i<v[z[b].q].size();++i){
            if(sol[v[z[b].q][i]]==0){
                if(z[e].lvl==z[b].lvl)
                    g<<'\n'<<"nivelul "<<z[b].lvl+1<<": ";
                g<<v[z[b].q][i]<<" ";
                ++e;
                z[e].lvl=z[b].lvl+1;
                z[e].q=v[z[b].q][i];
                sol[v[z[b].q][i]]=1;
            }
        }
        ++b;
    }
    return 0;
}

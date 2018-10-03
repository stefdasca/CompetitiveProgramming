#include<bits/stdc++.h>
using namespace std;
ifstream f("liste.in");
ofstream g("liste.out");
int n,nr,x;
struct stacks
{
    bitset<122>v;
};
stacks v[100002];
int main()
{
    f>>n;
    f>>nr;
    for(int i=1;i<=nr;++i)
    {
        f>>x;
        v[1].v[x]=1;
    }
    int lstck=1;
    for(int i=2;i<=n;++i)
    {
        f>>nr;
        ++lstck;
        for(int j=0;j<=120;++j)
            v[lstck].v[j]=0;
        for(int j=1;j<=nr;++j)
            f>>x,v[lstck].v[x]=1;
        do{
            bool ok=0;
            for(int a=0;a<=120;++a)
                if(v[lstck].v[a]==1 && v[lstck-1].v[a]==1)
                {
                    ok=1;
                    break;
                }
            if(ok==1){
                --lstck;
                for(int a=0;a<=120;++a)
                    v[lstck].v[a]=max(v[lstck].v[a],v[lstck+1].v[a]);
            }
            else
                break;
        }while(lstck>1);
    }
    g<<lstck;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("risipa.in");
ofstream g("risipa.out");
int A,B;
char c[102];
struct vals
{
    int v[102],l;
};
vals v[30002];
int nd=1;
int vv[102];
int find_the_rest()
{
    for(int i=0;i<v[nd].l;++i)
        vv[i]=v[nd].v[i];
    for(int j=v[nd].l-1;j>=0;--j){
        if(j==0)
            return vv[j]%3;
        vv[j-1]+=(vv[j]%3)*10;
    }
}
bool comp(int sa, int sb)
{
    if(v[sa].l!=v[sb].l)
        return 0;
    else
        for(int i=v[sa].l-1;i>=0;--i)
            if(v[sa].v[i]!=v[sb].v[i])
                return 0;
    return 1;
}
void Sim()
{
    bool ok=1;
    while(ok){
        ++nd;
        for(int i=0;i<v[nd-1].l;++i)
            v[nd].v[i]=v[nd-1].v[i];
        v[nd].l=v[nd-1].l;
        int nr=find_the_rest();
        if(nr==0)
            for(int j=v[nd].l-1;j>=0;--j)
            {
                if(j)
                    v[nd].v[j-1]+=(v[nd].v[j]%3)*10;
                v[nd].v[j]/=3;
                if(j==v[nd].l-1 && v[nd].v[j]==0)
                    --v[nd].l;
            }
        else
            if(nr==1)
                v[nd].v[0]+=A;
            else
                v[nd].v[0]+=B;
        for(int j=0;j<v[nd].l;++j)
            if(v[nd].v[j]>9)
            {
                v[nd].v[j+1]+=v[nd].v[j]/10;
                v[nd].v[j]%=10;
                if(j==v[nd].l-1)
                    ++v[nd].l;
            }
        ok=0;
        for(int i=1;i<nd;++i)
            if(comp(i,nd)==1)
            {
                for(int j=v[nd].l-1;j>=0;--j)
                    g<<v[nd].v[j];
                g<<'\n';
                g<<i<<" "<<nd<<'\n';
                ok=1;
                break;
            }
        ok=1-ok;
    }
}
int main()
{
    f>>c;
    f>>A>>B;
    A=A*3+2;
    B=B*3+1;
    reverse(c,c+strlen(c));
    for(int i=strlen(c)-1;i>=0;--i)
        v[nd].v[i]=c[i]-'0';
    v[nd].l=strlen(c);
    Sim();
    return 0;
}

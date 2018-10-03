#include<bits/stdc++.h>
using namespace std;
ifstream f("dinti.in");
ofstream g("dinti.out");
int n,m,l;
char c1[1000002];
char c2[25];
int p2[25],nr;
deque<char>d;
bool gut[(1<<20)+1];
int main()
{
    f>>n>>m>>l;
    f>>c1;
    for(int i=0;i<l;++i)
        p2[i]=(1<<i);
    for(int i=0;i<=n-l;++i)
    {
        if(i==0)
            for(int j=0;j<l;++j)
                d.push_back(c1[j]),nr+=p2[l-j-1]*(c1[j]=='1');
        else{
            nr-=nr&p2[l-1];
            nr<<=1;
            nr+=(c1[i+l-1]=='1');
            d.pop_front(),d.push_back(c1[i+l-1]);
        }
        gut[(1<<l)-1-nr]=1;
    }
    for(int i=(1<<l)-1;i>0;--i)
        if(gut[i])
            for(int k=0;k<l;++k)
                if(i&p2[k])
                    gut[i-p2[k]]=1;
    for(int i=1;i<=m;++i)
    {
        f>>c2;
        nr=0;
        for(int j=0;j<l;++j)
            nr+=p2[l-j-1]*(c2[j]=='1');
        g<<gut[nr]<<'\n';
    }
    return 0;
}

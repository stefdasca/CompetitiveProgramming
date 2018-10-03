#include<bits/stdc++.h>
using namespace std;
ifstream f("licenta.in");
ofstream g("licenta.out");
int k,n,m;
struct s
{
    int st,sf;
};
s v[100002];
s v1[100002];
bool test(s a, s b)
{
    return a.st<b.st;
}
int main()
{
    f>>k;
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].st>>v[i].sf;
    f>>m;
    for(int i=1;i<=m;++i)
        f>>v1[i].st>>v1[i].sf;
    sort(v+1,v+n+1,test);
    sort(v1+1,v1+m+1,test);
    int a=1;
    int b=1;
    while(a<=n && b<=m)
    {
        while(v1[b].st<=v[a].sf)
        {
            int si=max(v[a].st,v1[b].st);
            int sfi=min(v[a].sf,v1[b].sf);
            if(sfi-si>=k){
                g<<si<<" "<<si+k<<'\n';
                return 0;
            }
            ++b;
        }
        ++a;
    }
    g<<-1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("dictree.in");
ofstream g("dictree.out");
int n,sol=1;
struct vc
{
    char c[102];
};
vc v[25002];
bool test(vc a, vc b)
{
    return strcmp(a.c,b.c)<0;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i].c;
    sort(v+1,v+n+1,test);
    sol+=strlen(v[1].c);
    for(int i=2;i<=n;++i)
    {
        int L=strlen(v[i].c);
        int eq=1;
        for(int j=0;j<L;++j)
        {
            if(v[i-1].c[j]!=v[i].c[j])
                eq=0;
            sol+=1-eq;
        }
    }
    g<<sol;
    return 0;
}

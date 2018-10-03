#include<bits/stdc++.h>
using namespace std;
ifstream f("restante.in");
ofstream g("restante.out");
int n,fr[27],sol;
char c1[17];
struct prm
{
    char q[40];
};
prm v[36002];
bool test(prm a, prm b)
{
    return strcmp(a.q, b.q)<0;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>c1;
        sort(c1,c1+strlen(c1));
        strcpy(v[i].q,c1);
    }
    sort(v+1,v+n+1,test);
    for(int i=2;i<n;++i)
        if(strcmp(v[i].q,v[i+1].q)!=0 && strcmp(v[i].q,v[i-1].q)!=0)
            ++sol;
    if(strcmp(v[1].q,v[2].q)!=0)
        ++sol;
    if(strcmp(v[n-1].q,v[n].q)!=0)
        ++sol;
    g<<sol;
    return 0;
}

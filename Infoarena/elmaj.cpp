#include<bits/stdc++.h>
using namespace std;
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int n;
int v[1000002];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    nth_element(v+1,v+n/2+1,v+n+1);
    int nr=v[n/2+1];
    int fr=0;
    for(int i=1;i<=n;++i)
        if(v[i]==nr)
            ++fr;
    if(fr>=n/2+1)
        g<<nr<<" "<<fr;
    else
        g<<-1;
}

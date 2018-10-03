#include<bits/stdc++.h>
using namespace std;
ifstream f("secv7.in");
ofstream g("secv7.out");
int n;
int v[30001];
int st[30001],dr[30001];
int main()
{
    f>>n;
    int pmax1=0,max1=-100020;
    for(int i=1;i<=n;++i){
        f>>v[i];
        if(v[i]>max1)
            max1=v[i],pmax1=v[i];
    }
    st[0]=-204022;
    dr[n+1]=-204204;
    for(int i=1;i<=n;++i)
        st[i]=max(st[i-1],v[i]);
    for(int i=n;i>=1;--i)
        dr[i]=max(dr[i+1],v[i]);
    // caz 1 : max e in secv de mijloc
    int sol=st[1]+dr[n]+max1;
    int pst=1;
    int pdr=n-1;
    // caz 2 : max e in secv din stanga
    for(int j=2;j<n;++j)
        if(st[j-1]+v[j]+dr[j+1]<sol)
            sol=st[j-1]+v[j]+dr[j+1],pst=j-1,pdr=j;
    g<<sol<<'\n';
    g<<pst<<" "<<pdr<<'\n';
    return 0;
}

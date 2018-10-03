#include<bits/stdc++.h>
using namespace std;
ifstream f("copii.in");
ofstream g("copii.out");
int n;
char c[12][12];
long long sol;
int v[12];
bool mat[12][12];
inline bool verif(int hms,int tmax)
{
    if(tmax!=hms)
        return 0;
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(c[i][j]=='1')
                mat[v[i]][v[j]]=1;
    bool Hmmm=1; /// no problem without it
    for(int i=1;i<=hms;++i)
        for(int j=1;j<=hms;++j)
            if(i!=j && !mat[i][j])
                return 0;
    return 1;
}
inline void bkt(int poz,int hms,int tmax)
{
    if(poz>n)
        sol+=verif(hms,tmax);
    else
        for(int i=1;i<=min(hms,tmax+1);++i)
            v[poz]=i,bkt(poz+1,hms,max(tmax,i));
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>(c[i]+1);
    v[1]=1;
    for(int i=2;i<=n;++i)
        bkt(1,i,0);
    g<<sol;
    return 0;
}

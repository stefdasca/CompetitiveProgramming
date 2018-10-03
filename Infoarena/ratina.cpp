#include <bits/stdc++.h>
#define PRIMMAX 123457
#define NMAX 10005
#define CUVMAX 2005
using namespace std;
char cuv[CUVMAX];
int n,query,k;
int L[NMAX][CUVMAX];
short a[NMAX],lug[NMAX],dmin;
ifstream fin("ratina.in");
ofstream fout("ratina.out");
inline bool CHECK(int poz)
{
    int x;
    for(int i=1;i<=k;i++)
    {
        x=a[i];
        if(L[a[1]][poz]!=L[x][poz])
            return false;
    }
    return true;
}
inline void CB()
{
    int st=1,dr=dmin,poz=0,mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(CHECK(mij))
        {
            poz=mij;
            st=mij+1;
        }
        else dr=mij-1;
    }
    fout<<poz<<"\n";
}
int main()
{
    int x;
    fin>>n>>query;
    for(int i=1;i<=n;i++)
    {
        fin>>(cuv+1);
        lug[i]=strlen(cuv+1);
        for(int j=1;j<=lug[i];j++)
            L[i][j]=(1LL*L[i][j-1]*26+(cuv[j]-'a'+1))%PRIMMAX;
    }
    while(query--)
    {
        fin>>k;
        dmin=CUVMAX;
        for(int i=1;i<=k;i++)
        {
            fin>>a[i];
            x=a[i];
            dmin=min(dmin,lug[x]);
        }
        CB();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream in("startrek.in");
ofstream out("startrek.out");
int n,minpas,maxpas,m;
int sect[100100],anmax[100100],anmin[100100],nr=1,k;
int main()
{
    in>>n>>minpas>>maxpas>>m;
    for(int i=1; i<=m; ++i)
    {
        int x, y;
        in>>x>>y;
        sect[x]=y;
        anmax[y]=x;
        if(anmin[y]==0)
            anmin[y]=x;
    }
    for(int i=1; i<=n; ++i)
        if(anmin[i]==0)
            anmin[i]=100005;
    for(int i=1; i<=n; ++i)
        if(sect[i]==nr+1)
            nr++, k=1;
        else
        {
            sect[i]=nr;
            k++;
            if(k>=minpas && i>=anmax[nr])
                nr++, k=0;
        }
    if(k<minpas)
        nr--;
    k=min(n-minpas+1,anmin[nr]);
    for(int i=n; i>=1; --i)
    {
        sect[i]=nr;
        if(i==k)
            nr--, k=min(i-minpas,anmin[nr]);
    }
    k=0, nr=1;
    for(int i=1; i<=n; ++i)
        if(sect[i]==nr+1)
            nr++, k=1;
        else
        {
            sect[i]=nr;
            k++;
            if(k==maxpas)
                nr++,k=0;
        }
    out<<sect[n]<<'\n';
    for(int i=1; i<=n; ++i)
        out<<sect[i]<<' ';
    return 0;
}

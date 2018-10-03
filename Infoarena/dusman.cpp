#include<bits/stdc++.h>
using namespace std;
ifstream f("dusman.in");
ofstream g("dusman.out");
int n,k,d;
bool mat[1002][1002];
int v[1002];
bool z[1002];
void bkt(int r)
{
    if(r==n+1){
        --k;
        return;
    }
    else
        for(int i=1;i<=n && k;++i)
            if(z[i]==0 && mat[i][v[r-1]]==0){
                v[r]=i;
                z[i] =1;
                bkt(r+1);
                z[i]=0;
            }
}
int main()
{
    f>>n>>k>>d;
    int a,b;
    for(int i=1;i<=d;++i)
        f>>a>>b,mat[a][b]=1,mat[b][a]=1;
    bkt(1);
    for(int i=1;i<=n;++i)
        g<<v[i]<<" ";
    return 0;
}

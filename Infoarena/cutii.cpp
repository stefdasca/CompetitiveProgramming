/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
#define maxb 3502
using namespace std;
ifstream f("cutii.in");
ofstream g("cutii.out");
int T,n;
struct arr
{
    int x,y,z;
};
arr v[maxb];
int aib[maxb][maxb];
bool test(arr a, arr b)
{
    return a.x<b.x;
}
int getmax(int L, int C)
{
    int max1=0;
    for(int i=L;i;i-=(i&(-i)))
        for(int j=C;j;j-=(j&(-j)))
            max1=max(max1,aib[i][j]);
    return max1;
}
void update(int L, int C,int val)
{
    for(int i=L;i<=n;i+=(i&(-i)))
        for(int j=C;j<=n;j+=(j&(-j)))
            aib[i][j]=max(aib[i][j],val);
}
int main()
{
    f>>n>>T;
    for(;T;--T)
    {
        for(int i=1;i<=n;++i)
            f>>v[i].x>>v[i].y>>v[i].z;
        sort(v+1,v+n+1,test);
        int sol=0;
        for(int i=1;i<=n;++i)
        {
            int Q=getmax(v[i].y,v[i].z)+1;
            update(v[i].y,v[i].z,Q);
            sol=max(sol,Q);
        }
        for(int i=1;i<=n;++i)
            for(int j=v[i].y;j<=n;j+=(j&(-j)))
                for(int k=v[i].z;k<=n;k+=(k&(-k)))
                    aib[j][k]=0;
        g<<sol<<'\n';
    }
    return 0;
}

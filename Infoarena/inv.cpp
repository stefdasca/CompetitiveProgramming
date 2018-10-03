#include<bits/stdc++.h>
using namespace std;
ifstream f("inv.in");
ofstream g("inv.out");
int n,v[100002],vs[100002],nri;
int AIB[100002];
void update(int s)
{
    for(int i=s;i<=n;i+=(i&(-i)))
        AIB[i]++;
}
int calc(int s)
{
    int sol=0;
    for(int i=s;i;i-=(i&(-i)))
        sol+=AIB[i];
    return sol;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],vs[i]=v[i];
    sort(vs+1,vs+n+1);
    for(int i=1;i<=n;++i)
    {
        int b=1;
        int e=n;
        int q=0;
        while(b<=e)
        {
            int m=(b+e)/2;
            if(vs[m]==v[i]){
                q=m;
                break;
            }
            else
                if(vs[m]<v[i])
                    b=m+1;
                else
                    e=m-1;
        }
        while(vs[q-1]==vs[q])
            --q;
        nri+=q-calc(q-1)-1;
        nri%=9917;
        update(q);
    }
    g<<nri<<'\n';
    return 0;
}

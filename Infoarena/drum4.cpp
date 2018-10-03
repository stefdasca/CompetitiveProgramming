#include<bits/stdc++.h>
using namespace std;
ifstream f("drum4.in");
ofstream g("drum4.out");
int x[100001],y[100002],n,k;
int main()
{
    f>>n>>k;
    int a=n;
    int b=n;
    for(int i=1;i<=k;++i)
    {
        int p,q;
        f>>p>>q;
        x[p]=y[q]=1;
    }
    for(int i=1;i<=n;++i)
        a-=x[i],b-=y[i];
    g<<max(a,b);
    return 0;
}

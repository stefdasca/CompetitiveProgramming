#include<bits/stdc++.h>
using namespace std;
ifstream f("cocochanel.in");
ofstream g("cocochanel.out");
int n,m;
int v1[100002],v2[100002];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v1[i];
    for(int j=1;j<=m;++j)
        f>>v2[j];
    sort(v2+1,v2+m+1);
    for(int i=1;i<=n;++i)
    {
        int b=1;
        int e=m;
        int sol=0;
        while(b<=m)
        {
            int e=m;
            while(b<=e)
            {
                int hf=(b+e)/2;
                if(v2[hf]>=v1[i] && (v2[hf-1]<v1[i] || hf==b)){
                    b=hf+1;
                    ++sol;
                    v1[i]+=v1[i];
                    break;
                }
                else
                    if(v2[hf]<v1[i])
                        b=hf+1;
                    else
                        e=hf-1;
            }
        }
        g<<sol<<'\n';
    }
    return 0;
}

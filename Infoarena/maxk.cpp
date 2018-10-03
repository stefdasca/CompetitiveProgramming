#include<bits/stdc++.h>
using namespace std;
ifstream f("maxk.in");
ofstream g("maxk.out");
int v1[1000002],v2[100002],ok;
int max1,k,n;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i){
        f>>v1[i];
        v2[v1[i]]++;
    }
    for(int i=1;i<=100000;++i)
        if(v2[i]>k)
            ++ok;
    int lmin=n+1;
    int s=1;
    int e=1;
    while(s<=e && e<=n)
        if(ok)
            do
            {
                --v2[v1[e]];
                if(v2[v1[e]]==k)
                    --ok;
                ++e;
            }while(ok && e<=n);
        else
            do{
                lmin=min(lmin,e-s);
                if(s<e)
                {
                    ++v2[v1[s]];
                    if(v2[v1[s]]>k)
                        ++ok;
                    ++s;
                }
                else
                    if(ok==0 && s==e){
                        lmin=0;++s;break;}
            }while(ok==0);
    g<<lmin;
    return 0;
}

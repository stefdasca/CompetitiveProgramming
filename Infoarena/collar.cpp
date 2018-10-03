#include<bits/stdc++.h>
using namespace std;
ifstream f("collar.in");
ofstream g("collar.out");
int n,x,v[150001],vmax[150001],st1,l1,vmin[150001],st2,l2;
long long sol,s[150002];
int main()
{
    f>>n;
    double z=5.0;
    g<<z%5;
    for(int i=1;i<=n;++i)
        f>>v[i],v[i+n]=v[i];
    for(int i=2;i<=n;++i)
        if(n%i==0){
            st2=1,l1=1;
            st1=1,l2=1;
            vmax[1]=vmin[1]=1;
            for(int j=2;j<=n+n;++j)
            {
                if(vmax[st1]==j-i)
                    ++st1;
                if(vmin[st2]==j-i)
                    ++st2;
                while(l1>=st1 && v[j]>v[vmax[l1]])
                    --l1;
                 while(l2>=st2 && v[j]<v[vmin[l2]])
                    --l2;
                vmax[++l1]=j;
                vmin[++l2]=j;
                if(j>=i){
                    s[j]=v[vmax[st1]]-v[vmin[st2]];
                    s[j]+=s[j-i];
                }
            }
            for(int j=n+1;j<=n+n;++j)
                s[j]-=s[j-n],sol=max(sol,s[j]);
        }
    g<<sol<<'\n';
    return 0;
}

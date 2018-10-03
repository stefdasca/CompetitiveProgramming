#include<bits/stdc++.h>
using namespace std;
ifstream f("multimi2.in");
ofstream g("multimi2.out");
int n;
int l0,v[500002];
int l1,v1[500002];
int main()
{
    f>>n;
    if(n%2==0)
        if(n==2)
            g<<1<<'\n'<<1<<'\n'<<1<<'\n'<<1<<'\n'<<2<<'\n';
        else{
            for(int i=1;i<=n/2;++i)
                if(i&1)
                    v[l0+1]=i,v[l0+2]=n-i+1,l0+=2;
                else
                    v1[l1+1]=i,v1[l1+2]=n-i+1,l1+=2;
            if((n/2)%2==1)
            {
                g<<1<<'\n';
                g<<l0-1<<'\n';
                for(int i=1;i<l0;++i)
                    g<<v[i]<<" ";
                g<<'\n'<<l1+1<<'\n';
                for(int i=1;i<=l1;++i)
                    g<<v1[i]<<" ";
                g<<n/2+1;
            }
            else
            {
                g<<0<<'\n';
                g<<l0<<'\n';
                for(int i=1;i<=l0;++i)
                    g<<v[i]<<" ";
                g<<'\n'<<l1<<'\n';
                for(int i=1;i<=l1;++i)
                    g<<v1[i]<<" ";
            }
        }
    else
        if(n==3)
            g<<1<<'\n'<<1<<'\n'<<3<<'\n'<<2<<'\n'<<"1 2"<<'\n';
        else{
            for(int i=1;i<=n/2;++i)
                if(i&1)
                    v[l0+1]=i,v[l0+2]=n-i,l0+=2;
                else
                    v1[l1+1]=i,v1[l1+2]=n-i,l1+=2;
            if((n/2)%2==1)
                {
                g<<0<<'\n';
                g<<l0<<'\n';
                for(int i=1;i<=l0;++i)
                    g<<v[i]<<" ";
                g<<'\n'<<l1+1<<'\n';
                for(int i=1;i<=l1;++i)
                    g<<v1[i]<<" ";
                g<<n;
            }
            else
            {
                g<<1<<'\n';
                g<<l0+1<<'\n';
                for(int i=1;i<=l0;++i)
                    g<<v[i]<<" ";
                g<<n/2<<'\n'<<l1<<'\n';
                for(int i=1;i<=l1;++i)
                    if(v1[i]!=n/2)
                        g<<v1[i]<<" ";
                g<<n<<'\n';
            }
        }
    return 0;
}

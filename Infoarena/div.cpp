#include<bits/stdc++.h>
using namespace std;
ifstream f("div.in");
ofstream g("div.out");
int m,d,b,e;
char c[5002];
int v[5002],vmax[5002];
int p[5002],u[5002],z[5002];
int main()
{
    f>>m;
    f.get();
    f>>c;
    int l=strlen(c);
    for(int i=0;i<l;++i)
        v[i+1]=c[i]-'0';
    p[1]=v[1]%m;
    for(int i=2;i<=l;++i)
        p[i]=(p[i-1]*10+v[i])%m;
    z[0]=1;
    for(int i=1;i<=l;++i)
        z[i]=(z[i-1]*10)%m;
    u[l]=v[l]%m;
    for(int i=l-1;i>=1;--i)
        u[i]=(u[i+1]+z[l-i]*v[i])%m;
    if(p[l]==0)
        g<<0<<" "<<0<<'\n';
    else
        for(int i=1;i<=l;++i)
        {
            int ok=0;
            int s=0;
            int e=0;
            for(int j=1;j<=l-i+1;++j)
                if((v[j+i]==0 && j==1) && j+i<=l);
                else
                if((p[j-1]*z[l-j-i+1]+u[j+i])%m==0)
                    if(ok==0)
                    {
                        for(int q=1;q<j;++q)
                            vmax[q]=v[q];
                        for(int q=j+i;q<=l;++q)
                            vmax[q-i]=v[q];
                        s=j;
                        ok=1;
                        e=j+i-1;
                    }
                    else
                    {
                        int cmp=0;
                        for(int q=1;q<j && !cmp;++q)
                        {
                            if(vmax[q]>v[q])
                                cmp=1;
                            if(vmax[q]<v[q])
                                cmp=-1;
                        }
                        for(int q=j+i;q<=l && !cmp;++q)
                        {
                            if(vmax[q-i]>v[q])
                                cmp=1;
                            if(vmax[q-i]<v[q])
                                cmp=-1;
                        }
                        if(cmp==-1)
                        {
                            for(int q=1;q<j;++q)
                                vmax[q]=v[q];
                            for(int q=j+i;q<=l;++q)
                                vmax[q]=v[q];
                            s=j;
                            e=j+i-1;
                        }
                    }
        if(ok==1)
        {
            g<<s<<" "<<e;
            break;
        }
    }
    return 0;
}

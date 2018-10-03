/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("triti2.in");
ofstream g("triti2.out");
int k,v[1002],len,sz,sum[1002];
char c[1002];
struct hm
{
    int a[202],b[202],c[202];
    int lena,lenb,lenc;
};
hm v2[1002];
void init()
{
    v2[k].b[1]=v2[k].c[1]=v2[k].lenb=v2[k].lenc=1;
    if(k>1)
    {
        v2[k].lena=1;
        v2[k].a[1]=1;
    }
}
void total()
{
    for(int j=v2[1].lenb;j>=1;--j)
        sum[j]+=v2[1].b[j];
    for(int j=v2[1].lenc;j>=1;--j)
        sum[j]+=v2[1].c[j];
    len=max(v2[1].lenb,v2[1].lenc);
}
void buildsols()
{
    for(int i=k;i>1;--i)
    {
        for(int j=1;j<=v2[i].lena;++j)
            v2[i-1].b[j]+=v2[i].a[j];
        v2[i-1].lenb=max(v2[i-1].lenb,v2[i].lena);
        for(int j=1;j<=v2[i].lenc;++j)
            v2[i-1].b[j]+=v2[i].c[j];
        v2[i-1].lenb=max(v2[i-1].lenb,v2[i].lenc);
        if(i>2)
        {
            for(int j=1;j<=v2[i].lenb;++j)
                v2[i-1].a[j]+=v2[i].b[j];
            v2[i-1].lena=max(v2[i-1].lena,v2[i].lenb);
        }
        for(int j=1;j<=v2[i].lenb;++j)
            v2[i-1].c[j]+=v2[i].b[j];
        v2[i-1].lenc=max(v2[i-1].lenb,v2[i].lenb);
        for(int j=1;j<=v2[i-1].lena;++j)
            if(v2[i-1].a[j]>=10)
            {
                v2[i-1].a[j+1]+=v2[i-1].a[j]/10;
                v2[i-1].a[j]%=10;
                if(j==v2[i-1].lena)
                    ++v2[i-1].lena;
            }
        for(int j=1;j<=v2[i-1].lenb;++j)
            if(v2[i-1].b[j]>=10)
            {
                v2[i-1].b[j+1]+=v2[i-1].b[j]/10;
                v2[i-1].b[j]%=10;
                if(j==v2[i-1].lenb)
                    ++v2[i-1].lenb;
            }
        for(int j=1;j<=v2[i-1].lenc;++j)
            if(v2[i-1].c[j]>=10)
            {
                v2[i-1].c[j+1]+=v2[i-1].c[j]/10;
                v2[i-1].c[j]%=10;
                if(j==v2[i-1].lenc)
                    ++v2[i-1].lenc;
            }
    }
    total();
    for(int j=1;j<=len;++j)
        if(sum[j]>=10)
        {
            sum[j+1]+=sum[j]/10;
            sum[j]%=10;
            if(j==len)
                ++len;
        }
}
int cmp(int a[],int m,int b[],int n)
{
    if(m>n)
        return 1;
    if(n>m)
        return -1;
    for(int j=n;j>=1;--j)
        if(a[j]>b[j])
            return 1;
        else
            if(a[j]<b[j])
                return -1;
    return 0;
}
void sc(int a[],int &m, int b[],int n) /// a-b
{
    for(int i=1;i<=n;++i){
        a[i]-=b[i];
        if(a[i]<0)
            --a[i+1],a[i]+=10;
    }
    while(a[m]==0)
        --m;
}
int precdigit;
void init2()
{
    if(cmp(v,sz,v2[1].b,v2[1].lenb)==1)
        sc(v,sz,v2[1].b,v2[1].lenb),precdigit=2;
    else
        precdigit=1;
}
int main()
{
    f>>k>>c+1;
    sz=strlen(c+1);
    for(int i=1;i<=sz;++i)
        v[sz-i+1]=c[i]-'0';
    init();
    buildsols();
    if(cmp(sum,len,v,sz)==-1){
        g<<-1;
        return 0;
    }
    init2();
    g<<precdigit;
    for(int i=2;i<=k;++i)
    {
        if(precdigit==0)
            g<<1,precdigit=1;
        else
            if(precdigit==2)
                g<<1,precdigit=1;
            else
                if(cmp(v,sz,v2[i].a,v2[i].lena)==1)
                    sc(v,sz,v2[i].a,v2[i].lena),g<<2,precdigit=2;
                else
                    g<<0,precdigit=0;
    }
    g<<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("free.in");
ofstream g("free.out");
char si[102];
int vi[302],b[302],m[302],e[302],l;
int lb=1,le,lm;
int cmp(int b[],int e[],int lb,int le);
int prd(int x[])
{
    int x1[202];
    for(int i=1;i<=lm;++i)
        x1[i]=x[i];
    x1[lm+1]=0;
    x1[1]++;
    int q=1;
    while(x1[q]>9)
        x1[q]-=10,++q,x1[q]++;
    int lm1=lm+(x1[lm+1]>0);
    int p1[402],p2[402];
    for(int i=1;i<=400;++i)
        p1[i]=p2[i]=0;
    for(int i=1;i<=lm;++i)
        for(int j=1;j<=lm;++j)
            p1[i+j-1]+=x[i]*x[j];
    int z=lm*2;
    for(int i=1;i<=z;++i)
        if(p1[i]>9){
            p1[i+1]+=p1[i]/10,p1[i]%=10;
            if(p1[z+1]>0)
                ++z;
        }
     for(int i=1;i<=lm1;++i)
        for(int j=1;j<=lm1;++j)
            p2[i+j-1]+=x1[i]*x1[j];
    z=lm1*2;
    for(int i=1;i<=z;++i)
        if(p2[i]>9){
            p2[i+1]+=p2[i]/10,p2[i]%=10;
            if(p2[z+1])
                ++z;
        }
    int Lt=lm*2;
    while(p1[Lt]==0)
        --Lt;
    int Lt1=lm*2;
    while(p2[Lt1]==0)
        --Lt1;
    int nr=cmp(p1,vi,Lt,l);
    int nr1=cmp(p2,vi,Lt1,l);
    if(nr<=0 && nr1>0)
        return 0;
    else
        if(nr>0)
            return 1;
        else
            return -1;
}
void ad(int b[],int m[],int e[])
{
    for(int i=1;i<=le;++i)
        m[i]=b[i]+e[i];
    lm=le;
    for(int i=1;i<=lm;++i)
    {
        if(m[i]>9)
        {
            m[i+1]++;
            m[i]-=10;
            if(m[le+1]>0)
                ++lm;
        }
    }
    for(int i=lm;i>=1;--i){
        m[i-1]+=(m[i]%2!=0)*10;
        m[i]/=2;
    }
    while(m[lm]==0)
        --lm;
}
int cmp(int b[],int e[],int lb,int le)
{
    if(lb>le)
        return 1;
   if(le>lb)
        return -1;
    for(int i=lb;i>=1;--i){
        if(b[i]>e[i])
            return 1;
        if(e[i]>b[i])
            return -1;
    }
    return 0;
}
void CautBin(int b[],int m[],int e[])
{
    while(cmp(b,e,lb,le)<=0)
    {
        ad(b,m,e);
        int q=prd(m);
        if(q==0)
            break;
        else
            if(q==-1)
            {
               for(int i=1;i<=lm;++i)
                  b[i]=m[i];
               b[1]++;
               int q=1;
               while(b[q]>9)
               {
                   b[q+1]++;
                   b[q]-=10;
                   ++q;
               }
               lb=lm+(b[lm+1]>0);
            }
            else
                if(q==1)
                {
                    for(int i=1;i<=lm;++i)
                        e[i]=m[i];
                    e[1]--;
                    int q=1;
                    while(e[q]<0)
                    {
                       e[q+1]--;
                       e[q]+=10;
                       ++q;
                    }
                    le=lm-(!e[lm]);
                }
    }
}
int main()
{
    f>>si+1;
    l=strlen(si+1);
    for(int i=l;i>=1;--i)
        vi[l-i+1]=si[i]-'0',e[l-i+1]=si[i]-'0';
    lb=1;
    le=l;
    b[1]=1;
    CautBin(b,m,e);
    for(int i=1;i<=l;++i){
        vi[i]-=m[i];
        if(vi[i]<0){
            int fa=-vi[i]/10;
            if((-vi[i])%10)
                ++fa;
            vi[i]+=10*fa,vi[i+1]-=fa;
        }
    }
    bool ok=0;
    for(int i=l;i>=1;--i)
        if(vi[i]>0 || ok==1)
            g<<vi[i],ok=1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("koba.in");
ofstream g("koba.out");
int n,a,b,c,a1,b1,c1,sol,d1,d,sp[13*13*13];
int mat[12][12][12],fa[12][12][12];
int mb(int a,int b,int c)
{
    int ss=a+b+c;
    for(int i=4;i<=n;++i)
    {
        d=(c+a*b)%10;
        a=b;
        b=c;
        c=d;
        ss+=d;
    }
    g<<ss<<'\n';
}
int main()
{
    f>>n>>a>>b>>c;
    a%=10;
    b%=10;
    c%=10;
    a1=a;
    b1=b;
    c1=c;
  //  mb(a,b,c);
    int q=4;
    bool ok=1;
    while(ok && q<=n)
    {
        d=(c+a*b)%10;
        if(mat[d][c][b]==0)
            mat[d][c][b]=1,fa[d][c][b]=q;
        else{
            ok=0;break;
        }
        ++q;
        a=b;
        b=c;
        c=d;
    }
    if(ok==1){
        sol+=a1+b1+c1;
        for(int i=4;i<=n;++i){
            d1=(c1+a1*b1)%10;
            a1=b1;
            b1=c1;
            c1=d1;
            sol+=d1;
        }
        g<<sol;
    }
    else
    {
        fa[d][c][b]-=2;
        q-=2;
        if(fa[d][c][b]==3)
            sol+=a1+b1;
        else
            if(fa[d][c][b]==2)
                sol+=a1;
            else
                if(fa[d][c][b]>=4){
                    sol+=a1+b1+c1;
                    for(int i=4;i<fa[d][c][b];++i)
                    {
                        d1=(c1+a1*b1)%10;
                        a1=b1;
                        b1=c1;
                        c1=d1;
                        sol+=d1;
                    }
                }
        int r=0;
        if(fa[d][c][b]==1)
        {
            sp[1]=a1;
            sp[2]=a1+b1;
            sp[3]=a1+b1+c1;
            r=3;
        }
        else
            if(fa[d][c][b]==2)
            {
                sp[1]=b1;
                sp[2]=c1+b1;
                r=2;
            }
            else
                if(fa[d][c][b]==3)
                    sp[1]=c1,r=1;
        for(int i=fa[d][c][b];i<q;++i)
        {
            d1=(c1+a1*b1)%10;
            a1=b1;
            b1=c1;
            c1=d1;
            ++r;
            sp[r]=sp[r-1]+d1;
        }
        q-=fa[d][c][b];
        while(fa[d][c][b]+q<=n)
            sol+=sp[q],fa[d][c][b]+=q;
        sol+=sp[n-fa[d][c][b]+1];
        g<<sol;
    }
    return 0;
}

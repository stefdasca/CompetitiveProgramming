/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("cifre.in");
ofstream g("cifre.out");
int a,b,c,k,xa,xb;
int hm[12];
void memo()
{
    for(int i=1000000;i<=1999999;++i)
    {
        int q=i;
        int fr=0;
        while(q>1)
        {
            fr=fr+(q%10==c);
            q/=10;
        }
        hm[fr]++;
    }
}
int main()
{
    f>>a>>b>>c>>k;
    xb=b-a+1;
    memo();
    for(int i=a;i<min((a/1000000)*1000000+1000000*(a%1000000!=0),b+1);++i)
    {
        int q=i;
        int fr=0;
        while(q)
        {
            fr=fr+(q%10==c);
            q/=10;
        }
        if(fr>=k)
            ++xa;
    }
    a=min((a/1000000)*1000000+1000000*(a%1000000!=0),b+1);
    if(a<b)
    {
        for(int i=(a/1000000)+(a%1000000!=0);i<(b/1000000)+(b%1000000==999999);++i)
        {
            int q=i;
            int fr=0;
            while(q)
            {
                fr=fr+(q%10==c);
                q/=10;
            }
            for(int j=0;j<=9;++j)
                if(fr+j>=k)
                    xa+=hm[j];
        }
        for(int i=(b/1000000+(b%1000000==999999))*1000000;i<=b;++i)
        {
            int q=i;
            int fr=0;
            while(q)
            {
                fr=fr+(q%10==c);
                q/=10;
            }
            if(fr>=k)
                ++xa;
        }
    }
    double sol=(xa+0.0)/(xb+0.0);
    g<<fixed<<setprecision(4)<<sol;
    return 0;
}

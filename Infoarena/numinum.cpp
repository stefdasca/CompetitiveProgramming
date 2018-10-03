#include<bits/stdc++.h>
using namespace std;
ifstream f("numinum.in");
ofstream g("numinum.out");
int t,a,b,c,d;
int nrs(int a, int b)
{
    int sol=0;
    while(a!=1 || b!=1)
    {
        if(a>b)
        {
            if(b==1)
                a=1;
            else
                a%=b;
        }
        else
        {
            if(a==1)
                b=1;
            else
                b%=a;
        }
        ++sol;
    }
    return sol;
}
int nxt(int x, int y)
{
    if(x<y)
        return x;
    return x%y+(y==1);
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>a>>b>>c>>d;
        int x=nrs(a,b);
        int y=nrs(c,d);
        int sol=0;
        if(a==c && (max(b,d)-min(b,d))%a==0)
        {
            g<<(max(b,d)-min(b,d))/a<<'\n';
            continue;
        }
        if(b==d && (max(a,c)-min(a,c))%b==0)
        {
            g<<(max(a,c)-min(a,c))/b<<'\n';
            continue;
        }
        int qq=0;
        while(1)
        {
            if(x>y)
            {
                sol+=max(a,b)/min(a,b)-(min(a,b)==1);
                int a2=a,b2=b;
                a=nxt(a2,b2);
                b=nxt(b2,a2);
                --x;
            }
            else
                if(y>x)
                {
                    sol+=max(c,d)/min(c,d)-(min(c,d)==1);
                    int a2=c,b2=d;
                    c=nxt(a2,b2);
                    d=nxt(b2,a2);
                    --y;
                }
                else
                {
                    if(a==c && (max(b,d)-min(b,d))%a==0)
                    {
                        sol+=(max(b,d)-min(b,d))/a;
                        break;
                    }
                    else
                        if(b==d && (max(a,c)-min(a,c))%b==0)
                        {
                            sol+=(max(a,c)-min(a,c))/b;
                            break;
                        }
                        else
                        {
                            sol+=max(a,b)/min(a,b)-(min(a,b)==1);
                            int a2=a,b2=b;
                            a=nxt(a2,b2);
                            b=nxt(b2,a2);
                            --x;
                            sol+=max(c,d)/min(c,d)-(min(c,d)==1);
                            a2=c,b2=d;
                            c=nxt(a2,b2);
                            d=nxt(b2,a2);
                            --y;
                        }
                }
        }
        g<<sol<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("eq4.in");
ofstream g("eq4.out");
long long c,a,b;
long long e,freeres,xres,yres,zres,tres,res;
long long nr,sgn,wd;
string s;
vector<long long>coe;
unordered_map<long long,long long>m;
long long aux=1;
void compute()
{
    for(long long i=0;i<s.size();++i)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            wd=1;
            nr=nr*10+s[i]-'0';
            continue;
        }
        if(s[i]=='+')
        {
            if(nr>0)
                freeres+=nr*sgn,res+=nr*sgn,nr=0,wd=0;
            sgn=1;
            continue;
        }
        if(s[i]=='-')
        {
            if(nr>0)
                freeres+=nr*sgn,res+=nr*sgn,nr=0,wd=0;
            sgn=-1;
            continue;
        }
        if(!wd)
            nr=1;
        wd=0;
        if(s[i]=='x')
            xres+=nr*sgn,res+=nr*sgn,nr=0;
        if(s[i]=='y')
            yres+=nr*sgn,res+=nr*sgn,nr=0;
        if(s[i]=='z')
            zres+=nr*sgn,res+=nr*sgn,nr=0;
        if(s[i]=='t')
            tres+=nr*sgn,res+=nr*sgn,nr=0;
    }
    if(nr>0)
        freeres+=nr*sgn,res+=nr*sgn,nr=0;
}
int main()
{
    f>>c;
    f>>s;
    f>>a>>b>>e;
    compute();
    if(c==1)
        g<<res<<'\n';
    if(c==2)
    {
        if(xres!=0)
            coe.push_back(xres);
        else
            aux=aux*(b-a+1);
        if(yres!=0)
            coe.push_back(yres);
        else
            aux=aux*(b-a+1);
        if(zres!=0)
            coe.push_back(zres);
        else
            aux=aux*(b-a+1);
        if(tres!=0)
            coe.push_back(tres);
        else
            aux=aux*(b-a+1);
        if(coe.size()==0)
            if(freeres==e)
                g<<aux<<'\n';
            else
                g<<0<<'\n';
        if(coe.size()==1)
        {
            long long ss=e-freeres;
            if(ss%coe[0])
                g<<0<<'\n';
            else
            {
                ss/=coe[0];
                if(a<=ss && ss<=b)
                    g<<aux<<'\n';
                else
                    g<<0<<'\n';
            }
        }
        if(coe.size()==2)
        {
            long long sol=0;
            for(long long j=a;j<=b;++j)
            {
                long long ss=e-freeres-coe[0]*j;
                if(ss%coe[1])
                    continue;
                else
                {
                    ss/=coe[1];
                    if(a<=ss && ss<=b)
                        sol+=aux;
                }
            }
            g<<sol<<'\n';
        }
        if(coe.size()==3)
        {
            long long sol=0;
            for(long long i=a;i<=b;++i)
                for(long long j=a;j<=b;++j)
                {
                    long long ss=e-freeres-coe[1]*j-coe[0]*i;
                    if(ss%coe[2])
                        continue;
                    else
                    {
                        ss/=coe[2];
                        if(a<=ss && ss<=b)
                            sol+=aux;
                    }
                }
            g<<sol<<'\n';
        }
        if(coe.size()==4)
        {
            e-=freeres;
            long long sol=0;
            for(long long i=a;i<=b;++i)
                for(long long j=a;j<=b;++j)
                    m[coe[0]*i+coe[1]*j]++;
            for(long long i=a;i<=b;++i)
                for(long long j=a;j<=b;++j)
                    sol+=m[e-coe[2]*i-coe[3]*j];
            g<<sol<<'\n';
        }
    }
    return 0;
}

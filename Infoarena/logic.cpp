#include<bits/stdc++.h>
using namespace std;
ifstream f ("logic.in");
ofstream g ("logic.out");
int n,n1,n2,ap1[30],ap2[30],val[30],j,ok1,ok2,ok;
char sir1[260],sir2[260],s[260];
bool verificap()
{
    memset(ap1,0,sizeof(ap1));
    memset(ap2,0,sizeof(ap2));
    for(int i=0;i<n1;++i)
        if(sir1[i]>='a'&&sir1[i]<='z')
            ap1[sir1[i]-'a'+1]=1;
    for(int i=0;i<n2;++i)
        if(sir2[i]>='a'&&sir2[i]<='z')
            ap2[sir2[i]-'a'+1]=1;
    for(int i=1;i<=26;++i)
        if(ap1[i]!=ap2[i])
            return 0;
    return 1;
}
int eval();
int termen();
void solve(int k)
{
    if(ap1[k])
    {
        for(int i=0;i<=1;++i)
        {
            val[k]=i;
            if(k<26)
                solve(k+1);
            else
                if(k==26)
                {
                    strcpy(s,sir1);
                    j=0;
                    ok1=eval();
                    strcpy(s,sir2);
                    j=0;
                    ok2=eval();
                    if(ok1!=ok2)
                        ok=0;
                }
        }
    }
    else
    {
        if(k<26)
            solve(k+1);
        else
            if(k==26)
            {
                strcpy(s,sir1);
                j=0;
                ok1=eval();
                strcpy(s,sir2);
                j=0;
                ok2=eval();
                if(ok1!=ok2)
                    ok=0;
            }
    }
}
int variable()
{
    if(s[j]=='~')
    {
        ++j;
        return (!variable());
    }
    return val[s[j++]-'a'+1];
}
int termen()
{
    int r,neg=0;
    while(s[j]=='~')
    {
       ++j;
       neg=!neg;
    }
    if(s[j]=='(')
    {
        ++j;
        r=eval();
        ++j;
    }
    else
        r=variable();
    if(neg)
        r=!r;
    while(s[j]=='&')
        ++j,r&=termen();
    return r;
}
int eval()
{
    int r=termen();
    while(s[j]=='|' || s[j]=='^')
    {
        if(s[j]=='|')
            ++j,r|=eval();
        else
            ++j,r^=eval();
    }
    return r;
}
int main()
{
    f>>n;
    f.get();
    for(int i=1;i<=n;++i)
    {
        f.getline(sir1,260);
        f.getline(sir2,260);
        n1=strlen(sir1);
        n2=strlen(sir2);
        if(!verificap())
            g<<"diferite"<<'\n';
        else
        {
            memset(val,0,sizeof(val));
            ok=1;
            solve(1);
            if(ok)
                g<<"egale"<<'\n';
            else
                g<<"diferite"<<'\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
ifstream f("bool.in");
ofstream g("bool.out");
int x,i,n,k;
char c, s[1010], *p;
bool a[105];

bool exand();
bool exor();
bool eval();


int main()
{
    f.getline(s,1000);
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>c;
        p=s; x=c-'A';
        a[x]=!a[x];
        if (exor()==true)
            g<<1;
        else
            g<<0;
    }
    return 0;
}
bool exor()
{
    bool r;
    r=exand();
    while ( *p=='O' && *(p+1)=='R')
    {
        p+=3;
        r=r|exand();
    }
    return r;
}
bool exand ()
{
    bool r;
    r=eval();
    while ( *p=='A' && *(p+1)=='N' )
    {
        p+=4;
        r=r&eval();
    }
    return r;
}
bool eval()
{
    bool r=0;
    if ( *p=='(')
    {
        p++;
        r=exor();
        p++;
    }
    else
        if ( *p=='N' && *(p+1)=='O' )
        {
            p+=4;
            r=!eval();
        }
        else
            if (*p=='F' && *(p+1)=='A')
            {
                r=0;
                p+=6;
            }
            else
                if ( *p=='T' && *(p+1) =='R' )
                {
                    r=1;
                    p+=5;
                }
                else
                {
                    r=a[*p-'A'];
                    p+=2;
                }
    return r;
}

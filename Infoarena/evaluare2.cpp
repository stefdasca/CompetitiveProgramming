/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("evaluare2.in");
ofstream g("evaluare2.out");
char c[102],*p;
long long eval();
long long imparte();
long long ridput();
long long ogl();
long long eval()
{
    long long r=imparte();
    while(*p=='+')
    {
        ++p;
        r+=imparte();
    }
    return r;
}
long long imparte()
{
    long long r=ridput();
    while(*p=='/')
    {
        ++p;
        r/=ridput();
    }
    return r;
}
deque<long long>d;
long long ridput()
{
    long long r=ogl();
    while(*p=='^')
    {
        ++p;
        r=pow(r,ridput());
    }
    return r;
}
long long inv(long long nr)
{
    long long og=0;
    while(nr)
    {
        og=og*10+nr%10;
        nr/=10;
    }
    return og;
}
long long ogl()
{
    long long r=0;
    long long nt=0;
    while(*p=='!')
    {
        ++p;
        ++nt;
    }
    if(*p=='(')
    {
        ++p;
        r=eval();
        ++p;
    }
    else
        while(*p>='0' && *p<='9')
        {
            r=r*10+(*p-'0');
            ++p;
        }
    for(int i=1;i<=nt;++i)
        r=inv(r);
    return r;
}
int main()
{
    f>>c;
    p=c;
    g<<eval();
    return 0;
}

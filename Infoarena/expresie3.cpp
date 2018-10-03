/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("expresie3.in");
ofstream g("expresie3.out");
int v[27];
bool ap[27],fo;
char c[20002],*p;
void eval(int v[],int sgn)
{
    int v2[27]={0};
    if(!fo)
        while(*p)
        {
            if(*p>='a' && *p<='z')
                v2[*p-'a']+=sgn,++p;
            else
                if(*p=='*')
                {
                    ++p;
                    if(*p=='(')
                    {
                        ++p;
                        fo=1;
                        eval(v2,sgn);
                        ++p;
                    }
                }
                else
                    if(*p=='/')
                    {
                        ++p;
                        if(*p=='(')
                        {
                            ++p;
                            fo=1;
                            eval(v2,-sgn);
                            ++p;
                        }
                        else
                            v2[*p-'a']-=sgn,++p;
                    }
                    else
                        if(*p=='(')
                        {
                            ++p;
                            fo=1;
                            eval(v2,sgn);
                            ++p;
                        }
        }
    else
        while(*p!=')')
        {
            if(*p>='a' && *p<='z')
                v2[*p-'a']+=sgn,++p;
            else
                if(*p=='*')
                {
                    ++p;
                    if(*p=='(')
                    {
                        ++p;
                        fo=1;
                        eval(v2,sgn);
                        ++p;
                    }
                }
                else
                    if(*p=='/')
                    {
                        ++p;
                        if(*p=='(')
                        {
                            ++p;
                            fo=1;
                            eval(v2,-sgn);
                            ++p;
                        }
                        else
                            v2[*p-'a']-=sgn,++p;
                    }
                    else
                        if(*p=='(')
                        {
                            ++p;
                            fo=1;
                            eval(v2,sgn);
                            ++p;
                        }

        }
    for(int i=0;i<=26;++i)
        v[i]+=v2[i];
}
int main()
{
    f>>c;
    p=c;
    int l=strlen(c);
    for(int i=0;i<l;++i)
        if(c[i]>='a' && c[i]<='z')
            ap[c[i]-'a']=1;
    eval(v,1);
    for(int i=0;i<26;++i)
        if(ap[i]==1)
            g<<(char)(i+'a')<<" "<<v[i]<<'\n';
    return 0;
}

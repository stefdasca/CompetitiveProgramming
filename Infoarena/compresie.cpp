/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("compresie.in");
ofstream g("compresie.out");
int Stars,poz,len,nr,nl,n;
char c[1000002];
char mat[1002][1002];
void Start()
{
    f>>c;
    len=strlen(c);
    for(int i=0;i<len;++i)
        if(c[i]=='*')
            ++Stars;
        else
            if(c[i]>='0' && c[i]<='9')
                nr=nr*10+c[i]-'0';
            else
                if(nr)
                    nl+=nr,nr=0;
                else
                    ++nl;
    g<<Stars<<'\n';
}
void rec(int stl, int stc, int sfl, int sfc)
{
    if(sfl==stl && stc==sfc){
        mat[stl][stc]=c[poz],++poz;
        return;
    }
    if(c[poz]=='*')
    {
        ++poz;
        if(sfl==stl)
        {
            rec(stl,stc,sfl,(stc+sfc)/2);
            rec(stl,(stc+sfc)/2+1,sfl,sfc);
        }
        else
            if(stc==sfc)
            {
                rec(stl,stc,(stl+sfl)/2,sfc);
                rec((stl+sfl)/2+1,stc,sfl,sfc);
            }
            else
            {
                rec(stl,stc,(stl+sfl)/2,(stc+sfc)/2);
                rec(stl,(stc+sfc)/2+1,(stl+sfl)/2,sfc);
                rec((stl+sfl)/2+1,stc,sfl,(stc+sfc)/2);
                rec((stl+sfl)/2+1,(stc+sfc)/2+1,sfl,sfc);
            }
    }
    else
        if(c[poz]>='0' && c[poz]<='9')
        {
            int nr=0;
            while(c[poz]>='0' && c[poz]<='9')
                nr=nr*10+c[poz]-'0',++poz;
            for(int i=stl;i<=sfl;++i)
                for(int j=stc;j<=sfc;++j)
                    mat[i][j]=c[poz];
            ++poz;
        }
}
int main()
{
    Start();
    n=sqrt(nl);
    rec(1,1,n,n);
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=n;++j)
            g<<mat[i][j];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("ecuatii.in");
ofstream g("ecuatii.out");
int n;
int xms,xmd;
int nrms,nrmd;
char c1[501];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i){
        f>>c1;
        int p=0;
        xms=xmd=nrms=nrmd=0;
        bool sg=1;
        int nr=0;
        while(c1[p]!='=')
        {
            if(c1[p]=='-'){
                if(nr)
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xms-=nr,nr=0;
                        else
                            xms+=nr,nr=0;
                    else
                        if(sg==0)
                            nrms-=nr,nr=0;
                        else
                            nrms+=nr,nr=0;
                else
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xms--,nr=0;
                        else
                            xms++,nr=0;
                sg=0;
            }
            if(c1[p]=='+'){
                if(nr)
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xms-=nr,nr=0;
                        else
                            xms+=nr,nr=0;
                    else
                        if(sg==0)
                            nrms-=nr,nr=0;
                        else
                            nrms+=nr,nr=0;
                else
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xms--,nr=0;
                        else
                            xms++,nr=0;
                sg=1;
            }
            if(c1[p]>='0' && c1[p]<='9')
                nr=nr*10+c1[p]-'0';
            ++p;
        }
        if(c1[p-1]=='x')
            if(sg==0)
                xms-=max(1,nr),nr=0;
            else
                xms+=max(1,nr),nr=0;
        else
            if(sg==0)
                nrms-=nr,nr=0;
            else
                nrms+=nr,nr=0;
        ++p;
       while(p<strlen(c1))
        {
            if(c1[p]=='-'){
                if(nr)
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xmd-=nr,nr=0;
                        else
                            xmd+=nr,nr=0;
                    else
                        if(sg==0)
                            nrmd-=nr,nr=0;
                        else
                            nrmd+=nr,nr=0;
                else
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xmd--,nr=0;
                        else
                            xmd++,nr=0;
                sg=0;
            }
            if(c1[p]=='+'){
                if(nr)
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xmd-=nr,nr=0;
                        else
                            xmd+=nr,nr=0;
                    else
                        if(sg==0)
                            nrmd-=nr,nr=0;
                        else
                            nrmd+=nr,nr=0;
                else
                    if(c1[p-1]=='x')
                        if(sg==0)
                            xmd--,nr=0;
                        else
                            xmd++,nr=0;
                sg=1;
            }
            if(c1[p]>='0' && c1[p]<='9')
                nr=nr*10+c1[p]-'0';
            ++p;
        }
        if(c1[p-1]=='x')
            if(sg==0)
                xmd-=max(1,nr),nr=0;
            else
                xmd+=max(1,nr),nr=0;
        else
            if(sg==0)
                nrmd-=nr,nr=0;
            else
                nrmd+=nr,nr=0;
       sg=1;
       xms-=xmd;
       nrmd-=nrms;
       if(xms==0 && nrmd==0)
          g<<"infinit"<<'\n';
       else
            if(xms==0 && nrmd!=0)
                g<<"imposibil"<<'\n';
            else
            {
                float nr=(nrmd+0.0)/xms;
                g<<fixed<<setprecision(4)<<nr<<'\n';
            }
    }
    return 0;
}

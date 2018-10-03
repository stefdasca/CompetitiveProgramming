#include<bits/stdc++.h>
using namespace std;
ifstream f("text4.in");
ofstream g("text4.out");
int l;
char c1[1023];
int main()
{
    f>>l;
    f.get();
    while(f.getline(c1,1021))
    {
        int z=strlen(c1);
        int st=0;
        while(st<z)
        {
            int ast=st;
            int nrch=0,nrcuv=0;
            while(nrch+nrcuv-1<l && st<z)
            {
              //  g<<c1[st];
                if(c1[st]!=' '){
                    ++nrch;
                    if(st==0 || c1[st-1]==' ')
                        ++nrcuv;
                }
                ++st;
            }
            if(st==z){
                for(int j=ast;j<z-1;++j)
                    if(c1[j]!=' ')
                    {
                        g<<c1[j];
                        if(c1[j+1]==' ')
                            g<<" ";
                    }
                g<<c1[z-1]<<'\n';
            }
            else
            {
                --st;
              //  g<<nrch<<" "<<nrcuv<<'\n';
                if(nrch+nrcuv-1==l)
                    if(c1[st]!=' ' && c1[st+1]==' ');
                    else{
                        while(c1[st]!=' ')
                            --st,--nrch;
                        --nrcuv;
                        while(c1[st]==' ')
                            --st;
                    }
                else
                    while(nrch+nrcuv-1>l){
                        while(c1[st]!=' ')
                            --st,--nrch;
                        --nrcuv;
                        while(c1[st]==' ')
                            --st;
                    }
                int d=(l-nrch)/(nrcuv-1);
                int mod=(l-nrch)%(nrcuv-1);
                for(int i=ast;i<st;++i)
                    if(c1[i]!=' ')
                    {
                        g<<c1[i];
                        if(c1[i+1]==' ')
                        {
                            for(int j=1;j<=d;++j)
                                g<<" ";
                            if(mod)
                                g<<" ",--mod;
                        }
                    }
                g<<c1[st]<<'\n';
                ++st;
                while(c1[st]==' ')
                    ++st;
            }
        }
    }
    return 0;
}

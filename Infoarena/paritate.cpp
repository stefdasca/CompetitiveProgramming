#include<bits/stdc++.h>
using namespace std;
ifstream f("paritate.in");
ofstream g("paritate.out");
char c1[60001*8];
int ok=1;
int v1[60001],nrp;
int main()
{
    f>>c1;
    int l=strlen(c1);
    for(int i=0;i<l;i+=8)
    {
        int k=c1[i]-'0';
        int nrb=0;
        for(int j=i+1;j<i+8;++j)
            if(c1[j]=='1')
                nrb=1-nrb;
        if(k!=nrb)
            ok=0,++nrp,v1[nrp]=i/8;
    }
    if(ok==0)
    {
        g<<"NU"<<'\n';
        for(int i=1;i<=nrp;++i)
            g<<v1[i]<<" ";
    }
    else{
        g<<"DA"<<'\n';
        for(int i=0;i<l;i+=8)
        {
            int k=c1[i]-'0';
            int nrb=0,p=1;
            for(int j=i+7;j>i;p+=p,--j)
                if(c1[j]=='1')
                    nrb+=p;
            if(nrb==10)
                g<<'\n';
            else{
                char c=nrb;
                g<<c;
            }
        }
    }
    return 0;
}

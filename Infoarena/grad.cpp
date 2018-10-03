#include<bits/stdc++.h>
using namespace std;
ifstream f("grad.in");
ofstream g("grad.out");
int nrp[200];
int ex[200],sg;
char c[302];
int main()
{
    f.getline(c,260);
    int np=0;
    for(int i=2;i<=30;++i)
    {
        bool ok=0;
        for(int j=2;j*j<=i;++j)
            if(i%j==0)
            {
                ok=1;
                break;
            }
        if(ok==0)
            nrp[++np]=i;
    }
    int l=strlen(c);
    int lc=0;
    c[l]=' ';
    ++l;
    for(int i=0;i<l;++i)
        if(c[i]!=' ')
        {
            ++lc;
            int nr=c[i]-'a'+1;
            for(int j=1;j<=np && nr>1;++j)
                while(nr%nrp[j]==0)
                    nr/=nrp[j],ex[j]+=lc;
        }
        else
        if(lc){
                int prod=1;
                for(int j=1;j<=np;ex[j]=0,++j)
                    prod=(prod*(ex[j]+1))%lc;
               sg+=prod;
                lc=0;
            }
    g<<sg;
    return 0;
}

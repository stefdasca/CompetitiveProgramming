#include<bits/stdc++.h>
using namespace std;
ifstream f("ciurulet.in");
ofstream g("ciurulet.out");
int n,tip[1000003];
string s;
int gut[1000003];
int main()
{
    f>>n;
    f>>s;
    for(int i=2;i<=n;++i)
        if(s[i-2]=='1')
            tip[i]=1;
        else
            if(s[i-2]=='?')
                tip[i]=-1;
    for(int i=2;i<=n;++i)
        if(tip[i]==1)
        {
            gut[i]=1;
            for(int j=i+i;j<=n;j+=i)
            {
                if(s[j-2]=='?')
                    tip[j]=0;
                gut[j]=1;
            }
        }
        else
            if(tip[i]==-1)
            {
                int qq=0,tot=0;
                for(int j=i+i;j<=n;j+=i)
                    if(s[j-2]=='1')
                    {
                        qq=1;
                        break;
                    }
                if(qq==tot)
                {
                    gut[i]=1;
                    for(int j=i+i;j<=n;j+=i)
                    {
                        if(s[j-2]=='?')
                            tip[j]=0;
                        gut[j]=1;
                    }
                }
            }
    int nru=0;
    for(int i=2;i<=n;++i)
        nru+=gut[i];
    g<<nru<<'\n';
    for(int i=2;i<=n;++i)
        g<<gut[i];
    return 0;
}

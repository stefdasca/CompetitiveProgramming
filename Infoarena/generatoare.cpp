#include<bits/stdc++.h>
using namespace std;
ifstream f("generatoare.in");
ofstream g("generatoare.out");
int n,v[50002];
double sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int j=0;j<30;++j)
    {
        int inte=(1<<(j+1));
        int bune=(1<<j);
        double ppar=1.0000;
        double pimpar=0.0000;
        for(int j=1;j<=n;++j)
        {
            int cati=(v[j]/inte)*bune;
            if(v[j]%inte>bune)
                cati+=v[j]%inte-bune;
            double rr=(0.0+cati)/(0.0+v[j]);
            double a=ppar;
            double b=pimpar;
            ppar=a*(1.0000-rr)+b*rr;
            pimpar=b*(1.0000-rr)+a*rr;
        }
        sol=sol+pimpar*(0.0+bune);
    }
    g<<fixed<<setprecision(3)<<sol;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("zile.in");
ofstream g("zile.out");
int n,k,z,v[2001];
int main()
{
    f>>n>>z>>k;
    if(k==0)
        for(int i=1;i<=n;++i)
            g<<i<<" ";
    else
    {
        int r=1,s=0;
        int p=2;
        while(s+r<=k)
        {
            v[p]=s+r;
            s+=r,++r;
            ++p;
        }
        --p;
        for(int i=p;i>=2;--i)
        {
            int nru=0,ndu=0;
            int zz=0;
            int pz=i;
            while(zz<k)
            {
                if(zz+v[pz]<=k)
                    zz+=v[pz],++ndu,nru+=pz;
                else
                    --pz;
            }
            if(nru<=n)
                if(z-ndu>=n-nru)
                {
                    int nd=0;
                    zz=0;
                    pz=i;
                    ndu=0;
                    nru=0;
                     while(zz<k)
                        if(zz+v[pz]<=k){
                            zz+=v[pz],++ndu;
                            for(int j=1;j<=pz;++j)
                                g<<ndu<<" ",++nru;
                        }
                        else
                            --pz;
                     ++ndu;
                     for(int j=nru+1;j<=n;++j)
                         g<<ndu<<" ",++ndu;
                     break;
                }
        }
    }
    return 0;
}

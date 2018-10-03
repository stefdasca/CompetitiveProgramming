#include<bits/stdc++.h>
using namespace std;
ifstream f("subgeom.in");
ofstream g("subgeom.out");
int t,n,nr;
vector<int>v[100002];
int ar[5002];
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n;
        for(int i=1;i<=n;++i)
            f>>ar[i],v[ar[i]].push_back(i);
        int Lmax=1;
        for(int i=1;i+Lmax-1<=n;++i)
            for(int j=2;ar[i]*j<=100000;++j)
            {
                int minp=i;
                int L=1;
                long long nr=ar[i]*j;
                while(nr<=100000 && !v[nr].empty())
                {
                    bool ok=0;
                    for(int I=0;I<v[nr].size();++I)
                        if(v[nr][I]>minp){
                            minp=v[nr][I];
                            ok=1;
                            break;
                        }
                    if(ok==1)
                    {
                        ++L;
                        nr*=j;
                    }
                    else
                        break;
                }
                Lmax=max(Lmax,L);
                int nt=1;
                bool ok=1;
                for(int q=1;q<=Lmax;++q){
                    nt*=(j+1);
                    if(nt*ar[i]>100000){
                        ok=0;
                        break;
                    }
                }
                if(!ok)
                    break;
            }
        g<<Lmax<<'\n';
        for(int i=1;i<=n;++i)
            if(v[ar[i]].size())
                v[ar[i]].clear();
    }
    return 0;
}

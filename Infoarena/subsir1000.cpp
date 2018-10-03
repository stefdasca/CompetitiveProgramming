#include<bits/stdc++.h>
using namespace std;
ifstream f("subsir1000.in");
ofstream g("subsir1000.out");
int lp[100001],nr,n;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        int nr1=nr;
        int bst=0;
        for(int j=2;j*j<=nr;++j)
            if(nr%j==0)
            {
                bst=max(bst,lp[j]);
                while(nr%j==0)
                    nr/=j;
            }
        if(nr>1)
            bst=max(bst,lp[nr]);
        ++bst;
        for(int j=2;j*j<=nr1;++j)
            if(nr1%j==0)
            {
                lp[j]=bst;
                while(nr1%j==0)
                    nr1/=j;
            }
        if(nr1>1)
            lp[nr1]=bst;
    }
    int sol=0;
    for(int i=1;i<=100000;++i)
        sol=max(sol,lp[i]);
    g<<sol<<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("sirag2.in");
ofstream g("sirag2.out");
int t;
int n,l;
char c[100002];
int frq[100002][28],mr[100002],cc[100002],cb;
int val(char x)
{
    return (int)(x-'a');
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>l;
        f>>(c+1);
        int sol=0;
        int lp=1;
        for(int i=1;i<=n;++i)
        {
            if(c[i]!='*')
            {
                ++frq[i%l][val(c[i])];
                if(frq[i%l][val(c[i])]==1)
                {
                    mr[i%l]++;
                    while(mr[i%l]==2)
                    {
                        if(c[lp]!='*')
                        {
                            --frq[lp%l][val(c[lp])];
                            if(!frq[lp%l][val(c[lp])])
                                --mr[lp%l];
                        }
                        ++lp;
                    }
                }
            }
            if((i-lp+1)%l==0)
                sol=max(sol,i-lp+1);
        }
        while(lp<=n)
        {
            if(c[lp]!='*')
            {
                --frq[lp%l][val(c[lp])];
                if(!frq[lp%l][val(c[lp])])
                    --mr[lp%l];
            }
            ++lp;
        }
        g<<sol<<'\n';
    }
    return 0;
}

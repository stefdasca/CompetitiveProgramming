#include<fstream>
using namespace std;
ifstream f("reactii.in");
ofstream g("reactii.out");
int n,t,nr;
int min1[15002],max1[15002];
int main()
{
    f>>n;
    f>>t;
    for(;t;--t)
    {
        int l=0;
        for(int i=1;i<=n;++i)
        {
            f>>nr;
            if(l==0 || min1[l]-1!=nr && max1[l]+1!=nr)
                ++l,min1[l]=nr,max1[l]=nr;
            else
            {
                if(min1[l]-1==nr)
                    --min1[l];
                else
                    ++max1[l];
                bool ok=1;
                while(ok && l>1)
                {
                    ok=0;
                    if(min1[l]-1==max1[l-1] || max1[l]+1==min1[l-1])
                    {
                        max1[l-1]=max(max1[l-1],max1[l]);
                        min1[l-1]=min(min1[l-1],min1[l]);
                        --l;
                        ok=1;
                    }
                }
            }
        }
        if(l>1)
            g<<0<<'\n';
        else
            g<<1<<'\n';
    }
    return 0;
}

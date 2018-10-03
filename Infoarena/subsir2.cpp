#include<fstream>
using namespace std;
ifstream f("subsir2.in");
ofstream g("subsir2.out");
int n,sol[5005],bf[5005],v[5005],i,j,min1,p,s;
int main()
{
    f>>n;
    for (i=1;i<=n;++i)
        f>>v[i];
    for (i=n;i>=1;--i)
    {
        min1=1e9;
        s=min1;
        for (j=i+1;j<=n;++j)
            if ((v[j]>=v[i]) && (v[j]<min1))
                {
                    min1=v[j];
                    if (sol[j]<=s)
                        s=sol[j],p=j;
            }
        if (min1==1e9)
            sol[i]=1;
        else
                sol[i]=sol[p]+1,bf[i]=p;
    }
    min1=sol[1],p=1,j=v[1];
    for (i=2;i<=n;++i)
        if (v[i]<j)
        {
            j=v[i];
            if (sol[i]<=min1)
                min1=sol[i],p=i;
        }
    g<<min1<<'\n';
    g<<p<<" ";
    while(--min1)
    {
        p=bf[p];
        g<<p<<" ";
    }

return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("gramezi.in");
ofstream g("gramezi.out");
int n;
bool taken[30002];
struct p
{
    int pa,sum,pi;
};
p z[30002],b[30002];
bool test(p a, p b)
{
    if(a.sum==b.sum)
        return a.pa<b.pa;
    return a.sum<b.sum;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int A,B;
        f>>A>>B;
        z[i]={A,A+B,i};
        b[i]={B,A+B,i};
    }
    sort(z+1,z+n+1,test);
    sort(b+1,b+n+1,test);
    int xa=n,xb=n;
    long long scora=0, scorb=0;
    for(int i=1;i<=n;++i)
    {
        if(i&1)
        {
            while(taken[z[xa].pi])
                --xa;
            scora+=z[xa].pa;
            taken[z[xa].pi]=1;
        }
        else
        {
            while(taken[b[xb].pi])
                --xb;
            scorb+=b[xb].pa;
            taken[b[xb].pi]=1;
        }
    }
    g<<scora<<" "<<scorb;
    return 0;
}

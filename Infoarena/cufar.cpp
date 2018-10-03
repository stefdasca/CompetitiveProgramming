/// Why, Rose? Why?
#include<bits/stdc++.h>
using namespace std;
ifstream f("cufar.in");
ofstream g("cufar.out");
int c,n,nr,k,prime[1000002][9];
int cate[1000002];
long long sol;
bool prim[1000002];
void ciur()
{
    for(int i=2;i<=1000000;i++)
        if(!prim[i])
            for(int j=i;j<=1000000;j+=i)
            {
                prim[j]=1;
                ++cate[j];
                prime[j][cate[j]]=i;
            }
}
int main()
{
    ciur();
    f>>c>>n;
    if(c==1)
    {
        f>>nr>>k;
        g<<prime[nr][k]<<'\n';
    }
    else
    {
        long long sol=0;
        for(int i=1;i<=n;++i)
        {
            f>>nr>>k;
            sol+=1LL*prime[nr][k];
        }
        g<<sol<<'\n';
    }
    return 0;
}

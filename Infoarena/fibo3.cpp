#include<bits/stdc++.h>
using namespace std;
ifstream f("fibo3.in");
ofstream g("fibo3.out");
int n,j;
long long x1,x2,yy,y2,sol,fib[502];
const long long q=1e15;
int main()
{
    f>>n;
    fib[1]=1;
    fib[2]=1;
    for(j=3;fib[j-1]<=10*q;++j)
        fib[j]=fib[j-1]+fib[j-2];
    --j;
    for(int i=1;i<=n;++i)
    {
        sol=0;
        f>>x1>>yy>>x2>>y2;
        long long bg=yy;
        int q=2;
        while(x1+yy>fib[q])
            ++q;
        yy+=(fib[q]-x1-yy);
        while(yy<=y2)
        {
            sol+=min(yy-bg+1,x2-x1+1);
            yy+=fib[q+1]-fib[q];
            ++q;
        }
        x1++;
        q=2;
        while(x1+y2>fib[q])
            ++q;
        x1+=(fib[q]-x1-y2);
        while(x1<=x2)
        {
            sol+=min(y2-bg+1,x2-x1+1);
            x1+=fib[q+1]-fib[q];
            ++q;
        }
        g<<sol<<'\n';
    }
    return 0;
}

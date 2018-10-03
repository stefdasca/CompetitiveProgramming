#include<bits/stdc++.h>
using namespace std;
ifstream f("proc.in");
ofstream g("proc.out");
int n, i, nr, k, p, n1, n2;
int st, dr, t;
bool pot(int t)
{
    if(n == 0)
        return 1;
    int x=n1,y=n2,k2;
    for(i=1;i<=p;i++)
    {
        nr=t;
        if(y>0)
        {
            k2=t/i/2;
            if(y>=k2)
                nr-=i*2*k2;
            else
                nr-=i*2*y;
            y-=k2;
        }
        if(x>0)
            x-=nr/i;
        if(x<=0 && y<=0)
            return 1;
    }
    return 0;
}
int main()
{
    f>>n>>k>>p;
    n1=k;
    n2=n-k;
    dr=(1<<28);
    st=1;
    while(st<=dr)
    {
        t = st+(dr-st)/2;
        k = pot(t);
        if(k == 0)
            st = t+1;
        else
            dr = t-1;
    }
    if(pot(t)==0)
        t++;
    if(pot(t-1)==1)
        t--;
    g<<t;
    return 0;
}

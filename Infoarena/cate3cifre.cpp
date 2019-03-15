/*
        infoarena cate3cifre(https://infoarena.ro/problema/cate3cifre)
        
    "Find the biggest integer not bigger than n such that it can be written in exactly 2 distinct bases as ppp, where p is a digit from 0 to b - 1
 where b is a base"
 
    We can observe that the biggest base one can get without reaching over Nmax is 1000, so we can precompute all the numbers which have
 the stated property.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("cate3cifre.in");
ofstream g("cate3cifre.out");
int c, n;
int frq[1000002];
int xa[1000002], ya[1000002];
int va[1000002], ta[1000002];
int main()
{
    f >> c;
    f >> n;
    for(int i = 2; i <= 1000; ++i)
        for(int j = 1; j < i; ++j)
        {
            int nr = j * (i * i) + j * i + j;
            if(nr > 1000000)
                continue;
            frq[nr]++;
            if(frq[nr] == 1)
                xa[nr] = i, va[nr] = j;
            if(frq[nr] == 2)
                ya[nr] = i, ta[nr] = j;
        }
    for(int i = n; i >= 1; --i)
        if(frq[i] == 2)
        {
            if(c == 1)
                g << i;
            else
                g << xa[i] << " " << va[i] << '\n' << ya[i] << " " << ta[i] << '\n';
            return 0;
        }
    return 0;
}

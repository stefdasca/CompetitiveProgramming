/*
        Infoarena lautari(infoarena.ro/problema/lautari)

    "Given a array of size n and 2 numbers p and q, find the number of subarrays from that array which have at least p and at most q
distinct elements"

    This problem is quite classical and it involves using 2 pointers method for keeping the required information

*/

#include<bits/stdc++.h>
using namespace std;
ifstream f("lautari.in");
ofstream g("lautari.out");
int n, p, q;
int v[100002];
int frqp[100002], frqq[100002];
int Rpp, Rpq, Edp, Edq;
int main()
{
    f >> n >> p >> q;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    long long ans = 0;
    Rpp = 1;
    Rpq = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(i > 1)
        {
            --frqp[v[i-1]];
            --frqq[v[i-1]];
            if(frqp[v[i-1]] == 0)
                --Edp;
            if(frqq[v[i-1]] == 0)
                --Edq;
        }
        while(Rpp <= n && Edp < p)
        {
            ++frqp[v[Rpp]];
            if(frqp[v[Rpp]] == 1)
                ++Edp;
            ++Rpp;
        }
        if(Edp < p)
            break;
        while(Rpq <= n)
        {
            ++frqq[v[Rpq]];
            if(frqq[v[Rpq]] == 1)
                ++Edq;
            if(Edq > q)
            {
                --frqq[v[Rpq]];
                if(frqq[v[Rpq]] == 0)
                    --Edq;
                break;
            }
            ++Rpq;
        }
        ans += Rpq - Rpp + 1;
    }
    g << ans << '\n';
    return 0;
}

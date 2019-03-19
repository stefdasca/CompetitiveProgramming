/*
        Infoarena fibo4(https://www.infoarena.ro/problema/fibo4)
        
   "Given an array of N elements, initially empty and M queries of type a b c, add for each element i in range [a, b], c + (i - a)th
Fibonacci number modulo 666013 and print the array resulting"

    Fibonacci numbers are periodic, so we can generate the first ~1.3 million fibonacci numbers, then we can use a segment tree to simulate
the updates. 

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("fibo4.in");
ofstream g("fibo4.out");
int n, m, fib[2000002];
long long vv[1000002];
struct segtree
{
    long long t1, t2;
};
segtree aint[4000002];
const int Lper = 1332028;
const int mod = 666013;
long long sol[1002];
void build_fib()
{
    fib[1] = 1;
    fib[0] = 0;
    for(int i = 2; i <= Lper + 3; ++i)
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
}
void upd(int nod, int st, int dr, int L, int R, long long stp)
{
    if(dr < L || st > R)
        return;
    if(L <= st && dr <= R)
    {
        long long pb = stp + (st - L);
        pb %= Lper;
        aint[nod].t2 += fib[pb];
        aint[nod].t1 += fib[(Lper + pb - 1) % Lper];
        return;
    }
    int mid = (st + dr) / 2;
    upd(nod * 2, st, mid, L, R, stp);
    upd(nod * 2 + 1, mid + 1, dr, L, R, stp);
}
void build(int nod, int st, int dr)
{
    long long aa = aint[nod].t1 % mod;
    long long bb = aint[nod].t2 % mod;
    long long cc;
    for(int i = st; i <= dr; ++i)
    {
        if(i == st)
        {
            vv[i] = vv[i] + bb;
            if(vv[i] >= mod)
                vv[i] -= mod;
        }
        else
        {
            cc = aa + bb;
            if(cc >= mod)
                cc -= mod;
            vv[i] += cc;
            if(vv[i] >= mod)
                vv[i] -= mod;
            aa = bb;
            bb = cc;
        }
    }
    if(st == dr)
        return;
    int mid = (st + dr) / 2;
    build(nod * 2, st, mid);
    build(nod * 2 + 1, mid + 1, dr);
}
int main()
{
    f >> n >> m;
    build_fib();
    for(int i = 1; i <= m; ++i)
    {
        long long a, b, c;
        f >> a >> b >> c;
        upd(1, 1, n, a, b, c);
    }
    build(1, 1, n);
    for(int i = 1; i <= n; ++i)
        g << vv[i] << " ";
    return 0;
}

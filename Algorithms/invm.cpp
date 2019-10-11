// https://www.infoarena.ro/problema/inversmodular
#include<bits/stdc++.h>
using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
int A, N;
void gcd(long long &x, long long &y, int a, int b)
{
     if (!b)
         x = 1, y = 0;
     else
     {
         gcd(x, y, b, a % b);
         long long aux = x;
         x = y;
         y = aux - y * (a / b);
     }
}
int main()
{
    long long inv = 0, ins;
    f >> A >> N;
    gcd(inv, ins, A, N);
    if (inv <= 0)
       inv = N + inv % N;
    g << inv;
    return 0;
}

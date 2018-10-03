#include <bits/stdc++.h>
using namespace std;
ifstream f("bombar.in");
ofstream g("bombar.out");
int n;
int a[1435], b[1435], c[1435];
const int base = 1e8;
inline void inm(int a[], int b)
{
    int t = 0;
    for(int i = 1; i <= a[0] ; ++i)
    {
        a[i] = a[i] * b + t;
        t = a[i] / base;
        a[i] %= base;
    }
    while(t > 0)
    {
        a[++a[0]] = t % base;
        t /= base;
    }
}
inline void scad(int a[], int b[])
{
    int t = 0;
    for(int i = 1; i <= a[0] ; ++i)
    {
        a[i] = a[i] - b[i] + t;
        if(a[i] < 0)
            a[i] += base, t = -1;
        else t = 0;
    }
    while(a[a[0]] == 0)
        --a[0];
}
int main()
{
    f >> n;
    a[0] = 1;
    a[1] = 1;
    b[0] = 1;
    b[1] = 1;
    for(int i = 2; i <= n ; ++i)
    {
        inm(a, 4);
        scad(a, c);
        memcpy(c, b, sizeof(b));
        memcpy(b, a, sizeof(a));
    }
    g << a[a[0]];
    for(int i = a[0] - 1; i >= 1 ; --i)
    {
        int aux = a[i];
        while(aux * 10 < base)
            aux *= 10, g << 0;
        g << a[i];
    }
    return 0;
}

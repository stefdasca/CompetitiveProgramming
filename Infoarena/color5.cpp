#include<bits/stdc++.h>
using namespace std;
ifstream f("color5.in");
ofstream g("color5.out");
int n;
int main()
{
    f >> n;
    int sol = 1 + (n >= 4) + (n >= 7);
    g << sol << '\n';
    for(int i = 0; i < n; ++i)
    {
        g << i << " " << (i + 1) % n << " " << i % sol + 1 << '\n';
        g << n << " " << i << " " << (i+1) % sol + 1 << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("permsort2.in");
ofstream g("permsort2.out");
int n, poz[100002];
int aib[100002];
void add(int poz)
{
    for(; poz <= n; poz += (poz & (-poz)))
        aib[poz]++;
}
int compute(int poz)
{
    int ans = 0;
    for(; poz; poz -= (poz & (-poz)))
        ans += aib[poz];
    return ans;
}
vector<int>mv;
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        f >> nr;
        poz[nr] = i;
    }
    for(int i = n; i >= 1; --i)
    {
        int np = poz[i] + compute(n) - compute(poz[i] - 1);
        if(np > 1)
        {
            if(np - 1 > 1)
                mv.push_back(np-1);
            mv.push_back(np);
        }
        add(poz[i]);
    }
    g << mv.size() << '\n';
    for(int i = 0; i < mv.size(); ++i)
        g << "P " << mv[i] << '\n';
    return 0;
}

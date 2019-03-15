#include<bits/stdc++.h>
using namespace std;
ifstream f("valutar.in");
ofstream g("valutar.out");
int c;
int a, b, nr0;
int n, m, l, e, x;
struct exchangeplace
{
    char type;
    int LtE, EtL;
};
exchangeplace v[10002];
int pas[10002];
int lei[10002], euro[10002];
bool out[10002];
int poz[10002];
int main()
{
    f >> c;
    f >> a >> b >> nr0;
    f >> n >> m >> l >> e >> x;
    for(int i = 1; i <= n; ++i)
        f >> v[i].type >> v[i].LtE >> v[i].EtL;
    for(int i = 1; i <= m; ++i)
        lei[i] = l, euro[i] = e, poz[i] = 1;
    int turn = 1;
    for(int i = 1; i <= x; ++i)
    {
        nr0 = (a * nr0 + b) % n + 1;
        poz[turn] = poz[turn] + nr0;
        if(poz[turn] > n)
            poz[turn] -= n;
        if(v[poz[turn]].type == 'R')
            pas[turn]++;
        if(v[poz[turn]].type == 'G')
        {
            if(poz[turn] * v[poz[turn]].LtE > lei[turn])
            {
                if(pas[turn])
                    pas[turn]--;
                else
                    out[turn] = 1;
            }
            else
            {
                lei[turn] -= poz[turn] * v[poz[turn]].LtE;
                euro[turn] += poz[turn];
            }
        }
        if(v[poz[turn]].type == 'V')
        {
            if(euro[turn] < poz[turn])
            {
                if(pas[turn])
                    pas[turn]--;
                else
                    out[turn] = 1;
            }
            else
            {
                euro[turn] -= poz[turn];
                lei[turn] += poz[turn] * v[poz[turn]].EtL;
            }
        }
        while(1)
        {
            ++turn;
            if(turn > m)
                turn = 1;
            if(!out[turn])
                break;
        }
    }
    int ans1 = 0;
    int mx = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(!out[i])
        {
            ++ans1;
            if(euro[i] > euro[mx])
                mx = i;
        }
    }
    if(c == 1)
        g << ans1;
    else
        g << mx;
    return 0;
}

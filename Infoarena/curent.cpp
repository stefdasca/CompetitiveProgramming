#include<bits/stdc++.h>
using namespace std;
ifstream f("curent.in");
ofstream g("curent.out");
const int max_size = 111111;
int n, upds, que, pos;
struct evenimente
{
    int zi, tip;
};
evenimente q[2 * max_size];
struct updas
{
    int day, where, type;
};
updas x[max_size];
bool cmp(updas a, updas b)
{
    return a.day < b.day;
}
int ask[max_size];
bool cmp2(evenimente a, evenimente b)
{
    if(a.zi == b.zi)
        return a.tip < b.tip;
    return a.zi < b.zi;
}
vector<int>v[max_size];
int ordine[max_size];
int st[max_size], sf[max_size], poz_dfs;
void dfs(int nod)
{
    ++poz_dfs;
    ordine[poz_dfs] = nod;
    st[nod] = poz_dfs;
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        dfs(vecin);
    }
    sf[nod] = poz_dfs;
}
struct qq
{
    int sum, stins;
};
qq aint[4 * max_size];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod].sum = 1;
        return;
    }
    int mid = (st + dr) >> 1;
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid + 1, dr);
    aint[nod].sum = aint[nod << 1].sum + aint[nod << 1 | 1].sum;
}
bool aprins[max_size];
void update(int nod, int st, int dr, int x, int y, int tip)
{
    if(x <= st && dr <= y)
    {
        if(tip == 2)
        {
            if(aint[nod].stins >= 1)
                --aint[nod].stins;
            if(aint[nod].stins == 0)
                if(dr == st)
                    aint[nod].sum = 1;
                else
                    aint[nod].sum = aint[nod << 1].sum + aint[nod << 1 | 1].sum;
        }
        else
        {
            aint[nod].sum = 0;
            ++aint[nod].stins;
        }
        return;
    }
    if(dr < x || st > y)
        return;
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, x, y, tip);
    update(nod << 1 | 1, mid + 1, dr, x, y, tip);
    if(!aint[nod].stins)
        if(dr == st)
            aint[nod].sum = 1;
        else
            aint[nod].sum = aint[nod << 1].sum + aint[nod << 1 | 1].sum;
    else
        aint[nod].sum = 0;
}
int main()
{
    f >> n;
    for(int i = 2; i <= n; ++i)
    {
        int q;
        f >> q;
        v[q].push_back(i);
    }
    f >> upds;
    for(int i = 1; i <= upds; ++i)
        f >> x[i].day >> x[i].where >> x[i].type, q[i] = {x[i].day, 0};
    sort(x + 1, x + upds + 1, cmp);
    f >> que;
    for(int i = 1; i <= que; ++i)
        f >> ask[i], q[upds + i] = {ask[i], 1};
    sort(q + 1, q + upds + que + 1, cmp2);
    dfs(1);
    build(1, 1, n);
    for(int i = 1; i <= upds + que; ++i)
    {
        if(q[i].tip == 1)
            g << aint[1].sum << '\n';
        else
        {
            ++pos;
            int tip;
            if(x[pos].type == 0)
                tip = 1;
            else
                tip = 2;
            if((tip == 1 && !aprins[x[pos].where]) || (tip == 2 && aprins[x[pos].where]))
                aprins[x[pos].where] ^= 1, update(1, 1, n, st[x[pos].where], sf[x[pos].where], tip);
        }
    }
    return 0;
}

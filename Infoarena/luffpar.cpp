#include<bits/stdc++.h>
using namespace std;
ifstream f("luffpar.in");
ofstream g("luffpar.out");
int n, q;
string s;
int tip, st, dr;
struct aint
{
    int sum;
    int minim, maxim;
    int lazy;
};
aint v[800002];
void propagate(int nod, int st, int dr)
{
    v[nod].sum *= -1;
    int aa = v[nod].maxim;
    int bb = v[nod].minim;
    v[nod].minim = aa * -1;
    v[nod].maxim = bb * -1;
    v[nod].lazy = 0;
    if(st != dr)
    {
        v[nod << 1].lazy ^= 1;
        v[nod << 1 | 1].lazy ^= 1;
    }
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        if(s[st-1] == '(')
            v[nod].sum = 1, v[nod].maxim = 1, v[nod].minim = 1;
        else
            v[nod].sum = -1, v[nod].maxim = -1, v[nod].minim = -1;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid + 1, dr);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].maxim = max(v[nod << 1].maxim, v[nod << 1].sum + v[nod << 1|1].maxim);
    v[nod].minim = min(v[nod << 1].minim, v[nod << 1].sum + v[nod << 1|1].minim);
}
void update(int nod, int st, int dr, int L, int R)
{
    if(v[nod].lazy)
        propagate(nod, st, dr);
    if(R < st || dr < L)
        return;
    if(L <= st && dr <= R)
    {
        propagate(nod, st, dr);
        return;
    }
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R);
    update(nod << 1 | 1, mid + 1, dr, L , R);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].maxim = max(v[nod << 1].maxim, v[nod << 1].sum + v[nod << 1|1].maxim);
    v[nod].minim = min(v[nod << 1].minim, v[nod << 1].sum + v[nod << 1|1].minim);
}
int summ = 0, mini = 10000000;
void query(int nod, int st, int dr, int L, int R)
{
    if(v[nod].lazy)
        propagate(nod, st, dr);
    if(R < st || dr < L)
        return;
    if(L <= st && dr <= R)
    {
        mini = min(mini, summ + v[nod].minim);
        summ += v[nod].sum;
        return;
    }
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1 | 1, mid + 1, dr, L , R);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].maxim = max(v[nod << 1].maxim, v[nod << 1].sum + v[nod << 1|1].maxim);
    v[nod].minim = min(v[nod << 1].minim, v[nod << 1].sum + v[nod << 1|1].minim);
}
int main()
{
    f >> n;
    f >> s;
    build(1, 1, n);
    f >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip, st, dr;
        f >> tip >> st >> dr;
        if(tip == 1)
            update(1, 1, n, st, dr);
        else
        {
            summ = 0;
            mini = 10000000;
            if((dr - st + 1) % 2 == 1)
            {
                g << 0 << '\n';
                continue;
            }
            query(1, 1, n, st, dr);
            if(mini == 0 && summ == 0)
                g << 1 << '\n';
            else
                g << 0 << '\n';
        }
    }
    return 0;
}

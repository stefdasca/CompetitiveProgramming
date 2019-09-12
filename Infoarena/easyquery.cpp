/*
        infoarena easyquery

    Let's sort the queries in increasing order of their right end. We can observe that at each step, when we find a new maximum
or minimum, it will influence nodes in range [positionSmaller/Bigger, i], where positionSmaller/Bigger is the rightmost position, smaller
than i, such that v[positionSmaller/Bigger] < or > v[i], depending on case.

    Therefore, we can solve those updates using lazy propagation.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("eq.in");
ofstream g("eq.out");
int n, q, v[100002], aint[3][400002], lazy[3][400002];
struct qu
{
    int st, dr, pi;
};
qu vq[150002];
bool cmp(qu a, qu b)
{
    return a.dr < b.dr;
}
int ans[150002];
void propagate(int zona, int nod, int st, int dr)
{
    if(!lazy[zona][nod])
        return;
    aint[zona][nod] += lazy[zona][nod];
    if(st != dr)
    {
        lazy[zona][nod << 1] += lazy[zona][nod];
        lazy[zona][nod << 1|1] += lazy[zona][nod];
    }
    lazy[zona][nod] = 0;
}
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[1][nod] = v[st];
        aint[2][nod] = v[st];
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    aint[1][nod] = max(aint[1][nod << 1], aint[1][nod << 1|1]);
    aint[2][nod] = min(aint[2][nod << 1], aint[2][nod << 1|1]);
}
void update(int nod, int st, int dr, int L, int R, int val)
{
    if(L <= st && dr <= R)
    {
        lazy[1][nod] += val;
        lazy[2][nod] -= val;
        propagate(1, nod, st, dr);
        propagate(2, nod, st, dr);
        return;
    }
    propagate(1, nod, st, dr);
    propagate(2, nod, st, dr);
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, val);
    update(nod << 1|1, mid+1, dr, L, R, val);
    aint[1][nod] = max(aint[1][nod << 1], aint[1][nod << 1|1]);
    aint[2][nod] = min(aint[2][nod << 1], aint[2][nod << 1|1]);
}
int ans1 = 0, ans2 = 0;
void query(int nod, int st, int dr, int L, int R)
{
    propagate(1, nod, st, dr);
    propagate(2, nod, st, dr);
    if(L <= st && dr <= R)
    {
        ans1 = max(ans1, aint[1][nod]);
        ans2 = min(ans2, aint[2][nod]);
        return;
    }
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    query(nod << 1, st, mid, L, R);
    query(nod << 1|1, mid + 1, dr, L, R);
    aint[1][nod] = max(aint[1][nod << 1], aint[1][nod << 1|1]);
    aint[2][nod] = min(aint[2][nod << 1], aint[2][nod << 1|1]);
}
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    for(int i = 1; i <= q; ++i)
        f >> vq[i].st >> vq[i].dr, vq[i].pi = i;
    sort(vq + 1, vq + q + 1, cmp);
    build(1, 1, n);
    deque<pair<int, int> >mini, maxi;
    int poz = 1;
    for(int i = 1; i <= n; ++i)
    {
        int stt = i, drr = i;
        while(!mini.empty() && v[i] <= v[mini.back().second])
        {
            update(1, 1, n, mini.back().first, mini.back().second, -(v[i] - v[mini.back().second]));
            stt = mini.back().first;
            mini.pop_back();
        }
        mini.push_back({stt, drr});
        stt = i, drr = i;
        while(!maxi.empty() && v[i] >= v[maxi.back().second])
        {
            update(1, 1, n, maxi.back().first, maxi.back().second, v[i] - v[maxi.back().second]);
            stt = maxi.back().first;
            maxi.pop_back();
        }
        maxi.push_back({stt, drr});
        while(poz <= q && vq[poz].dr == i)
        {
            ans1 = -(1<<30), ans2 = (1<<30);
            query(1, 1, n, vq[poz].st, vq[poz].dr);
            ans[vq[poz].pi] = ans1 + ans2;
            ++poz;
        }
    }
    for(int i = 1; i <= q; ++i)
        g << ans[i] << '\n';
    return 0;
}

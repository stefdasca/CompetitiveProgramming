/*
        IOI 05-mountains

    * read the input and find the ends of the ranges asked in the queries and create segments which cover some part of the intervals
    Example: if you have ends 5 8 12 17 22 23, create these ranges: [5, 5], [6, 7], [8, 8], [9, 11], [12, 12], [13, 16], [17, 17], [18, 21], [22, 22], [23, 23]
    * after you created the segments, we can implement the updates using segment tree and lazy propagation
    * for each query, you need to binary search the first point such that the max sum subarray is bigger than h, and afterwards you can do some math to find the answer

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
set<int>s;
int n, vst[800002], vdr[800002], pz;
struct stt
{
    int lazy, mrk;
    int sum;
    int mx;
};
stt aint[3200002];
int nr = 0;
struct input
{
    char tip;
    int h;
    int a, b, d;
};
input v2[200002];
int cb(int val)
{
    int st = 1;
    int dr = pz;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(vst[mid] <= val)
            st = mid + 1, ans = mid;
        else
            dr = mid - 1;
    }
    return ans;
}
void propagate(int nod, int st, int dr)
{
    aint[nod].sum = aint[nod].lazy * (vdr[dr] - vst[st] + 1);
    if(aint[nod].sum < 0)
        aint[nod].mx = 0;
    else
        aint[nod].mx = aint[nod].sum;
    if(st < dr)
    {
        aint[nod << 1].lazy = aint[nod].lazy;
        aint[nod << 1|1].lazy = aint[nod].lazy;
        aint[nod << 1].mrk = 1;
        aint[nod << 1|1].mrk = 1;
    }
    aint[nod].lazy = 0;
    aint[nod].mrk = 0;
}
void update(int nod, int st, int dr, int L, int R, int val)
{
    if(L <= st && dr <= R)
        aint[nod].lazy = val, aint[nod].mrk = 1;
    if(aint[nod].mrk)
        propagate(nod, st, dr);
    if(L <= st && dr <= R)
        return;
    if(dr < L || st > R)
        return;
    int mid = (st + dr) / 2;
    update(nod << 1, st, mid, L, R, val);
    update(nod << 1|1, mid+1, dr, L, R, val);
    aint[nod].sum = aint[nod << 1].sum + aint[nod << 1|1].sum;
     aint[nod].mx = max(0, max(aint[nod << 1].mx, aint[nod << 1].sum + aint[nod << 1|1].mx));
}
int Find(int nod, int st, int dr, int mx)
{
    if(aint[nod].mrk)
        propagate(nod, st, dr);
    if(dr <= mx)
        return aint[nod].sum;
    if(st > mx)
        return 0;
    int mid = (st + dr) / 2;
    int anss = Find(nod << 1, st, mid, mx) + Find(nod << 1|1, mid+1, dr, mx);
    aint[nod].sum = aint[nod << 1].sum + aint[nod << 1|1].sum;
    aint[nod].mx = max(0, max(aint[nod << 1].mx, aint[nod << 1].sum + aint[nod << 1|1].mx));
    return anss;
}
int aa, bb, sum;
void Find2(int nod, int st, int dr, int mx)
{
    if(aint[nod].mrk)
        propagate(nod, st, dr);
    if(dr <= mx)
    {
        aa = max(sum + aint[nod].mx, aint[nod].mx);
        bb = max(bb, aa);
        sum += aint[nod].sum;
        return;
    }
    if(st > mx)
        return;
    int mid = (st + dr) / 2;
    Find2(nod << 1, st, mid, mx);
    Find2(nod << 1|1, mid+1, dr, mx);
    aint[nod].sum = aint[nod << 1].sum + aint[nod << 1|1].sum;
    aint[nod].mx = max(0, max(aint[nod << 1].mx, aint[nod << 1].sum + aint[nod << 1|1].mx));
}
int cbsol(int val)
{
    int st = 1;
    int dr = pz;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        aa = 0;
        bb = 0;
        sum = 0;
        Find2(1, 1, pz, mid);
        if(bb >= val)
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(cin >> v2[++nr].tip)
    {
        if(v2[nr].tip == 'E')
            break;
        if(v2[nr].tip == 'I')
            cin >> v2[nr].a >> v2[nr].b >> v2[nr].d, s.insert(v2[nr].a), s.insert(v2[nr].b);
        if(v2[nr].tip == 'Q')
            cin >> v2[nr].h;
    }
    for(set<int> ::iterator it = s.begin(); it != s.end(); ++it)
    {
        if(pz != 0 && *it - 1 > vst[pz])
        {
            vst[++pz] = vst[pz-1] + 1;
            vdr[pz] = *it - 1;
        }
        vst[++pz] = *it;
        vdr[pz] = *it;
    }
    for(int i = 1; i < nr; ++i)
    {
        if(v2[i].tip == 'I')
        {
            int x = cb(v2[i].a);
            int y = cb(v2[i].b);
            update(1, 1, pz, x, y, v2[i].d);
        }
        else
        {
            if(aint[1].mx <= v2[i].h)
                cout << n << '\n';
            else
            {
                int ans = cbsol(v2[i].h+1);
                int xa = Find(1, 1, pz, ans);
                int ya = Find(1, 1, pz, ans-1);
                int raport = (xa - ya) / (vdr[ans] - vdr[ans-1]);
                int diff = v2[i].h - ya;
                int ansss = vdr[ans-1];
                if(raport)
                    ansss += diff / raport;
                cout << ansss << '\n';
            }
        }
    }
    return 0;
}


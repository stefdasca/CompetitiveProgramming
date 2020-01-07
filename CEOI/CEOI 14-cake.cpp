/*
        CEOI 14-cake

    Let's use segment tree to solve this task. One can observe that we are going to eat before we eat cake i all the cakes between a and i
and some cakes on the other side.

    Basically, let's find the biggest value in range (a+1, i) or (i, a-1) - depends on whether a < i or a > i(a = i, a = 1 and a = n can be
dealt with using some ifs).

    Then, we are going to binary search for the closest value to a on the other side which is bigger than the maximum value computed previously.
Since O(log^2 n) per query is too slow, we are going to do the binary search inside the segment tree(two different implementations for the two halves
of the segment tree).

    When updating the values at the first step, one has to be careful to avoid updating the same element twice.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int n, a, v[250002], whr[250002];

int q;

int aint[1000002], poz[1000002];

vector<pair<int, int> >top;

void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        poz[nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    if(st >= a)
    {
        if(aint[nod << 1] >= aint[nod << 1|1])
            aint[nod] = aint[nod << 1], poz[nod] = poz[nod << 1];
        else
            aint[nod] = aint[nod << 1|1], poz[nod] = poz[nod << 1|1];
    }
    else
        if(aint[nod << 1] > aint[nod << 1|1])
            aint[nod] = aint[nod << 1], poz[nod] = poz[nod << 1];
        else
            aint[nod] = aint[nod << 1|1], poz[nod] = poz[nod << 1|1];
}

void upd(int nod, int st, int dr, int pz, int val)
{
    if(st == dr)
    {
        aint[nod] = val;
        poz[nod] = st;
        return;
    }
    int mid = (st + dr) / 2;
    if(pz <= mid)
        upd(nod << 1, st, mid, pz, val);
    else
        upd(nod << 1|1, mid+1, dr, pz, val);
    if(st >= a)
    {
        if(aint[nod << 1] >= aint[nod << 1|1])
            aint[nod] = aint[nod << 1], poz[nod] = poz[nod << 1];
        else
            aint[nod] = aint[nod << 1|1], poz[nod] = poz[nod << 1|1];
    }
    else
        if(aint[nod << 1] > aint[nod << 1|1])
            aint[nod] = aint[nod << 1], poz[nod] = poz[nod << 1];
        else
            aint[nod] = aint[nod << 1|1], poz[nod] = poz[nod << 1|1];
}

int qumx(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
        return aint[nod];
    int mid = (st + dr) / 2;
    return max(qumx(nod << 1, st, mid, L, R), qumx(nod << 1|1, mid+1, dr, L, R));
}
int mxval;
int query1(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return -1;
    if(aint[nod] < mxval)
        return -1;
    if(st == dr)
        return poz[nod];
    int mid = (st + dr) / 2;
    int ans = query1(nod << 1|1, mid+1, dr, L, R);
    if(ans != -1)
        return ans;
    return query1(nod << 1, st, mid, L, R);
}

int query2(int nod, int st, int dr, int L, int R)
{
    if(dr < L || st > R)
        return -1;
    if(aint[nod] < mxval)
        return -1;
    if(st == dr)
        return poz[nod];
    int mid = (st + dr) / 2;
    int ans = query2(nod << 1, st, mid, L, R);
    if(ans != -1)
        return ans;
    return query2(nod << 1|1, mid+1, dr, L, R);
}
map<int, int> wazz;
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], whr[v[i]] = i;
    for(int i = 1; i <= n; ++i)
        top.pb({i, whr[i]});
    build(1, 1, n);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        char tip;
        cin >> tip;
        if(tip == 'E')
        {
            int poz, plz;
            cin >> poz >> plz;
            deque<pair<int, int> >vals;
            wazz.clear();
            wazz[poz] = 1;
            while(vals.size() + 1 < plz)
            {
                if(wazz.find(top.back().se) != wazz.end())
                    top.pop_back();
                else
                    wazz[top.back().se] = 1, vals.push_front(top.back()), top.pop_back();
            }
            upd(1, 1, n, poz, top.back().fi + 1);
            top.pb({top.back().fi + 1, poz});
            while(!vals.empty())
            {
                upd(1, 1, n, vals.front().se, top.back().fi + 1);
                top.pb({top.back().fi + 1, vals.front().se});
                vals.pop_front();
            }
        }
        else
        {
            int poz;
            cin >> poz;
            if(poz == a)
                cout << 0 << '\n';
            else
            {
                if(a == 1 || a == n)
                    cout << abs(poz - a) << '\n';
                else
                    if(poz > a)
                    {
                        int ans = poz - a;
                        mxval = qumx(1, 1, n, a + 1, poz);
                        int p2 = query1(1, 1, n, 1, a - 1);
                        if(p2 == -1)
                            p2 = 0;
                        ans += a - 1 - p2;
                        cout << ans << '\n';
                    }
                    else
                    {
                        int ans = a - poz;
                        mxval = qumx(1, 1, n, poz, a - 1);
                        int p2 = query2(1, 1, n, a + 1, n);
                        if(p2 == -1)
                            p2 = n + 1;
                        ans += p2 - a - 1;
                        cout << ans << '\n';
                    }
            }
        }
    }
    return 0;
}

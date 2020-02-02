/*
        Balkan 12-BestTeams

    We can sort the queries in increasing order of age. Now we can observe that it's optimal to greedily take the people with the best skill,
as long as we didn't take the next one in order of skill(if we took skill_i according to sorted order, we can't take skill_(i-1)).

    In order to handle this, we need to keep a set with the intervals we already added in our data structure. In order to handle the updates regarding
uniting intervals, we have to use several fenwick trees which handle sum queries.

    In order to find the answer for a query, we have to binary search for the biggest place such that we can still select k people to form a team(or
the answer will be 0 otherwise).

    For more details regarding the casework, check out the source code.

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

using namespace std;

typedef long long ll;

int n;

int ord[300002];

ll sp[300002], sp2[300002];
pair<int, int> v[300002];

int cb(int val)
{
    int st = 1;
    int dr = n;
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(ord[mid] <= val)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}

int q;
ll ans[300002];
struct qu
{
    int max_age, nr;
    int pi;
};
qu vq[300002];
bool cmp(qu a, qu b)
{
    return a.max_age < b.max_age;
}


ll ts, aib[300002], td, sd[300002], totctt, ctt[300002], totctt2, ctt2[300002];

// update the sum + number of elements

void upd(int nod, ll val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += val;
}
ll compute(int nod)
{
    ll ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}

void upd3(int nod, int val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        ctt[nod] += val;
}
int compute3(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += ctt[nod];
    return ans;
}

// update the sum + number of elements removed

void upd2(int nod, ll val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        sd[nod] += val;
}
ll compute2(int nod)
{
    ll ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += sd[nod];
    return ans;
}

void upd4(int nod, int val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        ctt2[nod] += val;
}
int compute4(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += ctt2[nod];
    return ans;
}

set<pair<int, int> >s;
ll badsum(pair<int, int> a)
{
    if(a.fi % 2 == 0)
        return sp2[a.fi - 1] - sp2[a.se - 1];
    return sp[a.fi - 1] - sp[a.se - 1];
}
int evil(pair<int, int> a)
{
    if(a.fi == a.se)
        return 0;
    int fi = a.fi - 1;
    int lst = a.se + (a.se % 2 != fi % 2);
    return (fi - lst + 2) / 2;
}
void unify(pair<int, int> a, pair<int, int> b)
{
    upd4(a.fi, -evil(a));
    upd2(a.fi, -badsum(a));
    td -= badsum(a);
    totctt2 -= evil(a);
    s.erase(a);

    upd4(b.fi, -evil(b));
    upd2(b.fi, -badsum(b));
    td -= badsum(b);
    totctt2 -= evil(b);
    s.erase(b);

    a.fi = b.fi;
    s.insert(a);
    td += badsum(a);
    totctt2 += evil(a);
    upd4(a.fi, evil(a));
    upd2(a.fi, badsum(a));
    return;
}
void baga(int nr)
{
    int true_pos = cb(nr);
    ++totctt;
    upd3(true_pos, 1);
    if(s.empty())
    {
        s.insert({true_pos, true_pos});
        upd(true_pos, nr);
        ts += nr;
    }
    else
    {
        s.insert({true_pos, true_pos});
        upd(true_pos, nr);
        ts += nr;
        set<pair<int, int> > ::iterator it = s.lower_bound({true_pos, true_pos});
        if(it != s.begin())
        {
            --it;
            if((*it).fi == true_pos - 1)
                unify((*it), {true_pos, true_pos});
        }
        it = s.upper_bound({true_pos, true_pos});
        if(it != s.end())
        {
            if((*it).se == true_pos + 1)
            {
                set<pair<int, int> > ::iterator it2 = s.lower_bound({true_pos, true_pos});
                if(it2 == s.end() || *it2 > make_pair(true_pos, true_pos))
                    --it2;
                unify(*it2, *it);
            }
        }
    }
}
int countnd(int poz)
{
    ll ans = compute3(poz) - compute4(poz);
    set<pair<int, int> > ::iterator it2 = s.lower_bound({poz, 0});
    if(it2 != s.end())
    {
        pair<int, int> seg = *it2;
        if(seg.se > poz || seg.fi == poz);
        else
        {
            int start_evil = seg.fi - 1;
            int be = poz - (start_evil % 2 != poz % 2);
            int end_evil = seg.se + (start_evil % 2 != seg.se % 2);
            ans -= (be - end_evil + 2) / 2;
        }
    }
    return ans;
}

ll evaluate(int poz)
{
    if(poz == 0)
        return 0;
    ll ans = compute(poz) - compute2(poz);
    set<pair<int, int> > ::iterator it2 = s.lower_bound({poz, 0});
    if(it2 != s.end())
    {
        pair<int, int> seg = *it2;
        if(seg.se > poz || seg.fi == poz);
        else
        {
            int start_evil = seg.fi - 1;
            int be = poz - (start_evil % 2 != poz % 2);
            int end_evil = seg.se + (start_evil % 2 != seg.se % 2);
            if(start_evil % 2 == 0)
                ans = ans - sp[be] + sp[end_evil - 1];
            else
                ans = ans - sp2[be] + sp2[end_evil - 1];
        }
    }
    return ans;
}
ll solve_query(int val)
{
    ll st = 1;
    ll dr = n;
    ll ans = 1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(totctt - totctt2 - countnd(mid) >= val)
            ans = mid + 1, st = mid + 1;
        else
            dr = mid - 1;
    }
    return ts - td - evaluate(ans - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].fi >> v[i].se, ord[i] = v[i].se;
    sort(v + 1, v + n + 1);
    sort(ord + 1, ord + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        sp2[i] = sp2[i-1];
        sp[i] = sp[i-1];
        if(i % 2 == 1)
            sp2[i] += ord[i];
        else
            sp[i] += ord[i];
    }
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> vq[i].max_age >> vq[i].nr;
        vq[i].pi = i;
    }
    sort(vq + 1, vq + q + 1, cmp);
    int pz = 1;
    for(int i = 1; i <= q; ++i)
    {
        while(pz <= n && v[pz].fi <= vq[i].max_age)
            baga(v[pz].se), ++pz;
        ans[vq[i].pi] = solve_query(vq[i].nr);
    }
    for(int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
    return 0;
}

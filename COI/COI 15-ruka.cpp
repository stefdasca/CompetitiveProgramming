/*
        COI 15-Ruka

    * friendly note: My solution is not the intended one but I believe it's easier to understand(even though it's hard to implement as well)

    * Let's solve the problem using sqrt decomposition + merge sort tree. I will repeat this algorithm once at O(sqrt Q) queries by rebuilding
everything from the scratch.

    * Because we have a cursor which is moving, we can simplify the problem by splitting the n points in 3 categories, from the left to the right:
        1. points for which we are sure that we won't touch them(we can keep prefix sums to solve the problem for the respective range)
        2. points which will be modified in the current group(at most sqrt Q points, even though if we grow the bucket size the algorithm will run faster)
        3. points for which we are also sure that we won't touch them, but they're in right of the points in group 2(we can use the mergesort tree here)

    * During one such query, we will consider the updates already done and we are going to answer in O(1) for the points in group 1,
O(sqrt Q) for the points in group 2 and O(log ^2 n) for the points in group 3.

    * For implementation details, check the source code.
*/
#include<bits/stdc++.h>
#define fi first
#pragma GCC optimize("Ofast")
#define se second
using namespace std;
int n, q, buk;
char tip;
int poz = 1;
int prefixx[100002], prefixy[100002], ans[100002];
int Le, Ri;
pair<int, int> dir[100002], xx[100002], yy[100002];
vector<vector<int> >aint[2];
int last_answer;
struct st
{
    char c;
    int a, b;
};
st vov[300002];
void build(int nod, int st, int dr)
{
    aint[0][nod].resize(dr - st + 1), aint[1][nod].resize(dr - st + 1);
    if(st == dr)
    {
        aint[0][nod][0] = (xx[st].se);
        aint[1][nod][0] = (yy[st].se);
        return;
    }
    int mid = (st + dr) / 2;
    build(nod << 1, st, mid);
    build(nod << 1|1, mid+1, dr);
    int pa = 0;
    int pb = 0;
    int pop = 0;
    while(pa < aint[0][nod << 1].size() && pb < aint[0][nod << 1|1].size())
    {
        if(aint[0][nod << 1][pa] <= aint[0][nod << 1|1][pb])
            aint[0][nod][pop] = aint[0][nod << 1][pa], ++pa;
        else
            aint[0][nod][pop] = aint[0][nod << 1|1][pb], ++pb;
        ++pop;
    }
    while(pa < aint[0][nod << 1].size())
        aint[0][nod][pop] = aint[0][nod << 1][pa], ++pa, ++pop;
    while(pb < aint[0][nod << 1|1].size())
        aint[0][nod][pop] = aint[0][nod << 1|1][pb], ++pb, pop++;
    pa = 0;
    pb = 0;
    pop = 0;
    while(pa < aint[1][nod << 1].size() && pb < aint[1][nod << 1|1].size())
    {
        if(aint[1][nod << 1][pa] <= aint[1][nod << 1|1][pb])
            aint[1][nod][pop] = aint[1][nod << 1][pa], ++pa, ++pop;
        else
            aint[1][nod][pop] = aint[1][nod << 1|1][pb], ++pb, ++pop;
    }
    while(pa < aint[1][nod << 1].size())
        aint[1][nod][pop] = aint[1][nod << 1][pa], ++pa, ++pop;
    while(pb < aint[1][nod << 1|1].size())
        aint[1][nod][pop] = aint[1][nod << 1|1][pb], ++pb, ++pop;
}
int orgx, orgy;
void rebuild(int nrq, int start_poz)
{
    Le = Ri = start_poz;
    for(int i = nrq; i <= q; ++i)
    {
        if(vov[i].c == 'B')
        {
            start_poz = max(1, start_poz - 1);
            Le = min(Le, start_poz);
        }
        if(vov[i].c == 'F')
        {
            start_poz = min(n, start_poz + 1);
            Ri = max(Ri, start_poz);
        }
        if(Ri - Le + 1 >= 2500)
            break;
    }
    prefixx[0] = 1; prefixy[0] = 1;
    for(int i = max(1, start_poz - 2700); i <= n; ++i)
    {
        ans[i] = ans[i-1];
        if(prefixx[i-1] > 0 && prefixx[i-1] + dir[i].fi < 0)
            ++ans[i];
        if(prefixx[i-1] < 0 && prefixx[i-1] + dir[i].fi > 0)
            ++ans[i];
        if(prefixy[i-1] > 0 && prefixy[i-1] + dir[i].se < 0)
            ++ans[i];
        if(prefixy[i-1] < 0 && prefixy[i-1] + dir[i].se > 0)
            ++ans[i];
        prefixx[i] = prefixx[i-1] + dir[i].fi;
        prefixy[i] = prefixy[i-1] + dir[i].se;
    }
    orgx = prefixx[Ri];
    orgy = prefixy[Ri];
    for(int i = 1; i <= n - (Ri + 1) + 1; ++i)
    {
        xx[i] = {max(prefixx[Ri + i], prefixx[Ri + i - 1]), min(prefixx[Ri + i], prefixx[Ri + i - 1])};
        yy[i] = {max(prefixy[Ri + i], prefixy[Ri + i - 1]), min(prefixy[Ri + i], prefixy[Ri + i - 1])};
    }
    sort(xx + 1, xx + n - (Ri + 1) + 1 + 1);
    sort(yy + 1, yy + n - (Ri + 1) + 1 + 1);
    if(Ri != n)
        build(1, 1, n - (Ri + 1) + 1);
}
int queryx(int nod, int st, int dr, int L, int R, int threshold)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
    {
        int st1 = 0;
        int dr1 = aint[0][nod].size() - 1;
        int ans = -1;
        if(aint[0][nod].back() < threshold)
            return aint[0][nod].size();
        if(aint[0][nod][0] >= threshold)
            return 0;
        while(st1 <= dr1)
        {
            int mid = (st1 + dr1) / 2;
            if(aint[0][nod][mid] < threshold)
                ans = mid, st1 = mid + 1;
            else
                dr1 = mid - 1;
        }
        return (ans + 1);
    }
    int mid = (st + dr) / 2;
    return queryx(nod << 1, st, mid, L, R, threshold) + queryx(nod << 1|1, mid+1, dr, L, R, threshold);
}
int queryy(int nod, int st, int dr, int L, int R, int threshold)
{
    if(dr < L || st > R)
        return 0;
    if(L <= st && dr <= R)
    {
        int st1 = 0;
        int dr1 = aint[1][nod].size() - 1;
        int ans = -1;
        if(aint[1][nod].back() < threshold)
            return aint[0][nod].size();
        if(aint[1][nod][0] >= threshold)
            return 0;
        while(st1 <= dr1)
        {
            int mid = (st1 + dr1) / 2;
            if(aint[1][nod][mid] < threshold)
                ans = mid, st1 = mid + 1;
            else
                dr1 = mid - 1;
        }
        return (ans + 1);
    }
    int mid = (st + dr) / 2;
    return queryy(nod << 1, st, mid, L, R, threshold) + queryy(nod << 1|1, mid+1, dr, L, R, threshold);
}
int solve(int minii)
{
    int start = minii - 1;
    int sol = ans[start];
    int sumx = prefixx[start];
    int sumy = prefixy[start];
    bool op = 0;
    for(int i = minii; i <= Ri; ++i)
    {
        op = 1;
        if(sumx > 0 && sumx + dir[i].fi < 0)
            ++sol;
        if(sumx < 0 && sumx + dir[i].fi > 0)
            ++sol;
        if(sumy > 0 && sumy + dir[i].se < 0)
            ++sol;
        if(sumy < 0 && sumy + dir[i].se > 0)
            ++sol;
        sumx += dir[i].fi;
        sumy += dir[i].se;
        prefixx[i] = sumx;
        prefixy[i] = sumy;
        ans[i] = sol;
    }
    if(Ri != n)
    {
        int st = 1;
        int dr = n - Ri;
        int ans = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(xx[mid].fi >= -(sumx - orgx))
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        if(ans != 0)
            sol += queryx(1, 1, n - Ri, ans, n - Ri, -(sumx - orgx));
        st = 1;
        dr = n - Ri;
        ans = 0;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(yy[mid].fi >= -(sumy - orgy))
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        if(ans != 0)
            sol += queryy(1, 1, n - Ri, ans, n - Ri, -(sumy - orgy));
    }
    return sol;
}
void solvegood()
{
    int lq = 0;
    for(int i = 1; i <= q; ++i)
    {
        cin >> vov[i].c;
        if(vov[i].c == 'C')
            cin >> vov[i].a >> vov[i].b;
        if(vov[i].c == 'Q')
            lq = i;
    }
    rebuild(1, poz);
    last_answer = -1;
    int minii = Ri + 1;
    for(int i = 1; i <= lq; ++i)
    {
        char tip = vov[i].c;
        if(tip == 'B')
            poz = max(1, poz - 1);
        if(tip == 'F')
            poz = min(poz + 1, n);
        if(tip == 'Q')
        {
            if(last_answer == -1)
                last_answer = solve(minii);
            cout << last_answer << '\n';
            minii = Ri + 1;
        }
        if(tip == 'C')
        {
            int a = vov[i].a, b = vov[i].b;
            dir[poz] = {a, b};
            minii = min(minii, poz);
            last_answer = -1;
        }
        if(poz < Le || poz > Ri)
        {
            last_answer = -1;
            rebuild(i, poz);
            minii = Ri + 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> dir[i].fi >> dir[i].se;
    cin >> q;
    aint[0].resize(280000);
    aint[1].resize(280000);
    solvegood();
    return 0;
}

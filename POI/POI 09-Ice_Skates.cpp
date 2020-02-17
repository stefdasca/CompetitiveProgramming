/*
        POI 09-Ice_Skates

    One can observe that we can't have a subarray of length r with sum bigger than k * r, so we initialize every element with -k,
and at each step one has to update the value of the element(add cnt to arr[wh]).

    From this point on, the problem becomes equivalent to finding the max subarray sum with updates.

    The updates can be handled with segment tree, as follows:

    ssmax -> max subarray sum
    ssmaxl -> prefix with max subarray sum
    ssmaxr -> suffix with max subarray sum
    sum -> subtree sum

    Merging two nodes is a matter of casework, https://codeforces.com/blog/entry/56416?#comment-401219 is a good source to learn about
this specific problem.

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

int n, q, k, r;
ll arr[200002];
struct aint
{
    ll ssmax, ssmaxl, ssmaxr, sum;
};
aint v[800002];
void build(int nod, int st, int dr)
{
    if(st == dr)
    {
        v[nod].ssmax = arr[st];
        v[nod].ssmaxl = arr[st];
        v[nod].ssmaxr = arr[st];
        v[nod].sum = arr[st];
        return;
    }
    int mid = ((st + dr) >> 1);
    build(nod << 1, st, mid);
    build(nod << 1 | 1, mid+1, dr);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].ssmaxl = max(v[nod].sum, max(v[nod << 1].ssmaxl, v[nod << 1].sum + v[nod << 1 | 1].ssmaxl));
    v[nod].ssmaxr = max(v[nod].sum, max(v[nod << 1 | 1].ssmaxr, v[nod << 1 | 1].sum + v[nod << 1].ssmaxr));
    v[nod].ssmax = max(v[nod << 1].ssmax, v[nod << 1 | 1].ssmax);
    v[nod].ssmax = max(v[nod].ssmax, max(v[nod].ssmaxl, v[nod].ssmaxr));
    v[nod].ssmax = max(v[nod].ssmax, v[nod << 1].ssmaxr + v[nod << 1 | 1].ssmaxl);
}
void update(int nod, int st, int dr, int pos, ll val)
{
    if(st == dr)
    {
        v[nod].ssmax = val;
        v[nod].ssmaxl = val;
        v[nod].ssmaxr = val;
        v[nod].sum = val;
        return;
    }
    int mid = ((st + dr) >> 1);
    if(pos <= mid)
        update(nod << 1, st, mid, pos, val);
    else
        update(nod << 1 | 1, mid+1, dr, pos, val);
    v[nod].sum = v[nod << 1].sum + v[nod << 1 | 1].sum;
    v[nod].ssmaxl = max(v[nod].sum, max(v[nod << 1].ssmaxl, v[nod << 1].sum + v[nod << 1 | 1].ssmaxl));
    v[nod].ssmaxr = max(v[nod].sum, max(v[nod << 1 | 1].ssmaxr, v[nod << 1 | 1].sum + v[nod << 1].ssmaxr));
    v[nod].ssmax = max(v[nod << 1].ssmax, v[nod << 1 | 1].ssmax);
    v[nod].ssmax = max(v[nod].ssmax, max(v[nod].ssmaxl, v[nod].ssmaxr));
    v[nod].ssmax = max(v[nod].ssmax, v[nod << 1].ssmaxr + v[nod << 1 | 1].ssmaxl);
}
int L, R;
long long sol, ssm, ss, prv, prv2;
void qu(int nod, int st, int dr)
{
    if(st > R || dr < L)
        return;
    if(L <= st && dr <= R)
    {
        sol = max(sol, v[nod].ssmax);
        if(ssm == -(1LL<<60))
            ssm = max(v[nod].ssmaxr, v[nod].sum);
        else
        {
            sol = max(sol, ssm + v[nod].ssmaxl);
            ssm = max(ssm + v[nod].sum, max(v[nod].ssmaxr, v[nod].sum));
        }
        sol = max(sol, ssm);
        return;
    }
    int mid = (st + dr) >> 1;
    qu(nod << 1, st, mid);
    qu(nod << 1 | 1, mid+1, dr);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> k >> r;
    for(int i = 1; i <= n; ++i)
        arr[i] = -k;
    build(1, 1, n);
    int nrneg = 0;
    for(int i = 1; i <= q; ++i)
    {
        int cnt, wh;
        cin >> wh >> cnt;
        arr[wh] += cnt;
        update(1, 1, n, wh, arr[wh]);
        cout << ((v[1].ssmax <= 1LL * k * r) ? "TAK" : "NIE") << '\n';
    }
    return 0;
}

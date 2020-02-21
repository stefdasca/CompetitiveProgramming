/*
        POI 14-Supercomputer

    Let's find the depth of each node, and count the number of nodes on each level, as well as the max height of the tree.

    We can create a function, f_i(x) = i * x + count of nodes at depth bigger or equal to x.

    Since our functions are of form ax + b, this means that each function has a single range where it has the maximum value among all the functions,
so we can introduce them in stack in increasing order of i. Since we have a function for each possible depth, we don't have to sort them by a.

    Finding the ranges is done in a similar fashion with the algorithm used for finding offline CHT(convex hull trick).

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

int n, q, qu[1000002], ans[1000002], cnt[1000002], tt[1000002], lvl[1000002], hmax = 1;

struct functii
{
    int a, b, st, dr;
};

int ub(int a, int b)
{
    return (a + b - 1) / b;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
        cin >> qu[i];
    lvl[1] = 1, cnt[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        cin >> tt[i];
        lvl[i] = lvl[tt[i]] + 1;
        hmax = max(hmax, lvl[i]);
        ++cnt[lvl[i]];
    }
    int sum = n;
    deque<functii> d;
    for(int i = 1; i <= n, sum > 0; ++i)
    {
        sum -= cnt[i];
        functii f = {i, sum, 1, n};
        while(!d.empty())
        {
            functii bk = d.back();
            int k = ub(bk.b - f.b, f.a - bk.a);
            if(k <= bk.st)
                d.pop_back();
            else
            {
                d.back().dr = k - 1;
                f.st = k;
                break;
            }
        }
        d.pb(f);
    }
    for(int i = 0; i < d.size(); ++i)
        for(int j = d[i].st; j <= d[i].dr; ++j)
            ans[j] = d[i].a + ub(d[i].b, j);
    for(int i = 1; i <= q; ++i)
        if(qu[i] > n)
            cout << hmax << " ";
        else
            cout << ans[qu[i]] << " ";
    return 0;
}


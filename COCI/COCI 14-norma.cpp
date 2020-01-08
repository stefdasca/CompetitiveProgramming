/*
                COCI 14-Norma

    Let's keep the relevant values in two distinct deques, one for minimum and one for maximum. In order for these two deques to be efficient,
we also need other four deques to be created.

    spmin - deque to keep prefix sums of values of minimum in range [1, i], value of spmin[x] can be found using binary search. Similarly,
spmax works the same for maximum.

    spminusmin - deque to keep prefix sum of values of sum of values x * min[1, x+1]. Like the previous deque, these values can also be found using
binary search. Similarly, spminusmax works the same for maximum.

    Let me define rewrite the answer as sum of (prodplus * i - prodminus), for all i between 1 and n.

    prodplus = sum of product of min[1, j] * max[1, j], for all j between 1 and i.
    prodminus = sum of product of min[1, j] * max[1, j] * (j-1) for all j between 1 and i.

    Now we can observe that at some position i, we will either update only minimum, or maximum deque(the other one will have a point update). When updating
a deque, we will need to binary search the values of sums in range [a, b], this can be done with binary search. When we modify one of the values prodplus
or prodminus, we can update it based on the values in the other deque(max values for min updates and vice versa).

    One has to be careful at several things during implementation, namely at how you compute the sums and the gauss sum necessary for prodminus updates.

    In case you're scared by my rather long source code, one can implement it such that we only need two binary searches instead of four.
Also, you can probably use some slower method such as lazy propagation and segment tree queries, but this may not pass the whole set of testcases.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000000
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 0

using namespace std;

typedef long long ll;


int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int n, v[500002];

int prodplus, prodminus;
deque<int> mini, maxi;
deque<int> spmin, spmax;
deque<int> spminusmin, spminusmax;

int fndsg(int x)
{
    ll ans = 1LL * x * (x+1) / 2;
    return mul(ans, 1);
}

int findspmin(int st, int dr)
{
    int ans = 0;
    int L = 0;
    int R = mini.size() - 1;
    int ansy = 0;
    if(mini[0] >= dr)
        ans = add(ans, mul(dr, v[mini[0]]));
    else
    {
        while(L <= R)
        {
            int mid = (L + R) / 2;
            if(mini[mid] <= dr)
                ansy = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        ans = add(ans, spmin[ansy]);
        if(ansy != mini.size() - 1)
            ans = add(ans, mul(v[mini[ansy+1]], dr - mini[ansy]));
    }
    if(mini[0] >= st)
    {
        ans = add(ans, -mul(st - 1, v[mini[0]]));
        return ans;
    }
    L = 0;
    R = mini.size() - 1;
    int ansx = R;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(mini[mid] >= st)
            ansx = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    ans = add(ans, -spmin[ansx - 1]);
    ans = add(ans, -mul(v[mini[ansx]], st - 1 - mini[ansx-1]));
    return ans;
}

int findspmax(int st, int dr)
{
    int ans = 0;
    int L = 0;
    int R = maxi.size() - 1;
    int ansy = 0;
    if(maxi[0] >= dr)
        ans = add(ans, mul(dr, v[maxi[0]]));
    else
    {
        while(L <= R)
        {
            int mid = (L + R) / 2;
            if(maxi[mid] <= dr)
                ansy = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        ans = add(ans, spmax[ansy]);
        if(ansy != maxi.size() - 1)
            ans = add(ans, mul(v[maxi[ansy+1]], dr - maxi[ansy]));
    }
    if(maxi[0] >= st)
    {
        ans = add(ans, -mul(st - 1, v[maxi[0]]));
        return ans;
    }
    L = 0;
    R = maxi.size() - 1;
    int ansx = R;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(maxi[mid] >= st)
            ansx = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    ans = add(ans, -spmax[ansx - 1]);
    ans = add(ans, -mul(v[maxi[ansx]], st - 1 - maxi[ansx-1]));
    return ans;
}

int findspmin2(int st, int dr)
{
    int ans = 0;
    int L = 0;
    int R = mini.size() - 1;
    int ansy = 0;
    if(mini[0] >= dr)
        ans = add(ans, mul(fndsg(dr - 1), v[mini[0]]));
    else
    {
        while(L <= R)
        {
            int mid = (L + R) / 2;
            if(mini[mid] <= dr)
                ansy = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        ans = add(ans, spminusmin[ansy]);
        if(ansy != mini.size() - 1)
            ans = add(ans, mul(v[mini[ansy+1]], fndsg(dr - 1) - fndsg(mini[ansy] - 1)));
    }
    L = 0;
    R = mini.size() - 1;
    if(mini[0] >= st)
    {
        ans = add(ans, -mul(fndsg(st - 2), v[mini[0]]));
        return ans;
    }
    int ansx = R;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(mini[mid] >= st)
            ansx = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    ans = add(ans, -spminusmin[ansx - 1]);
    ans = add(ans, -mul(v[mini[ansx]], fndsg(st - 2) - fndsg(mini[ansx-1] - 1)));
    return ans;
}

int findspmax2(int st, int dr)
{
    int ans = 0;
    int L = 0;
    int R = maxi.size() - 1;
    int ansy = 0;
    if(maxi[0] >= dr)
        ans = add(ans, mul(fndsg(dr - 1), v[maxi[0]]));
    else
    {
        while(L <= R)
        {
            int mid = (L + R) / 2;
            if(maxi[mid] <= dr)
                ansy = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        ans = add(ans, spminusmax[ansy]);
        if(ansy != maxi.size() - 1)
            ans = add(ans, mul(v[maxi[ansy+1]], fndsg(dr - 1) - fndsg(maxi[ansy] - 1)));
    }
    L = 0;
    R = maxi.size() - 1;
    if(maxi[0] >= st)
    {
        ans = add(ans, -mul(fndsg(st - 2), v[maxi[0]]));
        return ans;
    }
    int ansx = R;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(maxi[mid] >= st)
            ansx = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    ans = add(ans, -spminusmax[ansx - 1]);
    ans = add(ans, -mul(v[maxi[ansx]], fndsg(st - 2) - fndsg(maxi[ansx-1] - 1)));
    return ans;
}

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1)
        {
            mini.pb(1);
            maxi.pb(1);
            spmin.pb(v[i]);
            spmax.pb(v[i]);
            spminusmin.pb(0);
            spminusmax.pb(0);
            prodplus = add(prodplus, mul(v[i], v[i]));
        }
        else
        {
            if(v[i] >= v[i-1])
            {
                int prv = i-1;
                while(!maxi.empty() && v[i] >= v[maxi.back()])
                {
                    if(maxi.size() != 1)
                    {
                        prodplus = add(prodplus, mul(v[i] - v[maxi.back()], findspmin(maxi[maxi.size() - 2] + 1, prv)));
                        prodminus = add(prodminus, mul(v[i] - v[maxi.back()], findspmin2(maxi[maxi.size() - 2] + 1, prv)));
                        spmax.pop_back();
                        spminusmax.pop_back();
                        if(v[maxi[maxi.size() - 2]] > v[i])
                        {
                            spmax.pb(add(spmax.back(), mul(i - maxi[maxi.size() - 2], v[i])));
                            spminusmax.pb(add(spminusmax.back(), mul(add(fndsg(i-1), -fndsg(maxi[maxi.size() - 2] - 1)), v[i])));
                        }
                        prv = maxi[maxi.size() - 2];

                    }
                    else
                    {
                        prodplus = add(prodplus, mul(v[i] - v[maxi.back()], findspmin(1, prv)));
                        prodminus = add(prodminus, mul(v[i] - v[maxi.back()], findspmin2(1, prv)));
                        spmax.pop_back();
                        spminusmax.pop_back();
                        spmax.pb(mul(i, v[i]));
                        spminusmax.pb(mul(fndsg(i-1), v[i]));
                    }
                    maxi.pop_back();
                }
                maxi.pb(i);
                mini.pb(i);
                spmin.pb(add(spmin.back(), v[i]));
                spminusmin.pb(add(spminusmin.back(), mul(v[i], i-1)));
            }
            else
            {
                int prv = i-1;
                while(!mini.empty() && v[i] < v[mini.back()])
                {
                    if(mini.size() != 1)
                    {
                        prodplus = add(prodplus, -mul(v[mini.back()] - v[i], findspmax(mini[mini.size() - 2] + 1, prv)));
                        prodminus = add(prodminus, -mul(v[mini.back()] - v[i], findspmax2(mini[mini.size() - 2] + 1, prv)));
                        spmin.pop_back();
                        spminusmin.pop_back();
                        if(v[mini[mini.size() - 2]] <= v[i])
                        {
                            spmin.pb(add(spmin.back(), mul(i - mini[mini.size() - 2], v[i])));
                            spminusmin.pb(add(spminusmin.back(), mul(add(fndsg(i-1), -fndsg(mini[mini.size() - 2] - 1)), v[i])));
                        }
                        prv = mini[mini.size() - 2];
                    }
                    else
                    {
                        prodplus = add(prodplus, -mul(v[mini.back()] - v[i], findspmax(1, prv)));
                        prodminus = add(prodminus, -mul(v[mini.back()] - v[i], findspmax2(1, prv)));
                        spmin.pop_back();
                        spminusmin.pop_back();
                        spmin.pb(mul(i, v[i]));
                        spminusmin.pb(mul(fndsg(i-1), v[i]));
                    }
                    mini.pop_back();
                }
                maxi.pb(i);
                mini.pb(i);
                spmax.pb(add(spmax.back(), v[i]));
                spminusmax.pb(add(spminusmax.back(), mul(v[i], i-1)));
            }
            prodplus = add(prodplus, mul(v[i], v[i]));
            prodminus = add(prodminus, mul(v[i], mul(v[i], i-1)));
        }
        ans = add(ans, mul(prodplus, i));
        ans = add(ans, -prodminus);
    }
    cout << ans;
    return 0;
}

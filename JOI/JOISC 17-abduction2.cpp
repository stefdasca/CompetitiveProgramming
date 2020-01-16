/*
        JOISC 17-abduction2

    Let's precompute using sparse table the maximum value for all ranges of length 2^i.

    Using this precomputing, now we can use a recursive approach to solve the problem(memoization is also necessary).

    In order to find the next maximum, we can binary search the position by querying the sparse table we just created.

*/
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;

int h, w, q, vh[50002], vw[50002];
int rmqL[20][50002], rmqC[20][50002];
int aa, bb;

map<pair<pair<int, int>, int>, ll> mp;

ll solve(int L, int C, int dir)
{
    if(mp.find({{L, C}, dir}) != mp.end())
        return mp[{{L, C}, dir}];
    ll ans = 0;
    if(dir == 0)
    {
        int cd = L;
        int init = vw[C];
        for(int i = aa; i >= 0; --i)
        {
            if(cd - (1<<i) + 1 >= 1)
            {
                if(rmqL[i][cd - (1<<i) + 1] > init);
                else
                    cd -= (1<<i);
            }
        }
        if(!(cd == 0 || cd > h))
        {
            int dif = L - cd + 1;
            if(C > 1)
                ans = max(ans, dif + solve(cd, C - 1, 3));
            if(C < w)
                ans = max(ans, dif + solve(cd, C + 1, 1));
        }
        else
            ans = max(ans, 1LL * L - 1);
   //     cout << L << " " << C << " " << dir << " " << cd << " " << ans << '\n';
    }
    if(dir == 2)
    {
        int cd = L;
        int init = vw[C];
        for(int i = aa; i >= 0; --i)
        {
            if(cd + (1<<i) - 1 <= h)
            {
                if(rmqL[i][cd] > init);
                else
                    cd += (1<<i);
            }
        }
        if(!(cd == 0 || cd > h))
        {
            int dif = cd - L + 1;
            if(C > 1)
                ans = max(ans, dif + solve(cd, C - 1, 3));
            if(C < w)
                ans = max(ans, dif + solve(cd, C + 1, 1));
        }
        else
            ans = max(ans, 1LL * h - L);
    //    cout << L << " " << C << " " << dir << " " << cd << " " << ans << '\n';
    }
    if(dir == 1)
    {
        int cd = C;
        int init = vh[L];
        for(int i = bb; i >= 0; --i)
        {
            if(cd + (1<<i) - 1 <= w)
            {
                if(rmqC[i][cd] > init);
                else
                    cd += (1<<i);
            }
        }
        if(!(cd == 0 || cd > w))
        {
            int dif = cd - C + 1;
            if(L > 1)
                ans = max(ans, dif + solve(L - 1, cd, 0));
            if(L < h)
                ans = max(ans, dif + solve(L + 1, cd, 2));
        }
        else
            ans = max(ans, 1LL * w - C);
   //     cout << L << " " << C << " " << dir << " " << cd << " " << ans << '\n';
    }
    if(dir == 3)
    {
        int cd = C;
        int init = vh[L];
        for(int i = bb; i >= 0; --i)
        {
            if(cd - (1<<i) + 1 >= 1)
            {
                if(rmqC[i][cd - (1<<i) + 1] > init);
                else
                    cd -= (1<<i);
            }
        }
        if(!(cd == 0 || cd > w))
        {
            int dif = C - cd + 1;
            if(L > 1)
                ans = max(ans, dif + solve(L - 1, cd, 0));
            if(L < h)
                ans = max(ans, dif + solve(L + 1, cd, 2));
        }
        else
            ans = max(ans, 1LL * C - 1);
     //   cout << L << " " << C << " " << dir << " " << cd << " " << ans << '\n';
    }
    mp[{{L, C}, dir}] = ans;
    return ans;
}
int main()
{
    cin >> h >> w >> q;
    for(int i = 1; i <= h; ++i)
        cin >> vh[i], rmqL[0][i] = vh[i];
    for(int i = 1; i <= w; ++i)
        cin >> vw[i], rmqC[0][i] = vw[i];
    for(int i = 1; (1<<i) <= h; ++i)
    {
        aa = i;
        for(int j = 1; j + (1<<i) - 1 <= h; ++j)
            rmqL[i][j] = max(rmqL[i-1][j], rmqL[i-1][j + (1<<(i-1))]);
    }
    for(int i = 1; (1<<i) <= w; ++i)
    {
        bb = i;
        for(int j = 1; j + (1<<i) - 1 <= w; ++j)
            rmqC[i][j] = max(rmqC[i-1][j], rmqC[i-1][j + (1<<(i-1))]);
    }
    for(int i = 1; i <= q; ++i)
    {
        int L, C;
        cin >> L >> C;
        ll ans = 0;
        if(L > 1)
            ans = max(ans, 1 + solve(L-1, C, 0));
        if(C < w)
            ans = max(ans, 1 + solve(L, C+1, 1));
        if(L < h)
            ans = max(ans, 1 + solve(L+1, C, 2));
        if(C > 1)
            ans = max(ans, 1 + solve(L, C-1, 3));
        cout << ans << '\n';
    }
    return 0;
}

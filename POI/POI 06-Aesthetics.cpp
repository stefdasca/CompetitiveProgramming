/*

                POI 06-Aesthetics

    Let's solve this task using DP. Let ans[j][i] be the best answer we can get, if the last sequence chosen is formed from elements in range [i, j].
This can be computed easily in O(n^3) but that's not enough. However, we can optimize the complexity to O(n^2 log n) using prefix sums and binary search.

    Let's keep for a position x all the good subarray sums(sums not bigger than m) in sorted order. Using ans[i][j], we can create prefix sums where we
will keep min in range [1, i] and in range [j, number of good subarrays ending in x]. Because we have to deal with absolute value, we have to do a "normalization".
Namely, if we have a value sol and the corresponding subarray sum is p, we will update the first prefix sum array with ans[j][i] + m - p, and the second
one with ans[i][j] + p.

    Why are we doing this? Because we can now assume that our sum is every value we want, and finding ans[j][i] based on the answers found at step (i-1)
is easy now with one binary search.

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

// #define fisier

using namespace std;

typedef long long ll;

int m, n, v[2002], sp[2002];

int vals[2002][2002], sz[2002], ans[2002][2002], poz[2002][2002];

int mini[2002][2002], minidr[2002][2002];

void build(int pz)
{
    for(int i = pz; i >= 1; --i)
    {
        int am = sp[pz] - sp[i-1] + (pz - i);
        if(am <= m)
            vals[pz][++sz[pz]] = am, poz[pz][sz[pz]] = i;
    }
    for(int i = 1; i <= sz[pz]; ++i)
    {
        if(i == 1)
            mini[pz][i] = ans[pz][poz[pz][i]] + m - vals[pz][i];
        else
            mini[pz][i] = min(mini[pz][i-1], ans[pz][poz[pz][i]] + m - vals[pz][i]);
    }
    for(int i = sz[pz]; i >= 1; --i)
    {
        if(i == sz[pz])
            minidr[pz][i] = ans[pz][poz[pz][i]] + vals[pz][i];
        else
            minidr[pz][i] = min(minidr[pz][i+1], ans[pz][poz[pz][i]] + vals[pz][i]);
    }
}
int binsearch(int wh, int val)
{
    int st = 1;
    int dr = sz[wh];
    int ans = 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(vals[wh][mid] <= val)
            ans = mid, st = mid + 1;
        else
            dr = mid - 1;
    }
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
    cin >> m >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        sp[i] = sp[i-1] + v[i];
    int anss = 210000000;
    int lps = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i; j >= 1; --j)
        {
            int am = sp[i] - sp[j-1] + (i - j);
            if(am > m)
                break;
            if(j == 1)
            {
                if(i == n)
                    anss = 0;
                continue;
            }
            int pz = binsearch(j - 1, am);
            int vaa = 210000000;
            int vbb = 210000000;
            if(pz != 0)
                vaa = mini[j-1][pz] - (m - am);
            if(pz != sz[j-1])
                vbb = minidr[j-1][pz+1] - am;
            if(i == n)
                anss = min(anss, min(vaa, vbb));
            if(j != 1)
                ans[i][j] = min(vaa, vbb);
        }
        build(i);
    }
    cout << anss;
    return 0;
}

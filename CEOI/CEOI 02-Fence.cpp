/*
    CEOI 02-Fence

    Let's define dp[i][j][0/1] to be the number of permutations of the first n numbers such that first element is j and the next element
is smaller(0) or bigger(1) than j.

    dp[1][1][1] = 1;
    dp[i][1][0] = 0;
    dp[i][j][0] = dp[i][j-1][0] + dp[i-1][j-1][1];
    dp[i][j][1] = dp[i][i - j + 1][0];

    Detailed proof of the DP is here(https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2002/fence-sol.pdf),
but the main idea is that by fixing the first element, we will simply reduce the permuation of length i to a permutation of length i-1.

    In order to find the kth smallest permutation, we can iterate through the positions while dealing with the following cases:

    1) pos = 0 => we have to fix the first element, drop dp[n][i][0] and dp[n][i][1] while possible
    2) pos = 1 => we have to fix whether our permutation will go like (up down up down ....) or (down up down up ...)
    3) pos != n-1 => we have to check either smaller elements (if we have ... down up) or bigger elements otherwise
    4) pos = n-1 => fix the last element


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

int n;

ll dp[22][22][2], nr;

int v[22], poz;

bool pus[22];
void build(int sz, ll rm)
{
    pus[v[poz]] = 1;
    if(poz == n-1)
    {
        for(int i = 1; i <= n; ++i)
            if(!pus[i])
                v[poz+1] = i;
        return;
    }
    if(poz == 0)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(rm > dp[sz][i][0] + dp[sz][i][1])
                rm = rm - dp[sz][i][1] - dp[sz][i][0];
            else
            {
                v[++poz] = i;
                build(sz - 1, rm);
                break;
            }
        }
    }
    else
        if(poz == 1)
        {
            int cnt = 0;
            for(int i = 1; i <= n; ++i)
            {
                if(!pus[i])
                {
                    ++cnt;
                    if(rm > (i < v[poz]) * dp[sz][cnt][1] + (i > v[poz]) * dp[sz][cnt][0])
                        rm = rm - (i < v[poz]) * dp[sz][cnt][1] - (i > v[poz]) * dp[sz][cnt][0];
                    else
                    {
                        v[++poz] = i;
                        build(sz - 1, rm);
                        break;
                    }
                }
            }
        }
        else
            if(poz >= 2)
            {
                if(v[poz - 1] > v[poz])
                {
                    int cnt = 0;
                    for(int i = 1; i <= n; ++i)
                    {
                        if(!pus[i])
                        {
                            ++cnt;
                            if(i > v[poz])
                            {
                                if(rm > dp[sz][cnt][0])
                                    rm = rm - dp[sz][cnt][0];
                                else
                                {
                                    v[++poz] = i;
                                    build(sz - 1, rm);
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                {
                    int cnt = 0;
                    for(int i = 1; i <= n; ++i)
                    {
                        if(!pus[i])
                        {
                            ++cnt;
                            if(i < v[poz])
                            {
                                if(rm > dp[sz][cnt][1])
                                    rm = rm - dp[sz][cnt][1];
                                else
                                {
                                    v[++poz] = i;
                                    build(sz - 1, rm);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1][1][1] = 1;
    for(int i = 2; i <= 20; ++i)
    {
        for(int j = 2; j <= i; ++j)
            dp[i][j][0] = dp[i][j-1][0] + dp[i-1][j-1][1];
        for(int j = 1; j <= i; ++j)
            dp[i][j][1] = dp[i][i - j + 1][0];
    }
    int t;
    cin >> t;
    for(; t; --t)
    {
        cin >> n >> nr;
        memset(pus, 0, sizeof(pus));
        memset(v, 0, sizeof(v));
        poz = 0;
        build(n, nr);
        for(int i = 1; i <= n; ++i)
            cout << v[i] << " ";
        cout << '\n';
    }
    return 0;
}

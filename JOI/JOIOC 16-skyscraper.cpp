/*
        JOIOC 16-skyscraper

    The solution is described in detail here(https://codeforces.com/blog/entry/47764).

    Here's a quick resume:

    * We are going to use component dp to solve the problem(the dp recurrence is described below).
    * Basically, we are going to simplify a bit the value we need to limit by processing the numbers in the array in increasing order.
    * At some step, we will consider the sum to be equal to the value of the sum we already fixed + (2 * j - 1) * (v[i+1] - v[i]),
because we have to add the current element to the permutation. Then, based on where we will add the new element, we are going to have some cases
(they are described in the dp recurrence)

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

int n, maxsum;
ll v[102];

ll dp[102][102][1002][3];
/*
    dp[i][j][k][l]:
    i - number of numbers placed
    j - number of connected components
    k - total sum currently (filling empty spaces with a_{i} (0-indexed)
    l - number of endpoints that are filled
*/

int solve(int i, int j, int k, int l)
{
    if(i > 0 && (j < 1 || l > 2 || k > maxsum)) // invalid conditions
        return 0;
    if(i == n) // necessary conditions for the permutation to be valid
        return (j == 1 && l == 2);
    if(dp[i][j][k][l] != -1) // already visited state
        return dp[i][j][k][l];
    int s = (v[i + 1] - v[i]) * (2 * j - l) + k; // the extra sum we must add to the current sum
    dp[i][j][k][l] = 0;
    dp[i][j][k][l] = add(dp[i][j][k][l], mul((j + 1 - l), solve(i + 1, j + 1, s, l))); // we are going to create a new component
    dp[i][j][k][l] = add(dp[i][j][k][l], mul((2 - l), solve(i + 1, j, s, l + 1))); // we add the current number at one of the borders and we have a component next to border
    dp[i][j][k][l] = add(dp[i][j][k][l], mul((2 - l), solve(i + 1, j + 1, s, l + 1))); // we add the current number at one of the borders and we don't a component next to border
    dp[i][j][k][l] = add(dp[i][j][k][l], mul((j - 1), solve(i + 1, j - 1, s, l))); // we are going to unify two components
    dp[i][j][k][l] = add(dp[i][j][k][l], mul((2 * j - l), solve(i + 1, j, s, l))); // we are going to attach the current element to the end of one component
    return dp[i][j][k][l];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> maxsum;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1); // we are going to run the dp in increasing order of the values
    if(n == 1) // special case
    {
        cout << 1;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    v[0] = v[1];
    cout << solve(0, 0, 0, 0);
    return 0;
}

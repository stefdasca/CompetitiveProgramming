/*
        Baltic 16-Swap

    One can observe that the swaps form a binary tree, so we can use DP to solve the problem easily

    Let dp[i][j] = minimal permutation of nodes in subtree of i if node i has been set to j

    There are at most O(nlogn) states, O(subtree size) per transition, therefore the
total complexity is O(n log^2 n), because we are in a binary tree.

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

int n, a[200002];
vector<int> dp[200002][36], v1, v2;
bool v[200002][36];

void mrg(vector<int> &v, vector<int> &a, vector<int> &b)
{
    for(int stp=1, i=0, j=0; i<a.size() || j<b.size(); i+=stp, j+=stp, stp*=2)
    {
        for(int k = 0; k < stp && i+k < a.size(); ++k)
            v.push_back(a[i+k]);
        for(int k = 0; k < stp && j+k < b.size(); ++k)
            v.push_back(b[j+k]);
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
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    v[1][0] = 1;
    for(int i = 1; 2 * i + 1 <= n; ++i)
        for(int j = 0; j < 36; ++j)
        {
            if(!v[i][j])
                continue;
            int b = (i >> (j / 2)) ^ (j & 1);
            if(a[2*i+1] < a[b] && a[2*i+1] < a[2*i])
                v[2*i][0] = v[2*i+1][j+2] = v[2*i][j+2] = v[2*i+1][1]=1;
            else
                v[2*i][(j+2) * (a[b] > a[2*i])] = v[2*i+1][0] = 1;
        }
    for(int i = n; i >= 1; --i)
    {
        for(int j = 0; j < 36; ++j)
        {
            if(!v[i][j])
                continue;
            int b = (i >> (j / 2)) ^ (j & 1);
            if(2 * i + 1 <= n)
            {
                if(a[2*i+1] < a[b] && a[2*i+1] < a[2*i])
                {
                    v1 = {a[2*i+1]};
                    v2 = {a[2*i+1]};
                    mrg(v1, dp[2*i][0], dp[2*i+1][j+2]);
                    mrg(v2, dp[2*i][j+2], dp[2*i+1][1]);
                    dp[i][j] = min(v1, v2);
                }
                else
                {
                    dp[i][j] = {min(a[b], a[2*i])};
                    mrg(dp[i][j], dp[2*i][(j+2) * (a[b]>a[2*i])], dp[2*i+1][0]);
                }
            }
            else
                if(2 * i <= n)
                    dp[i][j] = {min(a[b], a[2*i]), max(a[b], a[2*i])};
                else
                    dp[i][j] = {a[b]};
        }
        if(2 * i + 1 <= n)
            for(int j = 0; j <= 1; ++j)
                for(int k = 0; k <= 35; ++k)
                    if(v[2 * i + j][k])
                        vector<int>().swap(dp[2 * i + j][k]);
    }
    for(int i = 0; i < dp[1][0].size(); ++i)
        cout << dp[1][0][i] << " ";
    return 0;
}

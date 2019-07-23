#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int a, b, used[500002];
vector<int>v[4];
bool can(int mid, int a, int b)
{
    while(mid)
    {
        if(max(a, b) < mid)
            return 0;
        if(a >= b)
            a -= mid;
        else
            b -= mid;
        --mid;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> a >> b;
    int be = 0;
    int e = 500000;
    int mx = 0;
    while(be <= e)
    {
        int mid = (be+e)/2;
        if(can(mid, a, b))
            mx = mid, be = mid + 1;
        else
            e = mid - 1;
    }
    while(mx)
    {
        if(a >= b)
            v[1].push_back(mx), a -= mx;
        else
            v[2].push_back(mx), b -= mx;
        --mx;
    }
    for(int i = 1; i <= 2; ++i)
    {
        cout << v[i].size() << '\n';
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << '\n';
    }
    return 0;
}

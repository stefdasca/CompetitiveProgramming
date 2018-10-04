#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long n;
int sum(long long nr)
{
    int sol = 0;
    while(nr)
        sol += nr%10, nr /= 10;
    return sol;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    int sol = 0;
    for(int i = 1; i <= 110; ++i)
    {
        deque<int>v;
        long long x = i;
        while(x)
        {
            if(x > 9)
                v.push_front(9), x-=9;
            else
                v.push_front(x), x=0;
        }
        long long aa = 0;
        for(int i = 0; i < v.size(); ++i)
            aa = aa * 10 + v[i];
        if(aa <= n)
        {
            sol = max(sol, i + sum(n - aa));
        }
    }
    cout << sol;
    return 0;
}

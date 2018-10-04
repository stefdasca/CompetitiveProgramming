#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int v[200002];
int v2[200002];
long long sol;
deque<int>mx;
deque<int>mn;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        cin >> v2[i];
    for(int i = 1, j = 1; i <= n; ++i)
    {
        while(!mx.empty() && v[i] >= v[mx.back()])
            mx.pop_back();
        while(!mn.empty() && v2[i] <= v2[mn.back()])
            mn.pop_back();
        mx.push_back(i);
        mn.push_back(i);
        while(j <= i && v[mx.front()] - v2[mn.front()] > 0)
        {
            j++;
            while(!mx.empty() && mx.front() < j)
                mx.pop_front();
            while(!mn.empty() && mn.front() < j)
                mn.pop_front();
        }
        if(!mx.empty() && !mn.empty() && v[mx.front()] == v2[mn.front()])
            sol += min(mx.front(), mn.front()) - j + 1;
    }
    cout << sol << '\n';
    return 0;
}

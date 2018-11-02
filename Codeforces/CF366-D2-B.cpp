#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n, k;
int mini = 1000000000, who = 0;
bool pus[100002];
int v[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
    {
        if(!pus[i])
        {
            int sum = 0;
            int wh = i;
            for(int j = i; j <= n; j += k)
                sum += v[j], pus[j] = 1;
            if(sum < mini)
                mini = sum, who = wh;
        }
    }
    cout << who;
    return 0;
}
}
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n, v[100002];
int pos[100002];
int who[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        v[i] = nr;
        pos[nr] = i;
    }
    who[pos[n]] = 2;
    for(int i = n-1; i >= 1; --i)
    {
        for(int j = pos[i] - i; j > 0; j -= i)
        {
            if(!who[j])
                continue;
            if(who[j] == 2)
                who[pos[i]] = 1;
        }
        for(int j = pos[i] + i; j <= n; j += i)
        {
            if(!who[j])
                continue;
            if(who[j] == 2)
                who[pos[i]] = 1;
        }
        if(!who[pos[i]])
            who[pos[i]] = 2;
    }
    for(int i = 1; i <= n; ++i)
        if(who[i] == 1)
            cout << "A";
        else
            cout << "B";
    return 0;
}

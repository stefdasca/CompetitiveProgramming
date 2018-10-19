#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
int st[1002], dr[1002], pus[1002], sps[1002], spd[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin >> st[i];
    for(int i = 1; i <= n; ++i)
        cin >> dr[i];
    for(int i = 1; i <= n; ++i)
    {
        int mxr = (n-i);
        int mxl = (i-1);
        if(st[i] > mxl || mxr < dr[i])
        {
            cout << "NO";
            return 0;
        }
    }
    int filled = 0;
    int val = n;
    while(filled < n)
    {
        int summin = 4002;
        for(int i = 1; i <= n; ++i)
            if(!pus[i] && st[i] + dr[i] < summin)
                summin = st[i] + dr[i];
        for(int i = 1; i <= n; ++i)
            if(st[i] + dr[i] == summin)
            {
                if(sps[i] != st[i] || spd[i] != dr[i])
                {
                    cout << "NO";
                    return 0;
                }
                pus[i] = val, ++filled;
            }
        for(int i = 1; i <= n; ++i)
            sps[i] = sps[i-1] + (pus[i] != 0);
        for(int i = n; i >= 1; --i)
            spd[i] = spd[i+1] + (pus[i] != 0);
        --val;
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= n; ++i)
        cout << pus[i] << " ";
    return 0;
}

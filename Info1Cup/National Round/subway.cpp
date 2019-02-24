#include<bits/stdc++.h>
using namespace std;
long long k;
long long n;
vector<int>sz;
int tt[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    if(k == 0)
    {
        cout << 1 << '\n';
        cout << 0 << " " << -1;
        return 0;
    }
    while(n * (n - 1) / 2 < k)
        ++n;
    int tr = n;
    cout << n << '\n';
    --n;
    sz.push_back(n);
    k -= n;
    while(k)
    {
        --n;
        while(n > k)
            --n;
        sz.push_back(n);
        k -= n;
    }
    while(sz.size() < tr)
        sz.push_back(0);
    tt[0] = -1;
    int lp = tr - 1;
    for(int i = 0; i < tr; ++i)
    {
        if(sz[i] == 0)
            continue;
        tt[i + 1] = i;
        --sz[i];
        while(sz[i] > sz[i+1])
            tt[lp] = i, --sz[i], --lp;
    }
    for(int i = 0; i < tr; ++i)
        cout << i << " " << tt[i] << '\n';
    return 0;
}

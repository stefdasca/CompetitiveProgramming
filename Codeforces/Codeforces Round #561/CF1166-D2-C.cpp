#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
int v[200002];
long long ans;
int cb(int val)
{
    int L = 1;
    int R = n;
    int a = 0;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(v[mid] <= val)
            a = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    /*
    for(int i = -100; i <= 100; ++i)
    {
        int x = abs(i - 2);
        int y = abs(i + 2);
        if(x > y)
            swap(x, y);
      //  cout << x << " " << y << '\n';
        if(x <= min(abs(i), 2) && max(abs(i), 2) <= y)
            cout << i << " ";
    }
    cout << '\n';
    */
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] == 0)
            continue;
        int xx = abs(v[i]);
        /*
        cout << xx << '\n';
        cout << 2 * xx << " " << (xx/2 - (1-xx%2)) << '\n';
        cout << -(xx/2 + xx%2) << " " << -2 * xx - 1 << '\n';
        */
        ans = ans + cb(2 * xx) - cb(xx/2 - (1 - xx%2));
        ans = ans + cb(-(xx/2 + xx%2)) - cb(-2 * xx - 1);
        ans--;
    }
    cout << ans/2;
    return 0;
}


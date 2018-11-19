#include<bits/stdc++.h>
using namespace std;
int n, k, fr[102], mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        fr[nr]++;
    }
    int fd = 0;
    for(int i = 1; i <= 100; ++i)
    {
        if(fr[i] != 0)
        {
            ++fd;
            if(fr[i] % k == 0)
                mx = max(mx, fr[i]);
            else
                mx = max(mx, (fr[i] / k) * k + k);
        }
    }
    cout << fd * mx - n;
}

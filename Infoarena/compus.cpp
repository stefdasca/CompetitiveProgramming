#include<bits/stdc++.h>
using namespace std;
ifstream f("compus.in");
ofstream g("compus.out");
int n;
long long ans;
int main()
{
    f >> n;
    for(int i = n / 8; i <= (n - 5) / 5; ++i)
    {
        int m = n - (i + 1) * 5;
        if(m > 0)
        {
            int l = max(m - (i - 1) * 2, 0);
            l += (l%2 != m%2);
            if (m >= l * 3)
                ans += (m - l * 3) / 6 + 1;
        }
        else
            ans += (m == 0);
    }
    g << ans << '\n';
    return 0;
}

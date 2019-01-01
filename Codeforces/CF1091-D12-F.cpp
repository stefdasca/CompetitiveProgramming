/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
long long v[100002];
string s;
bool apa;
long long ans, stamina, iarba;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'L')
        {
            ans += v[i];
            stamina -= v[i];
            if (stamina < 0)
            {
                if(apa)
                    ans -= stamina * 3;
                else
                    ans -= stamina * 5;
                stamina = 0;
            }
        }
        if (s[i] == 'W')
        {
            apa = 1;
            stamina += v[i];
            ans += 3 * v[i];
        }
        if (s[i] == 'G')
        {
            stamina += v[i];
            ans += 5 * v[i];
            iarba += 2 * v[i];
        }
        iarba = min(iarba, stamina);
    }
    if (stamina > 0)
    {
        ans -= 4 * iarba/2;
        ans -= 2 * (stamina - iarba)/2;
    }
    cout << ans << '\n';
    return 0;
}


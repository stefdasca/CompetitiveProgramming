#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
long long a, b, modleft[1000002], modright[1000002];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> s;
    cin >> a >> b;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i == 0)
            modleft[i] = ((s[i] - '0') % a);
        else
            modleft[i] = (modleft[i-1] * 10 + (s[i]-'0')) % a;
    }
    int p10 = 1;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        modright[i] = (p10 * (s[i] - '0') + modright[i+1]) % b;
        p10 = (p10 * 10) % b;
    }
    for(int i = 0; i + 1 < s.size(); ++i)
        if(modleft[i] == 0 && modright[i+1] == 0)
        {
            if(s[i+1] == '0')
                continue;
            cout << "YES\n";
            for(int a = 0; a <= i; ++a)
                cout << s[a];
            cout << '\n';
            for(int a = i+1; a < s.size(); ++a)
                cout << s[a];
            return 0;
        }
    cout << "NO";
    return 0;
}

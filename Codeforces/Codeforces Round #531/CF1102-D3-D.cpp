/// 2222 by 1 february, thx

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int n, frq[7];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i)
        frq[s[i] - '0']++;
    if(frq[0] < n/3)
    {
        for(int i = 0; i < n; ++i)
            if(frq[s[i] - '0'] > n/3)
            {
                frq[s[i] - '0']--;
                frq[0]++;
                s[i] = '0';
                if(frq[0] == n/3)
                    break;
            }
    }
    if(frq[2] < n/3)
    {
        for(int i = n-1; i >= 0; --i)
            if(frq[s[i] - '0'] > n/3)
            {
                frq[s[i] - '0']--;
                frq[2]++;
                s[i] = '2';
                if(frq[2] == n/3)
                    break;
            }
    }
    if(frq[1] < n/3)
    {
        if(frq[2] > n/3)
        {
            for(int i = 0; i < n; ++i)
                if(frq[2] > n/3 && s[i] == '2')
                {
                    frq[s[i] - '0']--;
                    frq[1]++;
                    s[i] = '1';
                    if(frq[1] == n/3)
                        break;
                }
        }
        if(frq[0] > n/3)
        {
            for(int i = n-1; i >= 0; --i)
                if(frq[0] > n/3 && s[i] == '0')
                {
                    frq[s[i] - '0']--;
                    frq[1]++;
                    s[i] = '1';
                    if(frq[1] == n/3)
                        break;
                }
        }
    }
    cout << s;
    return 0;
}

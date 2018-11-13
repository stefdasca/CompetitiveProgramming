/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; ++i)
        if(i == n-1)
            s.pop_back(), cout << s;
        else
        {
            if(s[i] > s[i+1])
            {
                for(int j = 0; j < i; ++j)
                    cout << s[j];
                for(int j = i+1; j < n; ++j)
                    cout << s[j];
                return 0;
            }
        }
    return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s;
bool cansq[500002];
bool cancomm[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        cansq[i] = max(cansq[i], cansq[i+1]);
        cancomm[i] = max(cancomm[i], cancomm[i+1]);
        if(s[i] == ']')
            cansq[i] = 1;
        if(cansq[i] && s[i] == ':')
            cancomm[i] = 1;
    }
    int gg = 0;
    int L = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(gg == 0 && s[i] == '[')
            gg = 1, L = 1;
        else
            if(gg == 1 && s[i] == ':')
                gg = 2, L = 2;
            else
                if(gg == 2 && s[i] == '|')
                    ++L;
        if(cancomm[i+1] && gg == 2)
            ans = max(ans, L + 2);
    }
    if(ans == 0)
        cout << -1;
    else
        cout << ans;
    return 0;
}

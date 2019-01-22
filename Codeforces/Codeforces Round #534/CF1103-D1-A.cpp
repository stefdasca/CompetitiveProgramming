#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s;
struct pos
{
    int l, c;
};
pos v[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int C = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '0')
        {
            v[i] = {C, 1};
            if(C == 1)
                C = 3;
            else
                C = 1;
        }
    }
    C = 1;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '1')
        {
            v[i] = {C, 2};
            ++C;
            if(C == 5)
                C = 1;
        }
    }
    for(int i = 0; i < s.size(); ++i)
        cout << v[i].l << " " << v[i].c << '\n';
    return 0;
}


/// Never do the same mistake twice

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
char pos[102];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int leftpos = 0;
    int rightpos = s.size() - 1;
    for(int i = s.size(); i >= 1; --i)
    {
        if(i % 2 == 0)
            pos[i-1] = s[rightpos], --rightpos;
        else
            pos[i-1] = s[leftpos], ++leftpos;
    }
    cout << pos;
    return 0;
}


#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
deque<int>dg;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    while(n)
    {
        dg.push_front(n % 10);
        n /= 10;
    }
    for(int i = 0; i < dg.size(); ++i)
        dg[i] = min(dg[i], 9 - dg[i]);
    if(dg[0] == 0)
        dg[0] = 9;
    for(int i = 0; i < dg.size(); ++i)
        cout << dg[i];
    return 0;
}


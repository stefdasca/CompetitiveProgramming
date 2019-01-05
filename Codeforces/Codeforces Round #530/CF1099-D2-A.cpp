#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int w, h, we[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    int a, b;
    cin >> a >> b;
    we[b] = a;
    cin >> a >> b;
    we[b] = a;
    int gg = w;
    for(int i = h; i >= 0; --i)
    {
        gg += i;
        gg = gg - we[i];
        if(gg < 0)
            gg = 0;
    }
    cout << gg;
    return 0;
}


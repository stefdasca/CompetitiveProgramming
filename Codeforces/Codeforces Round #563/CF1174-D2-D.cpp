#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, x;
set<int>px;
int pxor[10000002];
int val[10000002], nr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    px.insert(0);
    bool ok = 1;
    while(ok)
    {
        ok = 0;
        for(int i = 1; i < (1<<n); i *= 2)
        {
            int poss = (pxor[nr] ^ i);
            if(px.find(poss) != px.end())
                continue;
            int z = (poss ^ x);
            if(px.find(z) != px.end())
                continue;
            ++nr;
            val[nr] = i;
            ok = 1;
            pxor[nr] = (pxor[nr - 1] ^ i);
            px.insert(pxor[nr]);
            break;
        }
    }
    cout << nr << '\n';
    for(int i = 1; i <= nr; ++i)
        cout << val[i] << " ";
    return 0;
}


#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int q;
int nr;
int ans[26] = {0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        int nr;
        cin >> nr;
        int p2 = 1;
        int z = 0;
        while(p2 < nr)
            p2 = p2 * 2 + 1, ++z;
        if(nr != p2)
            cout << p2 << '\n';
        else
        {
            cout << ans[z] << '\n';
        }
    }
    return 0;
}


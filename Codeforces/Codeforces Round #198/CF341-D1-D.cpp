#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, q;
long long bit[5][1002][1002];
void ad(int line, int st, long long vl)
{
    int which = (line % 2) + (st % 2) * 2;
    for(; line <= n; line += (line & (-line)))
        for(int j = st; j <= n; j += (j & (-j)))
            bit[which][line][j] ^= vl;
}
long long que(int line, int st)
{
    int which = (line % 2) + (st % 2) * 2;
    long long ans = 0;
    for(; line; line -= (line & (-line)))
        for(int j = st; j; j -= (j & (-j)))
            ans ^= bit[which][line][j];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= q; ++i)
    {
        int tip, xa, ya, xb, yb;
        cin >> tip >> xa >> ya >> xb >> yb;
        if(tip == 1)
        {
            long long aa = que(xb, yb) ^ que(xa - 1, yb);
            long long bb = que(xb, ya - 1) ^ que(xa - 1, ya - 1);
            cout << (aa ^ bb) << '\n';
        }
        else
        {
            long long nr;
            cin >> nr;
            ad(xa, ya, nr);
            ad(xb + 1, ya, nr);
            ad(xa, yb + 1, nr);
            ad(xb + 1, yb + 1, nr);
        }
    }
    return 0;
}


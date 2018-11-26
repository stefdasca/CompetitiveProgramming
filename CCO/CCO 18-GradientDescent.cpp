/*
    We can compute the answer separately for both x and y axis, the x-coordinate and y-coordinate being the median among the n coordinates,
for each of the axes.
    In order to get 100%, you have to compute the answer for both axis at the same time, taking into account several cases
*/

#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int L = 1, C = 1, b, e, b2, e2;
int query(int L, int C)
{
    int ans;
    cout << "? " << L << " " << C << endl;
    cin >> ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    b = 1;
    e = n;
    b2 = 1;
    e2 = m;
    bool gg = 1;
    bool gg2 = 1;
    while(gg || gg2)
    {
        int mid1, mid2;
        if(gg)
            mid1 = (b + e) / 2;
        else
            mid1 = L;
        if(gg2)
            mid2 = (b2 + e2) / 2;
        else
            mid2 = C;
        int xx = query(mid1, mid2);
        int yy;
        int zz;
        if(gg && mid1 + 1 <= n)
        {
            yy = query(mid1 + 1, mid2);
            if(xx == yy)
                gg = 0, L = mid1;
            else
                if(xx > yy)
                    L = mid1 + 1, b = mid1 + 1;
                else
                    L = mid1, e = mid1;
        }
        if(gg2 && mid2 + 1 <= m)
        {
            zz = query(mid1, mid2 + 1);
            if(xx == zz)
                gg2 = 0, C = mid2;
            else
                if(xx > zz)
                    C = mid2 + 1, b2 = mid2 + 1;
                else
                    C = mid2, e2 = mid2;
        }
        if(b == e)
            gg = 0;
        if(b2 == e2)
            gg2 = 0;
    }
    cout << "! " << query(L, C) << endl;
    return 0;
}

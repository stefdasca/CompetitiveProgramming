#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> order_set;
ifstream fi("pitricele.in");
ofstream fo("pitricele.out");
long long n, g, r, x, ans;
long long g2, r2, x2;
long long sum;
order_set S;
int main()
{
    fi >> n;
    for(long long i = 1; i <= n; ++i)
    {
        fi >> g >> r >> x;
        g ^= ans;
        r ^= ans;
        x ^= ans;
        sum += g;
        S.insert(r + sum);
        long long sol = *S.find_by_order(x-1)-sum;
        fo << sol << '\n';
        ans = sol;
    }
    return 0;
}

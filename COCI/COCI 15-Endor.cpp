/*
        COCI 15-Endor

    Let's assume that instead of changing the directions 180 degrees, the ants will swap eachother, and what
happens will be equivalent(it can be proved easily after reading the statement carefully)

    In order to get the O(n * k) solution, we first need to understand how the O(n^2) solution works.
After observing the statement mentioned above, we can simulate the moves quite easily if we fix the position of the ant which goes 
towards right. 

      That's what we are going to do in the O(n * k) solution, since all the ants having the same color can be reduced to one ant, 
after keeping suffix sums of the starting positions, of the last positions visited and of the count of ants of a given color.

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, k, l;
double ans[52];
struct str
{
    double d;
    int b;
    double lst;
    char c;
};
str v[100002];
double sum[3][42], ult[3][42];
ll ct[3][42];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> l;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].d >> v[i].b >> v[i].c, v[i].lst = v[i].d;
    for(int i = n; i >= 1; --i)
    {
        if(v[i].c == 'D')
        {
            ans[v[i].b] += (1.00000 * l - 1.0000 * v[i].d);
            for(int col = 0; col < k; ++col)
            {
                double intersection_sum = (1.00000 * ct[1][col] * v[i].d + sum[1][col]) * 0.500000;
                ans[col] += ult[1][col] - intersection_sum;
                int new_col = col + v[i].b;
                if(new_col >= k)
                    new_col -= k;
                sum[2][new_col] = sum[1][col];
                ct[2][new_col] = ct[1][col];
                ult[2][new_col] = intersection_sum;
            }
            for(int col = 0; col < k; ++col)
                sum[1][col] = sum[2][col], ct[1][col] = ct[2][col], ult[1][col] = ult[2][col];
        }
        else
        {
            sum[1][v[i].b] += v[i].d;
            ult[1][v[i].b] += v[i].d;
            ct[1][v[i].b] ++;
        }
    }
    for(int i = 0; i <= k-1; ++i)
        ans[i] += ult[1][i];
    for(int i = 0; i <= k-1; ++i)
        cout << fixed << setprecision(1) << ans[i] << '\n';
    return 0;
}


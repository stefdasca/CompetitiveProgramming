/*
        USACO 12nov-cbs-gold

    Let's build prefix sums for each string, 1 = '(', -1 = ')'.

    Two positions (l, r), with l < r form a concurrently balanced subarray if for all i in 1..n the values of prefix sums
are equal and there wasn't a i < j < r such that there is an i in 1..n such that the value of prefix sum in j is smaller
than the value of prefix sum in l-1.

    We can use this information to use a rather classical approach => sort the positions in the string, use RMQ to find the
rightmost position we can expand to and binary search the rightmost position with the same prefix sum values such that it
occurs before the value found in the RMQ binsearch.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("cbs.in");
ofstream g("cbs.out");
int n, sz, df[12][50012], poz[50012];
string s[12];
int v[50002];
bool cmp(int a, int b)
{
    for(int i = 1; i <= n; ++i)
        if(df[i][a] != df[i][b])
            return df[i][a] < df[i][b];
    return a < b;
}
int lg[50012], rmq[12][17][50012];
void build(int wh)
{
    for(int i = 1; i <= sz; ++i)
        rmq[wh][0][i] = df[wh][i];
    for(int i = 1; (1<<i) <= sz; ++i)
        for(int j = 1; j + (1<<i) - 1 <= sz; ++j)
            rmq[wh][i][j] = min(rmq[wh][i-1][j], rmq[wh][i-1][j + (1<<(i-1))]);
}
int query(int wh, int st, int dr)
{
    int dif = dr - st + 1;
    int val = lg[dif];
    return min(rmq[wh][val][st], rmq[wh][val][dr - (1<<val) + 1]);
}
bool ok(int start, int sf)
{
    for(int i = 1; i <= n; ++i)
    {
        int ans = query(i, start, sf);
        if(ans < df[i][start-1])
            return 0;
    }
    return 1;
}
int main()
{
    f >> n >> sz;
    for(int i = 2; i <= sz; ++i)
        lg[i] = lg[i/2] + 1;
    for(int i = 1; i <= n; ++i)
    {
        f >> s[i];
        s[i] = ' ' + s[i];
        for(int j = 1; j <= sz; ++j)
        {
            df[i][j] += (s[i][j] == '(');
            df[i][j] -= (s[i][j] == ')');
            df[i][j] += df[i][j-1];
            v[j] = j;
        }
        build(i);
    }
    sort(v, v + sz + 1, cmp);
    for(int i = 0; i <= sz; ++i)
        poz[v[i]] = i;
    long long cnt = 0;
    for(int start = 1; start <= sz; ++start)
    {
        int L = start;
        int R = sz;
        int ans = L-1;
        while(L <= R)
        {
            int mid = (L + R) / 2;
            if(ok(start, mid))
                ans = mid, L = mid + 1;
            else
                R = mid - 1;
        }
        L = poz[start-1] + 1;
        R = sz;
        int sl = L-1;
        while(L <= R)
        {
            int mid = (L + R) / 2;
            bool ok = 1;
            for(int j = 1; j <= n; ++j)
                if(df[j][start-1] != df[j][v[mid]])
                    ok = 0;
            if(ok)
            {
                if(v[mid] <= ans)
                    sl = mid, L = mid + 1;
                else
                    R = mid - 1;
            }
            else
                R = mid - 1;
        }
        cnt += sl - poz[start-1];
    }
    g << cnt << '\n';
    return 0;
}

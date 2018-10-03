#include<bits/stdc++.h>
using namespace std;
ifstream f("arbsort.in");
ofstream g("arbsort.out");
int n;
string s;
int nec[202],qq;
int dp[202][202][202], sz[202][202], sum[202], szz;
void add(int a[], int &b, int c[], int d)
{
    for(int i = 1; i <= d; ++i)
        a[i] += c[i];
    b = max(b, d);
    for(int i = 1; i <= b; ++i)
        if(a[i] >= 10)
        {
            a[i+1]++;
            a[i]-=10;
            if(i == b)
                ++b;
        }
}
void drop(int a[], int &b, int c[], int d)
{
    for(int i = 1; i <= d; ++i)
        a[i] -= c[i];
    for(int i = 1; i <= b; ++i)
        if(a[i] < 0)
            a[i] += 10, --a[i+1];
    while(a[b] == 0)
        --b;
}
void builddp()
{
    for(int i = 1; i < n; ++i)
        dp[n][i][1] = 1, sz[n][i] = 1;
    for(int i = n-1; i >= 2; --i)
    {
        memset(sum, 0, sizeof(sum));
        szz = 0;
        add(sum, szz, dp[i+1][i], sz[i+1][i]);
        for(int j = i-1; j >= 1; --j)
        {
            add(sum, szz, dp[i+1][j], sz[i+1][j]);
            add(dp[i][j], sz[i][j], sum, szz);
        }
    }
}
int cmp(int a[], int b, int c[], int d)
{
    if(b > d)
        return 1;
    if(b < d)
        return -1;
    for(int i = b; i >= 1; --i)
        if(a[i] > c[i])
            return 1;
        else
            if(a[i] < c[i])
                return -1;
    return 0;
}
int main()
{
    f >> n;
    f >> s;
    g << 0 << " ";
    if(n == 1)
        return 0;
    for(int i = s.size() - 1; i >= 0; --i)
        nec[++qq] = (s[i] - '0');
    builddp();
    int prec = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = prec; j < i; ++j)
        {
            if(cmp(nec, qq, dp[i][j], sz[i][j]) == 1)
                drop(nec, qq, dp[i][j], sz[i][j]);
            else
            {
                g << j << " ";
                prec = j;
                break;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
int chartoint(char x)
{
    if(x <= '9')
        return (x - '0');
    return 10 + (x - 'A');
}
bool mat[5500][5500];
short mx1[5502][5502], mx0[5502][5502];
bool good(int val)
{
    for(int i = val; i <= n; i += val)
        for(int j = val; j <= n; j += val)
            if(mx1[i][j] < val && mx0[i][j] < val)
                return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        for(int j = 0; j < n/4; ++j)
        {
            int val = chartoint(s[j]);
            int p2 = 8;
            for(int x = 4 * j + 1; x <= 4 * j + 4; ++x)
            {
                if(val & p2)
                    mat[i][x] = 1;
                p2 >>= 1;
            }
        }
    }
    vector<int>divisors;
    int ans = 1;
    for(int i = 1; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            divisors.push_back(i);
            if(i * i != n)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i == 1 || j == 1)
                mx1[i][j] = (mat[i][j] == 1);
            else
                if(mat[i][j] == 1)
                    mx1[i][j] = min(mx1[i][j-1], min(mx1[i-1][j], mx1[i-1][j-1])) + 1;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i == 1 || j == 1)
                mx0[i][j] = (mat[i][j] == 0);
            else
                if(mat[i][j] == 0)
                    mx0[i][j] = min(mx0[i][j-1], min(mx0[i-1][j], mx0[i-1][j-1])) + 1;
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; ++i)
        if(mx0[i][i] == i || mx1[i][i] == i)
            mx = i;
    for(int i = divisors.size() - 1; i >= 1; --i)
    {
        if(mx > divisors[i])
            continue;
        if(good(divisors[i]))
        {
            ans = divisors[i];
            break;
        }
    }
    cout << ans;
    return 0;
}



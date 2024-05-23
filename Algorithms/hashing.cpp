/*

  Here is a double hashing template which precomputes powers, hashes and checks how many times string b shows up in string a. 

  It is used to solve String Matching from CSES (https://cses.fi/problemset/task/1753/)

*/
#include <bits/stdc++.h>
using namespace std;

// choosing base and mod for hashes
const int base_1 = 31, mod_1 = 1000000007;
const int base_2 = 9973, mod_2 = 1000000009;

int n, m;
long long hsh[2][1000001], pw[2][1000001];
long long hsh1, hsh2;

int main()
{
    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    
    pw[0][0] = pw[1][0] = 1;
    for(int i = 1; i <= 1000000; i++)
    {
        pw[0][i] = (pw[0][i-1] * base_1) % mod_1;
        pw[1][i] = (pw[1][i-1] * base_2) % mod_2;
    }
    
    for(int i = 0; i < m; i++)
    {
        hsh1 = (hsh1 * base_1 + (b[i] - 'a')) % mod_1;
        hsh2 = (hsh2 * base_2 + (b[i] - 'a')) % mod_2;
    }
    
    for(int i = 0; i < n; i++)
    {
        hsh[0][i+1] = (hsh[0][i] * base_1 + (a[i] - 'a')) % mod_1;
        hsh[1][i+1] = (hsh[1][i] * base_2 + (a[i] - 'a')) % mod_2;
    }
    
    int cnt = 0;
    for(int i = m; i <= n; i++)
    {
        long long hsh_a = (hsh[0][i] - ((hsh[0][i - m] * pw[0][m]) % mod_1) + mod_1) % mod_1;
        long long hsh_b = (hsh[1][i] - ((hsh[1][i - m] * pw[1][m]) % mod_2) + mod_2) % mod_2;
        if(hsh_a == hsh1 && hsh_b == hsh2)
            cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}

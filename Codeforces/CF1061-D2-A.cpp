/*
    Just simple maths, divide s by n and add 1 if s % n > 0
*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    long long sol = s/n + (s % n > 0);
    cout << sol;
    return 0;
}

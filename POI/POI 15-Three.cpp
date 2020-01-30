/*
        POI 15-Three

    solution + proof: https://github.com/thecodingwizard/competitive-programming/blob/master/POI/POI15-Three.cpp

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

int n, ans = 1;
string s;
void one()
{
    int str = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(s[i] == s[i-1])
            ++str;
        else
            str = 1;
        ans = max(ans, str);
    }
}
void two()
{
    int nrB = 0, nrC = 0, nrS = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'B')
            ++nrB;
        else
            if(s[i] == 'C')
                ++nrC;
            else
                nrB = nrC = 0;
        ans = max(ans, nrB + nrC - (nrB == nrC));
    }
    nrB = 0, nrC = 0, nrS = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'B')
            ++nrB;
        else
            if(s[i] == 'S')
                ++nrS;
            else
                nrB = nrS = 0;
        ans = max(ans, nrB + nrS - (nrB == nrS));
    }
    nrB = 0, nrC = 0, nrS = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i] == 'S')
            ++nrS;
        else
            if(s[i] == 'C')
                ++nrC;
            else
                nrS = nrC = 0;
        ans = max(ans, nrS + nrC - (nrS == nrC));
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    s = ' ' + s;
    one();
    two();
    for(int i = 1; i <= 3; ++i)
    {
        int aa = 0, bb = 0, cc = 0;
        for(int j = i; j <= n; ++j)
        {
            aa += (s[j] == 'B');
            bb += (s[j] == 'S');
            cc += (s[j] == 'C');
            if(aa != bb && aa != cc && bb != cc)
                ans = max(ans, j - i + 1);
        }
    }
    for(int i = n; i >= n-3; --i)
    {
        int aa = 0, bb = 0, cc = 0;
        for(int j = i; j >= 1; --j)
        {
            aa += (s[j] == 'B');
            bb += (s[j] == 'S');
            cc += (s[j] == 'C');
            if(aa != bb && aa != cc && bb != cc)
                ans = max(ans, i - j + 1);
        }
    }
    cout << ans;
    return 0;
}

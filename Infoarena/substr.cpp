#include<bits/stdc++.h>
using namespace std;
ifstream fi("substr.in");
ofstream fo("substr.out");
int n, k;
char c[18002];
unordered_map<long long, int>mp;
long long hassh[18002];
long long modpow(long long b, long long ex)
{
    long long sol = 1;
    while(ex)
    {
        if(ex&1)
            sol = (sol * b) % 1000000009;
        b = (b * b) % 1000000009;
        ex >>= 1;
    }
    return sol;
}
long long pw[18002];
bool check(int len)
{
    long long cc = modpow(26, len);
    mp.clear();
    for(int i = 1; i <= n; ++i)
    {
        long long qq = hassh[i];
        if(i >= len)
        {
            qq = (qq + (1000000009 - hassh[i - len]) * cc) % 1000000009;
            mp[qq]++;
            if(mp[qq]>=k)
                return 1;
        }
    }
    return 0;
}
int main()
{
    fi >> n >> k;
    fi >> (c+1);
    hassh[0] = 1;
    for(int i = 1; i <= n; ++i)
        hassh[i] =( hassh[i-1] * 26LL + (c[i] - '0') ) % 1000000009;
    int b = 1;
    int e = n;
    int sol = 0;
    while(b <= e)
    {
        int mid = (b+e)/2;
        if(check(mid))
            sol = mid, b = mid+1;
        else
            e = mid-1;
    }
    fo << sol;
    return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n;
string s;
char c[] = "ACTG";
int tri(char a, char b)
{
    char cc = a;
    int co = 0;
    while(cc != b)
    {
        ++co, --cc;
        if(cc < 'A')
            cc = 'Z';
    }
    cc = a;
    int co2 = 0;
    while(cc != b)
    {
        ++co2, ++cc;
        if(cc > 'Z')
            cc = 'A';
    }
    return min(co, co2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    int mn = (1<<30);
    for(int i = 0; i + 3 < n; ++i)
    {
        int cost = 0;
        for(int j = i; j <= i + 3; ++j)
            cost += tri(s[j], c[j - i]);
        mn = min(mn, cost);
    }
    cout << mn;
    return 0;
}

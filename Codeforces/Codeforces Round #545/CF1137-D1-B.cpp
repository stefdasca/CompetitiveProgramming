#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
string s, t;
int nr1, nr0;
int n, m;
int pi[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> t;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == '1')
            ++nr1;
        else
            ++nr0;
    string a = ' ' + t;
    string b = ' ' + t;
    m = a.size(), n = b.size();
    t = ' ' + t;
    int k = 0;
    for(int i = 2; i < m; ++i)
    {
        while(k && a[k + 1] != a[i])
            k = pi[k];
        if(a[k + 1] == a[i])
            k++;
        pi[i] = k;
    }
    for(int i = 1; i <= s.size(); ++i)
    {
        int pp = i % (n - pi[n-1] - 1);
        if(pp == 0)
            pp = (n - pi[n-1] - 1);
        if(t[pp] == '1')
        {
            if(nr1)
                cout << 1, --nr1;
            else
                cout << 0, --nr0;
        }
        else
        {
            if(nr0)
                cout << 0, --nr0;
            else
                cout << 1, --nr1;
        }
    }
    return 0;
}


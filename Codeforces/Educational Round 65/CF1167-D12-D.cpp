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
int dp1, dp2;
deque<int>d;
deque<int>d2;
bool pus[500002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin >> s;
    d.push_back(1);
    pus[0] = 1;
    dp1 = 1;
    for(int i = 1; i < s.size(); ++i)
    {
        bool ok = 0;
        if(s[i] == '(')
            ok = 1;
        if(ok == 1)
        {
            if(dp1 <= dp2)
                d.push_back(1), pus[i] = 1, ++dp1;
            else
                d2.push_back(1), pus[i] = 0, ++dp2;
        }
        else
        {
            if(dp1 >= dp2)
                d.pop_back(), pus[i] = 1, --dp1;
            else
                d2.pop_back(), pus[i] = 0, --dp2;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << pus[i];
    return 0;
}

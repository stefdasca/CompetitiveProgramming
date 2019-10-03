/*
        AGC011-D

    * After running a bruteforce program, one can observe that if s[0] is A, then we will make it B
and the rest of the letters won't change, and if s[0] is B, then for every i in range 0, n-2,
s[i] will become NOT s[i+1], and s[n-1] will become A if n is odd and B otherwise.
    After negating the even indices, we will be able to solve the problem in O(k) using a deque,
which is not fast enough.

    * But, it's very easy to observe that after at most 2n operations, the strings will have the period at most 2,
thus we are left with running the algorithm for the first min(k, 2n(+1 if k is odd)).

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

int n, k;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    deque<int>d;
    for(int i = 1; i < n; i += 2)
        if(s[i] == 'A')
            s[i] = 'B';
        else
            s[i] = 'A';
    for(int i = 0; i < n; ++i)
        d.pb(i);
    for(int j = 1; j <= min(2 * n, k); ++j)
        if(s[d.front()] == 'A')
            s[d.front()] = 'B';
        else
        {
            int x = d.front();
            d.pop_front();
            if(n % 2 == 0)
                s[x] = 'B';
            else
                s[x] = 'A';
            d.pb(x);
        }
    k -= min(k, 2 * n);
    if(k % 2 == 1)
    {
        if(s[d.front()] == 'A')
            s[d.front()] = 'B';
        else
        {
            int x = d.front();
            d.pop_front();
            if(n % 2 == 0)
                s[x] = 'B';
            else
                s[x] = 'A';
            d.pb(x);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(i & 1)
        {
            if(s[d[i]] == 'A')
                cout << "B";
            else
                cout << "A";
        }
        else
            cout << s[d[i]];
    }
    return 0;
}


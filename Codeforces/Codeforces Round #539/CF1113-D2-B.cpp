#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, v[50002];
int frq[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], frq[v[i]]++, sum += v[i];
    sort(v+1, v+n+1);
    int mx = sum;
    for(int i = 2; i <= 100; ++i)
    {
        for(int j = i; j <= 100; j += i)
        {
            if(!frq[j])
                continue;
            sum -= j;
            --frq[j];
            sum += j/i;
            for(int k = 1; k <= 100; ++k)
                if(frq[k])
                {
                    mx = min(mx, sum + k * i - k);
                    break;
                }
            sum -= j/i;
            sum += j;
            ++frq[j];
        }
    }
    cout << mx;
    return 0;
}

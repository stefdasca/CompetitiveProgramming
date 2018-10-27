#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
long long sum;
long long cate, sumimpar, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        if(nr % 2 == 0)
            sum += nr;
        else
        {
            if(cate == 0)
                mini = nr;
            else
                mini = min(mini, 1LL * nr);
            ++cate;
            sumimpar += nr;
        }
    }
    if(cate % 2 == 1)
        sumimpar -= mini;
    cout << sum + sumimpar;
    return 0;
}

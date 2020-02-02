/*
        USACO 19feb-plat-cowdate

    After doing some brute force or some math on paper, one can observe that if we fix the left end of the range, the sum is a unimodal function.
Therefore, we can use two pointers to solve this problem.

    From this point it's just a matter of doing some math to find the formula for probability to get exactly one cow.

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

#define fisier 1

using namespace std;

typedef long long ll;

int n;
int prob[1000002];

double ans, trr[1000002];
int main()
{

    #ifdef fisier
        ifstream f("cowdate.in");
        ofstream g("cowdate.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        f >> prob[i];
        trr[i] = (0.0000 + prob[i]) / (0.0000 + 1e6);
        ans = max(ans, trr[i]);
    }
    double pr = (1.0000 - trr[1]);
    double sum = trr[1];
    int rp = 1;
    for(int i = 1; i <= n; ++i)
    {
        while(rp < n && sum < sum * (1.0000 - trr[rp+1]) + trr[rp+1] * pr)
            sum = sum * (1.0000 - trr[rp+1]) + trr[rp+1] * pr, ++rp, pr = pr * (1.00000 - trr[rp]);
        ans = max(ans, sum);
        sum = sum - trr[i] * (pr / (1.0000 - trr[i]));
        sum = sum / (1.0000 - trr[i]);
        pr = pr / (1.00000 - trr[i]);
    }
    ans = floor(ans * 1e6 + eps);
    g << ans;
    return 0;
}

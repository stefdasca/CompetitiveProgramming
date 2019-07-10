/// HopelessCoder

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int finall, fp[10002], cati;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    finall = 1;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            finall *= i;
            ++cati;
            while(n % i == 0)
                n /= i, ++fp[cati];
        }
    if(n > 1)
        finall *= n, fp[++cati] = 1;
    cout << finall << " ";
    int op = 0;
    int p2max = 0;
    for(int i = 1; i <= cati; ++i)
    {
        int pp = 1;
        while(pp < fp[i])
            pp *= 2;
        p2max = max(p2max, pp);
    }
    for(int i = 1; i <= cati; ++i)
        if(fp[i] != p2max)
            op = 1;
    while(p2max > 1)
        p2max /= 2, ++op;
    cout << op;
    return 0;
}

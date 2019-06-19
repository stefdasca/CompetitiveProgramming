#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int frq[102];
int frq2[102];
int sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        cin >> nr;
        sum += nr;
        for(int j = 1; j <= 100; ++j)
            frq2[j] = frq[j];
        int sum2 = sum;
        int failures = 0;
        int poz = 100;
        while(sum2 > m)
        {
            if(sum2 - frq2[poz] * poz > m)
                sum2 -= frq2[poz] * poz, failures += frq2[poz], --poz;
            else
            {
                int raport = (sum2 - m) / poz + (((sum2 - m) % poz) > 0);
                failures += raport;
                break;
            }
        }
        frq[nr]++;
        cout << failures << " ";
    }
    return 0;
}


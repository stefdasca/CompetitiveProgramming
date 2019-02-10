#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    vector<long long>divizori;
    vector<long long>putere;
    for(long long i = 2; i * i <= b; ++i)
        if(b % i == 0)
        {
            divizori.push_back(i);
            putere.push_back(0);
            while(b % i == 0)
                putere.back()++, b /= i;
        }
    if(b > 1)
    {
         divizori.push_back(b);
         putere.push_back(1);
    }
    long long mini = (1LL<<60);
    for(int i = 0; i < divizori.size(); ++i)
    {
        long long nn = n;
        long long sum = 0;
        while(nn)
        {
            sum += nn / divizori[i];
            nn /= divizori[i];
        }
        mini = min(mini, sum / putere[i]);
    }
    cout << mini;
    return 0;
}


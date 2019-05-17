#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int t;
vector<long long>nr;
long long a, b, c;
long long p2(int x, int y)
{
    if(x == y)
        return 1;
    return (1LL<<(y - x - 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(; t; --t)
    {
        cin >> a >> b >> c;
        bool found = 0;
        for(int term = 1; term <= 50; ++term)
        {
            nr.clear();
            nr.push_back(a);
            long long s = a;
            while(nr.size() < term)
            {
                if(s + 1 <= b)
                {
                    nr.push_back(s + 1);
                    s = s * 2 + 1;
                }
                else
                    break;
            }
            if(nr.size() < term)
                continue;
            long long ss = nr[0];
            for(int i = 1; i < nr.size(); ++i)
            {
                long long hcba = max(0LL, min(c - (nr[i] - ss), (b - nr.back()) / p2(i, nr.size() - 1)));
                nr[i] += hcba;
                for(int j = i+1; j < nr.size(); ++j)
                {
                    nr[j] = nr[j] + hcba;
                    hcba += hcba;
                }
                ss += nr[i];
            }
            if(nr.back() == b)
            {
                bool oki = 1;
                long long s = a;
                for(int j = 1; j < nr.size(); ++j)
                    if(nr[j] - s <= c)
                        s += nr[j];
                    else
                    {
                        oki = 0;
                        break;
                    }
                if(oki == 0)
                    continue;
                found = 1;
                cout << nr.size() << " ";
                for(int j = 0; j < nr.size(); ++j)
                    cout << nr[j] << " ";
                cout << '\n';
                break;
            }
        }
        if(!found)
            cout << -1 << '\n';
    }
    return 0;
}


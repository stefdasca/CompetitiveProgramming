#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
string s;
deque<string>d;
map<string, int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    d.push_back(s);
    mp[s] = 1;
    int cost = 0;
    --k;
    while(k && d.size())
    {
        string snsd = d[0];
        d.pop_front();
        for(int i = 0; k && i < snsd.size(); ++i)
        {
            string ot9;
            for(int j = 0; j < i; ++j)
                ot9 += snsd[j];
            for(int j = i+1; j < snsd.size(); ++j)
                ot9 += snsd[j];
            if(mp.find(ot9) == mp.end())
                mp[ot9] = 1, d.push_back(ot9), --k, cost += (n - ot9.size());
        }
    }
    if(k)
        cout << -1;
    else
        cout << cost;
    return 0;
}


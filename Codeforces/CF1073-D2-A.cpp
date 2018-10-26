#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
string s;
string s2;
int frq[28];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    cin>>s;
    for(int i = 0; i < s.size(); ++i)
    {
        memset(frq, 0, sizeof(frq));
        s2.clear();
        int ss = 0;
        for(int j = i; j < s.size(); ++j)
        {
            s2 += s[j];
            frq[s[j] - 'a']++;
            ss++;
            bool gg = 1;
            for(int q = 0; q <= 25; ++q)
                if(frq[q] > ss/2)
                    gg = 0;
            if(gg)
            {
                cout << "YES\n";
                cout << s2;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
string s;
bool sch[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i+1] == 'a')
        {
            sch[i] = 1;
            while(i+1 < s.size() && s[i+1] == 'a')
                ++i;
            sch[i] = 1;
        }
    }
    for(int i = 0; i < s.size(); ++i)
        cout << sch[i] << " ";
    return 0;
}

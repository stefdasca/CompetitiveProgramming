/*
    First, you want to know for each ending position how much you need to go to the left in order to get a bessie. In order to get this done, you can create a lookup table which tells you the previous position
a certain character showed up.

    After we did this, we can now define dp[i] as the answer for the substrings ending at position i. Let x be the position (0-indexed) up to which we need to go backwards for a bessie.
    Then, dp[i] = (dp[x] if x >= 0) + (x + 2), as we are off by one because of the indexing and off by one because we take the previous position before it all ended.
*/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

char lit[] = {'b', 'e', 's', 'i'};
int target[] = {0, 1, 2, 2, 3, 1};

int n, prv[4][300002];
long long dp[300002], ans;

int main()
{
    string s;
    cin >> s;
    
    n = s.size();
    
    for(int i = 0; i <= 3; i++)
        prv[i][0] = -1;
    
    for(int i = 0; i < n; i++)
        for(int poz = 0; poz <= 3; poz++)
            if(s[i] == lit[poz])
                prv[poz][i] = i;
            else
                if(i > 0)
                    prv[poz][i] = prv[poz][i-1];
    
    for(int i = 0; i < n; i++)
    {
        int x = i;
        int tgt = 5;
        while(tgt >= 0 && x >= 0)
        {
            int poz = prv[target[tgt]][x];
            if(poz != -1)
                tgt--;
            x = poz - 1;
        }
        if(tgt == -1)
        {
            dp[i] += (x + 2);
            dp[i] += dp[x];
        }
        ans += dp[i];
    }
    
    cout << ans << '\n';
    return 0;
}

/*
        Baltic 05-Ancient

We can use dynamic programming to find the number of solutions for this problem

Let's define dp[i][j][k][p] = number of ways to build the string up to position i, if last letter is
the jth letter in alphabet and we have k consecutive vowels or consonants(depends on j) and p consecutive letters
equal to j. The recurrence relation is based on the next character in the string, whether it's an '*' or a letter.
The transition require just a bit of casework, easy to find. One should also be careful about the cases when either k or
p are bigger than the maximum amount of consecutive characters of a certain type

*/

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int cc, ce, vc, ve;
bool voc[30];
string s;
long long sol, dp[20][27][20][20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> ve >> vc >> ce >> cc;
    cin >> s;
    voc[0] = 1; voc[4] = 1; voc[8] = 1; voc[14] = 1; voc[20] = 1;
    if(s[0] != '*')
        dp[0][(s[0] - 'a')][1][1] = 1;
    else
        for(int i = 0; i <= 25; ++i)
            dp[0][i][1][1] = 1;
    for(int i = 0; i < s.size() - 1; ++i)
    {
        for(int j = 0; j <= 25; ++j)
            for(int k = 0; k <= 4; ++k)
                for(int p = 0; p <= 4; ++p)
                {
                    if(!dp[i][j][k][p])
                        continue;
                    if(voc[j] && (p > ve || k > vc))
                        continue;
                    if(!voc[j] && (p > ce || k > cc))
                        continue;
                    for(int z = 0; z <= 25; ++z)
                    {
                        bool gg = 0;
                        if(s[i+1] == '*' || s[i+1] == ('a' + z))
                            gg = 1;
                        if(!gg)
                            continue;
                        if(z == j)
                             dp[i+1][z][k+1][p+1] += dp[i][j][k][p];
                        else
                        {
                            if(voc[j] == voc[z])
                                dp[i+1][z][k+1][1] += dp[i][j][k][p];
                            else
                                dp[i+1][z][1][1] += dp[i][j][k][p];
                        }
                    }
                }
    }
    for(int i = 0; i <= 25; ++i)
        for(int j = 0; j <= 4; ++j)
            for(int k = 0; k <= 4; ++k)
                if(voc[i] && j <= vc && k <= ve)
                    sol += dp[s.size() - 1][i][j][k];
                else
                    if(!voc[i] && j <= cc && k <= ce)
                        sol += dp[s.size() - 1][i][j][k];
    cout << sol;
    return 0;
}


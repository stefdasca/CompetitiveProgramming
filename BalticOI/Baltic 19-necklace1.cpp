/*
        Baltic 19-necklace1 - only first 3 subtasks

    editorial: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2019_solutions/necklace.sol_.en_.pdf
(the DP approach)

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

// #define fisier 1

using namespace std;

typedef long long ll;

string a, b;
int maxLen, startA, startB;

bool rev;
int lss[3002][3002];
int lsp[3002][3002], lps[3002][3002];
void solve()
{
    memset(lss, 0, sizeof(lss));
    for(int j = 0; j < b.size(); ++j)
        for(int i = 0; i < a.size() && j + i < b.size(); ++i)
            if(a[i] == b[j + i])
                lss[i][j + i] = (i > 0 ? lss[i - 1][j + i - 1] : 0) + 1;
            else
                lss[i][j + i] = 0;
    for(int j = 0; j < a.size(); ++j)
        for(int i = 0; i < b.size() && j + i < a.size(); ++i)
            if(a[i + j] == b[i])
                lss[i + j][i] = (i > 0 ? lss[i + j - 1][i - 1] : 0) + 1;
            else
                lss[i + j][i] = 0;
    memset(lsp, 0, sizeof(lsp));
    memset(lps, 0, sizeof(lps));
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < b.size(); ++j)
        {
            int x = lss[i][j];
            if (x == 0)
                continue;
            if (j - x >= 0)
                lsp[i][j - x] = max(lsp[i][j - x], x);
            if (i - x >= 0)
                lps[i - x][j] = max(lps[i - x][j], x);
        }
    }
    for(int i = 0; i < a.size(); ++i)
        for(int j = 1; j < b.size(); ++j)
            lsp[i][j] = max(lsp[i][j], lsp[i][j - 1] - 1);
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < b.size(); ++j)
        {
            int x = lsp[i][j];
            int y = lps[i][j];
            if(x + y > maxLen)
            {
                maxLen = x + y;
                startA = i - x + 1;
                startB = j - y + 1;
                if(rev)
                    startB = b.size() - (j + x + 1);
            }
        }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a;
    cin >> b;
    solve();
    reverse(b.begin(), b.end());
    rev = 1;
    solve();
    cout << maxLen << '\n';
    cout << startA << " " << startB << '\n';
    return 0;
}

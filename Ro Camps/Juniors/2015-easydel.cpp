/*
    dp[mask] inseamna scorul maxim pe care il putem obtine daca stergem culorile din reprezentarea lui mask
    atunci tranzitiile sunt dp[mask] = max(dp[mask], dp[mask ^ (1 << bit)] + (scorul pe care il adauga stergerea culorii bit));
    precalculam cost[i][j] care inseamna cu cate pozitii o sa se mute cuburile cu culoare j daca stergem cuburile cu culoare i
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1025], mv[12][12];

int main()
{
    ifstream cin("easydel.in");
    ofstream cout("easydel.out");
    
    string s;
    cin >> s;
    
    for(int i = 0; i <= 9; i++)
    {
        int cnt = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if((s[j] - '0') == i)
                cnt++;
            else
                mv[i][s[j] - '0'] += cnt;
        }
    }
    
    for(int i = 0; i <= 1023; i++)
    {
        vector<int> cnt(10);
        vector<int> cost(10);
        
        vector<int> rmv;
        
        for(int q = 0; q <= 9; q++)
            if(i & (1<<q))
                continue;
            else
                rmv.push_back(q);
        
        for(auto a : rmv)
            for(auto b : rmv)
                if(a != b)
                    cost[a] += mv[a][b];
        
        for(int nxt = 0; nxt <= 9; nxt++)
        {
            if((1<<nxt) & i)
                continue;
            dp[i ^ (1<<nxt)] = max(dp[i ^ (1<<nxt)], dp[i] + cost[nxt]);
        }
    }
    
    cout << dp[1023] << '\n';
    return 0;
}

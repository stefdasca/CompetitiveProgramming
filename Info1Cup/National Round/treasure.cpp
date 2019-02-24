/*
    treasure: given a string of n letters and a number k, implement the following algorithm: 
find the first substring with length k which has all letters equal, remove it and concatenate the remaining halves. (n, k <= 2e5)
    
    This task is similar to https://codeforces.com/contest/1104/problem/B
*/

#include<bits/stdc++.h>
using namespace std;
int n, k;
string s;
deque<char>lit;
deque<int>str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < n; ++i)
    {
        if(!lit.empty() && s[i] == lit.back())
        {
            ++str.back();
            if(str.back() == k)
                lit.pop_back(), str.pop_back();
        }
        else
        {
            lit.push_back(s[i]);
            str.push_back(1);
        }
    }
    for(int i = 0; i < lit.size(); ++i)
    {
        for(int j = 1; j <= str[i]; ++j)
            cout << lit[i];
    }
    return 0;
}

/*
        IOI 16-messy

    Use divide and conquer to build a string sequence like this(i attach the n = 8 case here)

        10000000
        01000000
        00100000
        00010000
        10001111
        01001111
        10111111
        11101111
        11111000
        11110100
        11111011
        11111110

    Basically, first 4 strings separate [0, 3] from [4, 7], next 2 separate [0, 1] from [2, 3] and so on.

    Using a similar approach, we can restore the strings in exactly n log n queries.

    Last but not least, one has to be careful at printing the answer.


*/
#include<bits/stdc++.h>
#include<messy.h>
using namespace std;

int N;
int poz[202];
vector<int> pospoz[202][202];
void build(int st, int dr)
{
    if(st == dr)
        return;
    string s;
    for(int i = 0; i < N; ++i)
        s += '1';
    int mid = (st + dr) / 2;
    for(int i = st; i <= dr; ++i)
        s[i] = '0';
    for(int i = st; i <= mid; ++i)
    {
        s[i] = '1';
        add_element(s);
        s[i] = '0';
    }
    build(st, mid);
    build(mid+1, dr);
}
void restore(int st, int dr)
{
    if(st == dr)
    {
        poz[st] = pospoz[st][st][0];
        return;
    }
    string twice;
    for(int i = 0; i < N; ++i)
        twice += '1';
    for(int i = 0; i < pospoz[st][dr].size(); ++i)
        twice[pospoz[st][dr][i]] = '0';
    int mid = (st + dr) / 2;
    for(int i = 0; i < pospoz[st][dr].size(); ++i)
    {
        int pp = pospoz[st][dr][i];
        twice[pp] = '1';
        bool xxx = check_element(twice);
        if(xxx)
            pospoz[st][mid].push_back(pp);
        else
            pospoz[mid+1][dr].push_back(pp);
        twice[pp] = '0';
    }
    restore(st, mid);
    restore(mid+1, dr);
}
vector<int> restore_permutation(int n, int w, int r)
{
    N = n;
    build(0, n-1);
    compile_set();
    for(int i = 0; i < n; ++i)
        pospoz[0][n-1].push_back(i);
    restore(0, n-1);
    vector<int> ans, ans2;
    for(int i = 0; i < n; ++i)
        ans.push_back(poz[i]);
    ans2.resize(n);
    for(int i = 0; i < n; ++i)
        ans2[ans[i]] = i;
    return ans2;
}

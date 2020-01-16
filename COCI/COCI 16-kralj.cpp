/*
        COCI 16-kralj

    One can find the valid points such that we can go from i to i-1 and we won't have any position which can't be filled.

    In case we found one such position, we will run a simple greedy algorithm(at each step, insert the elves which have to fight against dwarf i
and either take the worst elf which can beat the current dwarf, or discard the worst elf).

    Even though this gets full score(https://oj.uz/submission/195613), it has a worst case of O(n^2) in a test like

    1 1 3 3 5 5 .. n-1 n-1
    1 3 5 7 ......... 2n-1
    2 4 6 8 ......... 2n

    So we have to find another optimization. It can be observed by hand or by brute force that the best point to start with is right after the point
with the smallest difference between number of elves which have to fight dwarfs 1, 2, 3, ..., i and i.


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

int n, rival[500002];

int frq[500002], sp[1000002];

vector<int> enemy[500002];
int skill[500002], skill2[500002];

int ans = 0;
set<int> vb;

int solve(int st)
{
    int ss = 0;
    vb.clear();
    for(int i = st; i <= st + n - 1; ++i)
    {
        int truepos = i;
        if(truepos > n)
            truepos -= n;
        for(int j = 0; j < enemy[truepos].size(); ++j)
            vb.insert(skill2[enemy[truepos][j]]);
        if(skill[truepos] > *vb.rbegin())
            vb.erase(vb.begin());
        else
            ++ss, vb.erase(vb.lower_bound(skill[truepos]));
        if(ss + (st + n - 1) - i <= ans)
            return ss;
    }
    return ss;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> rival[i];
    for(int i = 1; i <= n; ++i)
        ++frq[rival[i]], enemy[rival[i]].pb(i);
    for(int i = 1; i <= n; ++i)
        cin >> skill[i];
    for(int i = 1; i <= n; ++i)
        cin >> skill2[i];
    int mn = 1;
    for(int i = 1; i <= n; ++i)
    {
        sp[i] = sp[i-1] + frq[i] - 1;
        if(i >= 2 && sp[i] < sp[mn])
            mn = i;
    }
    mn++;
    if(mn > n)
        mn -= n;
    ans = solve(mn);
    cout << ans;
    return 0;
}

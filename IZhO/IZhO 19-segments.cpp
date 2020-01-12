/*
            IZhO 19-segments

    solution: https://codeforces.com/blog/entry/64479?#comment-484350

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


int n, v[500002];
ll sp[500002];

set<pair<int, int> >s[500002];

int tri(int val, int pz, int pz2)
{
    ll sum = sp[pz2] - sp[pz - 1];
    int st = pz+1;
    int dr = n;
    int ans = -1;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(sp[mid] - sp[pz2] >= sum)
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    return ans;
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
        cin >> v[i];
    for(int i = 1; i <= n; ++i)
        sp[i] = sp[i-1] + v[i];
    for(int i = 1; i <= n; ++i)
    {
        s[i].insert({1, 1});
        int lst = 6969696;
        if(i == n)
        {
            cout << (*s[n].rbegin()).fi << '\n';
            return 0;
        }
        while(!s[i].empty())
        {
            pair<int, int> xx = *s[i].rbegin();
            s[i].erase(xx);
            if(xx.fi == lst)
                continue;
            s[i+1].insert(xx);
            int ans = tri(xx.fi, xx.se, i);
            if(ans != -1)
                s[ans].insert({xx.fi + 1, i + 1});
            if(lst != 6969696)
                break;
            lst = xx.fi;
        }
    }
    return 0;
}

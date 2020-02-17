/*
        NOI 17-rmq

    Sort the queries by the value of the answer, this can be done with counting sort.

    For all the queries with a given answer, we will check the following things in decreasing order of i:

    * Firstly, we must have an element equal to i left in our array, otherwise we don't have a solution.
    * Then, we will find the possible range where we can put an element equal to i and the reunion of the ranges which return us the answer equal to i.
    * If our intersection range is inconsistent(left_end > right_end), then we don't have a solution.
    * If we can't find a position where we can add the element equal to i in range [left_end, right_end], then we also don't have a solution.
    * Now we can assign the elements to their positions. Firstly, let's assign i to the position found at the previous position, then we will
assign elements in decreasing order of their value to the positions still unfilled yet. If at some step we're forced to fill a position with a number
smaller than i, we also don't have a solution.

    After we performed all the queries, if we still didn't fill some of the positions, we have to fill them too. Since those positions didn't occur
in any of the queries from the input, the values assigned are not relevant, so we can assign them in any order we want.

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

int n, q;

set<int> disp, pus;

int arr[100002], rau, op[100002];

vector<pair<int, int> > qu[100002];

int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        disp.insert(i), pus.insert(i);
    for(; q; --q)
    {
        int a, b, x;
        cin >> a >> b >> x;
        qu[x].pb({a, b});
    }
    for(int i = n-1; i >= 0; --i)
    {
        if(!qu[i].size())
            continue;
        int cs = 0, cd = n-1;
        int mins = n-1, maxd = 0;
        for(int j = 0; j < qu[i].size(); ++j)
        {
            cs = max(cs, qu[i][j].fi);
            cd = min(cd, qu[i][j].se);
            mins = min(mins, qu[i][j].fi);
            maxd = max(maxd, qu[i][j].se);
        }
        if(cs > cd)
        {
            rau = 1;
            break;
        }
        set<int> ::iterator it = pus.lower_bound(cs);
        if(it == pus.end() || *it > cd)
        {
            rau = 1;
            break;
        }
        if(disp.find(i) == disp.end())
        {
            rau = 1;
            break;
        }
        arr[*it] = i;
        op[*it] = 1;
        pus.erase(*it);
        disp.erase(i);
        while(1)
        {
            set<int> ::iterator it = pus.lower_bound(mins);
            if(it == pus.end() || *it > maxd)
                break;
            if(*disp.rbegin() < i)
            {
                rau = 1;
                break;
            }
            op[*it] = 1;
            arr[*it] = *disp.rbegin();
            pus.erase(*it);
            disp.erase(*disp.rbegin());
        }
        if(rau)
            break;
    }
    for(int i = 0; i < n; ++i)
        if(!op[i])
        {
            arr[i] = *disp.rbegin();
            disp.erase(*disp.rbegin());
        }
    if(rau)
    {
        for(int i = 0; i < n; ++i)
            cout << -1 << " ";
        cout << '\n';
        return 0;
    }
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << '\n';
    return 0;
}

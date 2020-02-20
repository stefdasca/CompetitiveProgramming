/*
        POI 09-Walk

    We can fix the median part of the palindrome(either one or two edges) and we will extend the palindrome using BFS.
In order to speed up the runtime, we will keep track of the already visited states so we will eventually get a runtime of
O(n^3 * sigma) which is way faster in practical usage.

    For each query, we're going to rebuild the string using track of the previous nodes which were on the path to pair (a, b).

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

string pal[402][402];
int nxtst[402][402];
int nxtdr[402][402];
int len[402][402];
char lit[402][402];
bool viz[402][402];

int len2[402][402][27];

int n, m;

vector<int> v[402][28], tr[402][28];

struct str
{
    int st, dr, ps, lit;
};
deque<str> d;
void bfs()
{
    while(!d.empty())
    {
        str nod = d[0];
        d.pop_front();
        if(nod.ps == 0)
        {
            for(int x = 0; x <= 25; ++x)
            {
                for(int i = 0; i < tr[nod.st][x].size(); ++i)
                {
                    int nst = tr[nod.st][x][i];
                    if(len2[nst][nod.dr][x] == 0)
                    {
                        d.push_back({nod.st, nod.dr, nst, x + 1});
                        len2[nst][nod.dr][x] = len[nod.st][nod.dr] + 1;
                    }
                }
            }
        }
        else
        {
            for(int j = 0; j < v[nod.dr][nod.lit - 1].size(); ++j)
            {
                int ndr = v[nod.dr][nod.lit - 1][j];
                if(viz[nod.ps][ndr])
                    continue;
                viz[nod.ps][ndr] = 1;
                len[nod.ps][ndr] = len[nod.st][nod.dr] + 2;
                nxtst[nod.ps][ndr] = nod.st;
                nxtdr[nod.ps][ndr] = nod.dr;
                lit[nod.ps][ndr] = ('a' + nod.lit - 1);
                d.pb({nod.ps, ndr, 0, 0});
            }
        }
    }
}
void build(int st, int dr)
{
    vector<char> ordine;
    vector<char> ordine2;
    while(len[st][dr])
    {
        if(len[st][dr] == 1)
        {
            ordine.pb(lit[st][dr]);
            break;
        }
        else
        {
            ordine.pb(lit[st][dr]);
            ordine2.pb(lit[st][dr]);
            int aa = nxtst[st][dr];
            int bb = nxtdr[st][dr];
            st = aa;
            dr = bb;
        }
    }
    for(int i = 0; i < ordine.size(); ++i)
        cout << ordine[i];
    for(int i = ordine2.size() - 1; i >= 0; --i)
        cout << ordine2[i];
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        v[a][c - 'a'].pb(b);
        tr[b][c - 'a'].pb(a);
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int x = 0; x <= 25; ++x)
            for(int j = 0; j < v[i][x].size(); ++j)
            {
                int vec = v[i][x][j];
                lit[i][vec] = ('a' + x);
                len[i][vec] = 1;
                viz[i][vec] = 1;
                d.pb({i, vec, 0, 0});
            }
    }
    for(int i = 1; i <= n; ++i)
        for(int x = 0; x <= 25; ++x)
            for(int j = 0; j < tr[i][x].size(); ++j)
            {
                int na = tr[i][x][j];
                for(int k = 0; k < v[i][x].size(); ++k)
                {
                    int nb = v[i][x][k];
                    if(!viz[na][nb])
                    {
                        lit[na][nb] = ('a' + x);
                        len[na][nb] = 2;
                        viz[na][nb] = 1;
                        d.pb({na, nb, 0, 0});
                    }
                }
            }
    bfs();
    int q;
    cin >> q;
    int prv;
    cin >> prv;
    for(int i = 2; i <= q; ++i)
    {
        int curr;
        cin >> curr;
        if(!viz[prv][curr])
            cout << -1 << '\n';
        else
        {
            cout << len[prv][curr] << " ";
            build(prv, curr);
            cout << '\n';
        }
        prv = curr;
    }
    return 0;
}

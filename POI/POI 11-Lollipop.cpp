/*

        POI 11-Lollipop

    The most important observation for this problem is that if we can get sum x, we can get sum x-2 as well, and this can be proven by casework

    1) we either have a T at one of the substring's ends
    2) we have two W

    Using this, we can find the biggest odd and the biggest even sum and run a recursive subprogram which solves the assigning sum problem.

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

int n, m, sp[1000002], smi, smp;
pair<int, int> bgp, bgi;
string s;

pair<int, int> pz[2000002];

void proc(pair<int, int> a)
{
    int val = sp[a.se] - sp[a.fi - 1];
    pz[val] = a;
    if(val <= 2)
        return;
    if(s[a.fi] == 'T')
        ++a.fi;
    else
        if(s[a.se] == 'T')
            --a.se;
        else
            --a.se, ++a.fi;
    proc(a);
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
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i)
        sp[i] = sp[i-1] + 1 + (s[i] == 'T');
    for(int i = 1; i <= n; ++i)
    {
        if(sp[i] % 2 == 0)
        {
            bgp = {1, i};
            if(smi)
            {
                if(sp[i] - sp[smi] > sp[bgi.se] - sp[bgi.fi - 1])
                    bgi = {smi+1, i};
            }
        }
        else
        {
            bgi = {1, i};
            if(!smi)
                smi = i;
            else
            {
                if(bgp.fi == 0)
                    bgp = {smi+1, i};
                else
                    if(sp[i] - sp[smi] > sp[bgp.se] - sp[bgp.fi - 1])
                        bgp = {smi+1, i};
            }
        }
    }
    proc(bgp);
    proc(bgi);
    for(int i = 1; i <= m; ++i)
    {
        int nr;
        cin >> nr;
        if(pz[nr].fi == 0)
            cout << "NIE\n";
        else
            cout << pz[nr].fi << " " << pz[nr].se << '\n';
    }
    return 0;
}

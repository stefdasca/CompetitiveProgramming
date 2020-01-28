/*
        POI 05-Banknote

    Use knapsack in order to find the answer and the parts the answer is made of. In order to speed up the algorithm
we're going to use the trick where we split n items of type a into 1+2+4+...+biggest possible power of 2+(n - sum of powers of two used already).

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

int n, v[202], am[202], tot, k;

struct it
{
    int tip, am;
};
it vx[5002];

int ruk[20002];
bool viz[20002];
short parts[20002][1002], sz[20002];

int tott[202];
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
        cin >> am[i];
    cin >> k;
    for(int i = 1; i <= n; ++i)
    {
        int pw = 1;
        while(am[i])
        {
            if(am[i] >= pw)
                vx[++tot] = {i, pw}, am[i] -= pw;
            else
                vx[++tot] = {i, am[i]}, am[i] = 0;
            pw <<= 1;
        }
    }
    viz[0] = 1;
    for(int i = 1; i <= tot; ++i)
    {
        for(int j = k; j >= v[vx[i].tip] * vx[i].am; --j)
        {
            if(!viz[j - v[vx[i].tip] * vx[i].am])
                continue;
            if(!viz[j] || ruk[j - v[vx[i].tip] * vx[i].am] + vx[i].am < ruk[j])
            {
                viz[j] = 1;
                ruk[j] = ruk[j - v[vx[i].tip] * vx[i].am] + vx[i].am;
                for(int x = 1; x <= sz[j - v[vx[i].tip] * vx[i].am]; ++x)
                    parts[j][x] = parts[j - v[vx[i].tip] * vx[i].am][x];
                parts[j][sz[j - v[vx[i].tip] * vx[i].am]+1] = i;
                sz[j] = sz[j - v[vx[i].tip] * vx[i].am]+1;
            }
        }
    }
    cout << ruk[k] << '\n';
    for(int x = 1; x <= sz[k]; ++x)
        tott[vx[parts[k][x]].tip] += vx[parts[k][x]].am;
    for(int x = 1; x <= n; ++x)
        cout << tott[x] << " ";
    cout << '\n';
    return 0;
}

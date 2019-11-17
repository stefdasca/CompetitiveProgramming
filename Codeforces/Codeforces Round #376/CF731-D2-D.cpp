#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, c;

vector<int> sg[500002];

int nec(int a, int b)
{
    if(a <= b)
        return b-a;
    return c-a+b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;
    for(int i = 1; i <= n; ++i)
    {
        int sz;
        cin >> sz;
        for(int j = 0; j < sz; ++j)
        {
            int nr;
            cin >> nr;
            sg[i].pb(nr);
        }
    }
    vector<int> poz;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 0; j < min((int)sg[i-1].size(), (int)sg[i].size()); ++j)
        {
            if(sg[i][j] != sg[i-1][j])
            {
                poz.pb(j);
                break;
            }
        }
        if(poz.size() < i-1)
            poz.pb(min((int)sg[i-1].size(), (int)sg[i].size()));
    }
    int shf = 0;
    bool ok = 1;
    while(ok && shf < c)
    {
        ok = 0;
        for(int i = 0; i < poz.size(); ++i)
        {
            if(poz[i] == sg[i+1].size());
            else
                if(poz[i] == sg[i+2].size())
                {
                    cout << -1;
                    return 0;
                }
                else
                {
                    if(shf == 0)
                        shf = nec(sg[i+1][poz[i]], 1);
                    int aa = sg[i+1][poz[i]] + shf;
                    if(aa > c)
                        aa -= c;
                    int bb = sg[i+2][poz[i]] + shf;
                    if(bb > c)
                        bb -= c;
                    if(aa > bb)
                        shf += c+1-aa, ok = 1;
                }
        }
    }
    if(shf >= c)
        cout << -1;
    else
        cout << shf;
    return 0;
}

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
using namespace std;
int n;
string s;
int x, y;
long long prefx[200002];
long long prefy[200002];
bool check(int len)
{
    for(int i = 0; i + len - 1 < n; ++i)
    {
        long long sumx = 0, sumy = 0;
        if(i)
        {
            sumx = prefx[i-1];
            sumy = prefy[i-1];
        }
        sumx = sumx + prefx[n-1] - prefx[i + len - 1];
        sumy = sumy + prefy[n-1] - prefy[i + len - 1];
        int difleft = len - abs(sumx - x) - abs(sumy - y);
        if(difleft >= 0 && difleft % 2 == 0)
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin>>n;
    cin>>s;
    cin>>x>>y;
    for(int i = 0; i < n; ++i)
    {
        if(i)
            prefx[i] = prefx[i-1], prefy[i] = prefy[i-1];
        if(s[i] == 'U')
            prefy[i]++;
        if(s[i] == 'D')
            prefy[i]--;
        if(s[i] == 'L')
            prefx[i]--;
        if(s[i] == 'R')
            prefx[i]++;
    }
    int b = 0;
    int e = n/2;
    int sol = -1;
    int solimpar = -1;
    while(b <= e)
    {
        int mid = (b+e)/2;
        if(check(mid * 2))
            sol = 2 * mid, e = mid - 1;
        else
            b = mid + 1;
    }
    b = 1;
    e = n/2 + n%2;
    while(b <= e)
    {
        int mid = (b + e)/2;
        if(check(mid * 2 - 1))
            solimpar = mid * 2 - 1, e = mid - 1;
        else
            b = mid + 1;
    }
    if(sol == -1 && solimpar == -1)
        cout << -1;
    else
        if(sol == -1)
            cout << solimpar;
        else
            if(solimpar == -1)
                cout << sol;
            else
                cout << min(solimpar, sol);
    return 0;
}

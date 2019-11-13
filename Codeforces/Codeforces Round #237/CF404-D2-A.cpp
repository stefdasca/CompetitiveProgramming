#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define eps 1e-9

using namespace std;

typedef long long ll;

int n;
char a[502][502];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    char lit = a[1][1];
    for(int i = 1; i <= n; ++i)
        if(a[i][i] == lit && a[i][n-i+1] == lit);
        else
        {
            cout << "NO";
            return 0;
        }
    char lit2 = a[1][2];
    if(lit2 == lit)
    {
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(j != i && j != n - i + 1 && lit2 != a[i][j])
            {
                cout << "NO";
                return 0;
            }
    cout << "YES";
    return 0;
}

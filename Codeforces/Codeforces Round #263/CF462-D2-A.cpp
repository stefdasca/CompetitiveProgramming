#include<bits/stdc++.h>
using namespace std;
int n;
char a[102][102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            int vc = 0;
            vc = (a[i-1][j] == 'o') + (a[i][j-1] == 'o') + (a[i+1][j] == 'o') + (a[i][j+1] == 'o');
            if(vc % 2 == 1)
            {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
    return 0;
}

#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    if(m >= n && k >= n)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}

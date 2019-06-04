#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, o;
int nrr[100002];
void ciur()
{
    for(int i = 2; i <= n; ++i)
        if(!nrr[i])
        {
            ++o;
            for(int j = i; j <= n; j += i)
                nrr[j] = o;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ciur();
    for(int i = 2; i <= n; ++i)
        cout << nrr[i] << " ";
    return 0;
}


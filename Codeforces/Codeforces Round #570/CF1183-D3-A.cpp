#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int sc(int nr)
{
    int ans = 0;
    while(nr)
    {
        ans += nr%10;
        nr /= 10;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(1)
    {
        if(sc(n)%4==0){
            cout << n;
            return 0;
        }
        ++n;
    }
    return 0;
}


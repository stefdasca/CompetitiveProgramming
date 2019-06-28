#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;

string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    cin >> b;
    int zero = 0;
    for(int i = 0; i < b.size(); ++i)
        zero += (b[i] == '0');
    int snsd = 0;
    int ans = 0;
    for(int i = 0; i < a.size(); ++i){
        snsd += (a[i] == '0');
        if(i >= b.size())
            snsd -= (a[i - b.size()] == '0');
        if(i + 1 >= b.size() && max(snsd - zero, zero - snsd) % 2 == 0)
            ++ans;
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#pragma gcc optimize("O3")
using namespace std;

int n;
double s[100002];
int ans[100002];
bool updown[100002];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        int qq = (int)s[i];
        if(s[i] < 0 && qq != s[i])
            qq--;
        sum += qq;
    }
    for(int i = 1; i <= n; ++i)
    {
        int qq = (int)s[i];
        if(s[i] < 0 && qq != s[i])
            qq--;
        if(sum < 0)
        {
            if(s[i] == qq)
                cout << qq << '\n';
            else
                ++sum, cout << qq + 1 << '\n';
        }
        else
            cout << qq << '\n';
    }
    return 0;
}

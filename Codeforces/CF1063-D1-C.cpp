/// Roziiiiiiiiii

#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define mod 1000000007
#define fi first
#define se second
using namespace std;
int n;
string ans;
int stb, drb;
int stw, drw;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // shuffle(permutation.begin(), permutation.end(), rng);
    cin >> n;
    int st = 0;
    int dr = 1000000000;
    for(int i = 1; i <= min(n, 28); ++i)
    {
        int mid = (st + dr) / 2;
        cout << mid << " " << 0 << endl;
        cin >> ans;
        if(ans[0] == 'b')
            dr = mid;
        else
            st = mid;
    }
    if(n <= 28)
    {
        cout << st + 1 << " " << 0 << " " << st + 1 << " " << 1000000000 << endl;
        return 0;
    }
    if(n >= 29)
    {
        cout << 1000000000 << " " << 1000000000 << endl;
        cin >> ans;
        if(n == 29)
        {
            cout << st + 1 << " " << 0 << " ";
            if(ans[0] == 'b')
                cout << 999999999 << " " << 1000000000 << endl;
            else
                cout << 1000000000 << " " << 999999999 << endl;
            return 0;
        }
        else
        {
            if(ans[0] == 'b')
            {
                cout << 999999998 << " " << 1000000000 << endl;
                cin >> ans;
                if(ans[0] == 'b')
                {
                    cout << st + 1 << " " << 0 << " ";
                    cout << 999999997 << " " << 1000000000 << endl;
                    return 0;
                }
                else
                {
                    cout << st + 1 << " " << 0 << " ";
                    cout << 999999999 << " " << 1000000000 << endl;
                    return 0;
                }
            }
            else
            {
                cout << 1000000000 << " " << 999999998<< endl;
                cin >> ans;
                if(ans[0] == 'w')
                {
                    cout << st + 1 << " " << 0 << " ";
                    cout << 1000000000 << " " <<  999999997<< endl;
                    return 0;
                }
                else
                {
                    cout << st + 1 << " " << 0 << " ";
                    cout << 1000000000 << " " <<  999999999<< endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

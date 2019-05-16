#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int p1, p2, p3, p4;
int ans[7];
bool s1, s2, s3;
int pp[10] = {0, 4, 8, 15, 16, 23, 42};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "? 1 2" << endl;
    cin >> p1;
    cout << "? 1 3" << endl;
    cin >> p2;
    cout << "? 1 4" << endl;
    cin >> p3;
    cout << "? 1 5" << endl;
    cin >> p4;
    int aa = __gcd(p1, p2);
    int bb = __gcd(p3, p4);
    aa = __gcd(aa, bb);
    for(int i = 6; i >= 1; --i)
        if(aa % pp[i] == 0)
        {
            aa = pp[i];
            break;
        }
    ans[1] = aa;
    ans[2] = p1/aa;
    ans[3] = p2/aa;
    ans[4] = p3/aa;
    ans[5] = p4/aa;
    for(int i = 1; i <= 6; ++i)
    {
        bool ok = 0;
        for(int j = 1; j <= 5; ++j)
            if(ans[j] == pp[i])
                ok = 1;
        if(!ok){
            ans[6] = pp[i];
            break;
        }
    }
    cout << "! ";
    for(int i = 1; i <= 6; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

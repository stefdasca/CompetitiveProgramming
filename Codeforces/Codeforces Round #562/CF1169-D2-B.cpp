#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, m;
struct arr
{
    int a, b;
};
arr v[300002];
int frq[300002], frq2[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
        cin >> v[i].a >> v[i].b;
    bool ok = 1;
    for(int i = 2; i <= m; ++i)
        if((v[i].a == v[1].a || v[i].a == v[1].b) && (v[i].b == v[1].a || v[i].b == v[1].b))
            ok = 1;
        else
        {
            ok = 0;
            break;
        }
    if(ok)
    {
        cout << "YES";
        return 0;
    }
    int ct = 0;
    for(int i = 2; i <= m; ++i)
        if(v[i].a != v[1].a && v[i].b != v[1].a)
            ++frq[v[i].a], ++frq[v[i].b], ++ct;
    for(int i = 1; i <= n; ++i)
        if(frq[i] == ct)
        {
            cout << "YES";
            return 0;
        }
    ct = 0;
    for(int i = 2; i <= m; ++i)
        if(v[i].a != v[1].b && v[i].b != v[1].b)
            ++frq2[v[i].a], ++frq2[v[i].b], ++ct;
    for(int i = 1; i <= n; ++i)
        if(frq2[i] == ct)
        {
            cout << "YES";
            return 0;
        }
    cout << "NO";
    return 0;
}

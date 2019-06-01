#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
int n, q;
int bkt;
long long v2[100002], rns[100002];
struct queries
{
    int st, dr, pi;
};
queries v[100002];
bool cmp(queries a, queries b)
{
    if(a.st / bkt == b.st / bkt)
        return a.dr < b.dr;
    return a.st < b.st;
}
long long ans = 0;
int frq[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    bkt = sqrt(n);
    for(int i = 1; i <= n; ++i)
        cin >> v2[i];
    for(int i = 1; i <= q; ++i)
        cin >> v[i].st >> v[i].dr, v[i].pi = i;
    sort(v + 1, v + q + 1, cmp);
    int st = 1;
    int dr = 0;
    for(int i = 1; i <= q; ++i)
    {
        while(st > v[i].st)
        {
            --st;
            if(v2[st] <= n){
                ++frq[v2[st]];
                if(frq[v2[st]] == v2[st])
                    ans++;
                else
                    if(frq[v2[st]] - 1 == v2[st])
                        ans--;
            }
        }
        while(dr < v[i].dr)
        {
            ++dr;
            if(v2[dr] <= n){
                ++frq[v2[dr]];
                if(frq[v2[dr]] == v2[dr])
                    ans++;
                else
                    if(frq[v2[dr]] - 1 == v2[dr])
                        ans--;
            }
        }
        while(st < v[i].st)
        {
            if(v2[st] <= n){
                --frq[v2[st]];
                if(frq[v2[st]] == v2[st])
                    ans++;
                else
                    if(frq[v2[st]] + 1 == v2[st])
                        ans--;
            }
            ++st;
        }
        while(dr > v[i].dr)
        {
            if(v2[dr] <= n){
                --frq[v2[dr]];
                if(frq[v2[dr]] == v2[dr])
                    ans++;
                else
                    if(frq[v2[dr]] + 1 == v2[dr])
                        ans--;
            }
            --dr;
        }

        rns[v[i].pi] = ans;
    }
    for(int i = 1; i <= q; ++i)
        cout << rns[i] << '\n';
    return 0;
}


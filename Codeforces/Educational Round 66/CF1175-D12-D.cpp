#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, k;
long long v[300002];
long long sp[300002], spb[300002];
struct snsd
{
    long long sump;
    int pi;
};
snsd v2[300002];
int aib[300002];
bool cmp(snsd a, snsd b)
{
    return a.sump < b.sump;
}
void add(int nod)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod]++;
}
int compute(int nod)
{
    long long a = 0;
    for(; nod; nod -= (nod & (-nod)))
        a += aib[nod];
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = n; i >= 1; --i)
        sp[i] = sp[i+1] + v[i], v2[i] = {sp[i], i};
    long long ans = sp[1];
    sort(sp + 1, sp + n + 1);
    sort(v2 + 1, v2 + n + 1, cmp);
    --k;
    int x = n;
    while(k)
    {
        int val = compute(v2[x].pi);
        if(val != v2[x].pi - 1)
            ans += v2[x].sump, add(v2[x].pi), --k;
        --x;
    }
    cout << ans;
    return 0;
}


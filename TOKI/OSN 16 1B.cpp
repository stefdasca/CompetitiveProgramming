/*
        OSN 16 1B

    Let's ask queries in this order:

    1 2 3 ... n/2 n/2 n/2-1 ... 1.

    If we heard a BIP, then the bomb is somewhere in range 1...n/2 and we will get the second trigger
(One can observe that if we know the first two times we heard a BIP, we can find out using this construction
which button is the one we need to press to trigger the BIPs)

    Let's ask now queries in this order:

    n/2+1 n/2+2 ... n

    If we heard the bomb twice, the bomb is somewhere in range 1...n/2.

    Let's ask now queries in this order:

    n n-1 n-2 ... n/2+1

    If we get the 2nd hit somewhere along the way, we should stop, otherwise we will keep asking for 1 until we get it.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, t, r, qu;
vector<int> vq, bomb;
string s;
int nrbip = 0;
int ask(int poz)
{
    cout << poz << endl;
    string x;
    cin >> x;
    if(x[0] == 'B')
    {
        ++nrbip;
        if(nrbip == n)
            exit(0);
        return 1;
    }
    return 0;
}
void solve()
{
    while(bomb.size() < 2)
    {
        if(ask(1))
            bomb.pb(qu);
        vq.pb(0);
        ++qu;
    }
    int ans;
    for(int k = 0; k < n; k++)
        if(bomb[0] - k >= 0 && bomb[1] - k >= 0 && vq[bomb[0] - k] == vq[bomb[1] - k])
            ans = vq[bomb[0]-k];
    while(1)
        ask(ans);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> n >> t >> r;
    for(int i = 1; i <= n/2; i++)
    {
        if(ask(i))
            bomb.pb(qu);
        vq.pb(i);
        ++qu;
    }
    for(int i = 0; i < n/2; i++)
    {
        if(ask(n / 2 -i))
            bomb.pb(qu);
        vq.pb(n / 2 - i);
        ++qu;
    }
    if(!bomb.empty())
        solve();
    for(int i = n/2 + 1; i <= n; i++)
    {
        if(ask(i))
            bomb.pb(qu);
        vq.pb(i);
        ++qu;
    }
    if(bomb.size() == 2)
        solve();
    for(int i = n; i > n/2 && bomb.size() < 2; i--)
    {
        if(ask(i))
            bomb.pb(qu);
        vq.pb(i);
        ++qu;
    }
    solve();
    return 0;
}

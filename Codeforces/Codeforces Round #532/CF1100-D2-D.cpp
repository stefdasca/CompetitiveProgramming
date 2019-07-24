#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 998244353

using namespace std;

typedef long long ll;

ll add(ll a, ll b)
{
    ll x = a+b;
    if(x >= mod)
        x -= mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

int x, y;
int ox[670], oy[670];


bool gol(int x, int y)
{
    for(int i = 1; i <= 666; ++i)
        if(ox[i] == x && oy[i] == y)
            return 0;
    return 1;
}


bool check()
{
    for(int i = 1; i <= 666; ++i)
        if(ox[i] == x || oy[i] == y)
            return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x >> y;
    for(int i = 1; i <= 666; ++i)
        cin >> ox[i] >> oy[i];
    while(x != 500 || y != 500)
    {
        int dir = 0, diry = 0;
        if(x < 500)
            dir = 1;
        if(x > 500)
            dir = -1;
        if(y < 500)
            diry = 1;
        if(y > 500)
            diry = -1;
        x += dir, y += diry;
        if(!gol(x, y)){
            cout << x << " " << y - diry << endl;
            return 0;
        }
        cout << x << " " << y << endl;
        if(check())
            return 0;
        int nr, nx, ny;
        cin >> nr >> nx >> ny;
        if(nr == -1)
            return 0;
        ox[nr] = nx, oy[nr] = ny;
    }
    int k1=0, k2=0, k3=0, k4=0;
    for(int i = 1; i <= 666; i++)
    {
        if(ox[i] < 500 && oy[i] < 500)
            k1++;
        else
            if(ox[i] < 500 && oy[i] > 500)
                k2++;
            else
                if(ox[i] > 500 && oy[i] < 500)
                    k3++;
                else
                    k4++;
    }
    int mink = min(min(k1,k2),min(k3,k4));
    int dr, dc;
    if(k1 == mink)
        dr = 1, dc = 1;
    else
        if(k2 == mink)
            dr = 1, dc = -1;
        else
            if(k3 == mink)
                dr = -1, dc = 1;
            else
                dr = -1, dc = -1;
    for(int i = 1; i <= 499; i++)
    {
        x+=dr;
        y+=dc;
        if(!gol(x, y))
        {
            cout << x << " " << y-dc << endl;
            return 0;
        }
        cout << x << " " << y << endl;
        if(check())
            return 0;
        int rn, mr, mc;
        cin >> rn >> mr >> mc;
        if(rn == -1)
            return 0;
        ox[rn] = mr, oy[rn] = mc;
    }
    return 0;
}

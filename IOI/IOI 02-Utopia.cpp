/*
        IOI 02-Utopia Divided

    We can solve the problem separately for each direction.

    Split the array of length 2n in 2 arrays of length n and for each direction(Ox or Oy) we sort the array.

    Let's find the number of positions where the sign doesn't change(this will be the split point of our array)
and at each step, we either take the biggest number from the left side(if sign doesn't change) or the leftmost number
from the right side(if the sign changes).

    Basically, we are trying to keep the value of the coordinate as small as possible in order to be able to switch its sign easily.

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

// #define fisier 1

using namespace std;

int n;

vector<int> x, y, sgnx, sgny, ansx, ansy;

int ovr[10002];
vector<int> solve(vector<int> vals, vector<int> signs, vector<int> ans)
{
    memset(ovr, 0, sizeof(ovr));
    int cnt = 1;
    for(int i = 1; i < n; ++i)
        if(signs[i] == signs[i+1])
            ++cnt;
    int st = cnt;
    int dr = cnt;
    ovr[cnt] = (signs[1] ? -1 : 1);
    ans[1] = ovr[cnt] * vals[cnt];
    for(int i = 2; i <= n; i++)
    {
        if(signs[i] == signs[i-1])
        {
            st--;
            ovr[st] = ovr[st+1] * -1;
            ans[i] = ovr[st] * vals[st];
        }
        else
        {
            dr++;
            ovr[dr] = ovr[dr-1] * -1;
            ans[i] = ovr[dr] * vals[dr];
        }
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    x.resize(n+1);
    y.resize(n+1);
    sgnx.resize(n+1);
    sgny.resize(n+1);
    ansx.resize(n+1);
    ansy.resize(n+1);

    for(int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    for(int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;
        if(c == 2 || c == 3)
            sgnx[i] = 1;
        else
            sgnx[i] = 0;
        if(c == 3 || c == 4)
            sgny[i] = 1;
        else
            sgny[i] = 0;
    }
    ansx = solve(x, sgnx, ansx);
    ansy = solve(y, sgny, ansy);
    for(int i = 1; i <= n; ++i)
        cout << (ansx[i] > 0 ? "+" : "-") << abs(ansx[i]) << " " << (ansy[i] > 0 ? "+" : "-") << abs(ansy[i]) << '\n';
    return 0;
}

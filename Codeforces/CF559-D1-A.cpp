#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int v[8];
double rad3 = 1.732050807568877;
struct puncte
{
    double x, y;
};
puncte arr[10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1; i <= 6; ++i)
        cin >> v[i];
    arr[2] = {0.00000 + v[1], 0.00000};
    arr[6] = {0.00000 - 0.500000 * v[6], 0.000000 + rad3 * 0.5000000 * v[6]};
    arr[3] = {arr[2].x + 0.500000 * v[2], arr[2].y + rad3 * 0.5000000 * v[2]};
    arr[4] = {arr[3].x - 0.500000 * v[3], arr[3].y + rad3 * 0.5000000 * v[3]};
    arr[5] = {arr[4].x - v[4], arr[4].y};
    double arie = 0.00000;
    for(int i = 1; i <= 6; ++i)
        arie = arie + arr[i].x * arr[i+1].y - arr[i+1].x * arr[i].y;
    arie *= 0.5000000;
    if(arie < 0.000000)
        arie *= -1.0000000;
    arie = arie * 4.00000000;
    arie /= rad3;
    long long ans = round(arie);
    cout << ans << '\n';
    return 0;
}


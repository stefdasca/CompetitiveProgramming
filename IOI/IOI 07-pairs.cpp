/*
            IOI 07-pairs

    * subtask 1: binary search the leftmost point which is situated within d distance

    * subtask 2: use sqrt decomposition to find the contribution to the answer for each point.

    * subtask 3: for each point, either use prefix sums(slower) or subtask 2(faster) to find the contribution to the answer

*/
#include<bits/stdc++.h>
using namespace std;
int tip, n, d, m;
long long ans;

struct tp
{
    int x, y, z;
};
tp vv[100002];

int v[100002];
void solve1()
{
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; ++i)
    {
        int sm = i;
        int st = 1;
        int dr = i-1;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(v[i] - v[mid] <= d)
                sm = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        ans += (i - sm);
    }
    cout << ans << '\n';
}

pair<int, int> nr[100002];
int aib[401][200002];
vector<int>coord[150002];
void upd(int bu, int pz, int val)
{
    aib[bu][pz] += val;
}
int compute(int bu, int pz)
{
    pz = max(pz, 0);
    pz = min(pz, 200000);
    return aib[bu][pz];
}
int cb(int linie, int col)
{
    int ans = 0;
    int st = 0;
    int dr = coord[linie].size() - 1;
    if(coord[linie].back() <= col)
        return coord[linie].size();
    if(coord[linie][0] > col)
        return 0;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(coord[linie][mid] <= col)
            ans = (mid + 1), st = mid + 1;
        else
            dr = mid - 1;
    }
    return ans;
}
void solve2()
{
    int buk = 400;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nr[i].first = x + y;
        nr[i].second = x - y + 100000;
        coord[nr[i].first].push_back(nr[i].second);
        int nrbuk = nr[i].first / buk + (nr[i].first % buk > 0);
        upd(nrbuk, nr[i].second, 1);
    }
    for(int i = 1; i <= 400; ++i)
        for(int j = 1; j <= 200000; ++j)
            aib[i][j] += aib[i][j-1];
    for(int i = 0; i <= 150000; ++i)
        sort(coord[i].begin(), coord[i].end());
    for(int i = 1; i <= n; ++i)
    {
        int st = max(1, nr[i].first - d);
        int sf = min(150000, nr[i].first + d);
        int nrbuk = st / buk + (st % buk > 0);
        --ans;
        while(st <= sf && st <= nrbuk * buk)
        {
            if(!coord[st].empty())
                ans += cb(st, nr[i].second + d) - cb(st, nr[i].second - d - 1);
            ++st;
        }
        while(st + buk - 1 <= sf)
        {
            nrbuk = st / buk + (st % buk > 0);
            ans += compute(nrbuk, nr[i].second + d) - compute(nrbuk, nr[i].second - d - 1);
            st += buk;
        }
        while(st <= sf)
        {
            if(!coord[st].empty())
                ans += cb(st, nr[i].second + d) - cb(st, nr[i].second - d - 1);
            ++st;
        }
    }
    cout << ans / 2 << '\n';
}

int is[80][80][80];
int sp[80][80][80];
void solve3()
{
    for(int i = 1; i <= n; ++i)
        cin >> vv[i].x >> vv[i].y >> vv[i].z, is[vv[i].x][vv[i].y][vv[i].z]++;
    for(int i = 1; i <= 75; ++i)
        for(int j = 1; j <= 75; ++j)
            for(int x = 1; x <= 75; ++x)
                sp[i][j][x] = sp[i][j][x-1] + is[i][j][x];
    for(int i = 1; i <= n; ++i)
    {
        --ans;
        for(int x = 1; x <= 75; ++x)
        {
            if(abs(vv[i].x - x) > d)
                continue;
            for(int y = 1; y <= 75; ++y)
            {
                int rem = d - abs(vv[i].x - x) - abs(vv[i].y - y);
                if(rem >= 0)
                    ans = ans + sp[x][y][min(75, vv[i].z + rem)] - sp[x][y][max(0, vv[i].z - rem - 1)];
            }
        }
    }
    cout << ans/2 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tip >> n >> d >> m;
    if(tip == 1)
        solve1();
    if(tip == 2)
        solve2();
    if(tip == 3)
        solve3();
    return 0;
}

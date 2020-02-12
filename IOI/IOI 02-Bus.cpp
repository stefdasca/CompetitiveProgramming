/*
        IOI 02-Bus

    detailed approach: https://github.com/thecodingwizard/competitive-programming/blob/master/IOI/IOI%2002-Bus.cpp

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

typedef long long ll;

int n, dist[502][502];
pair<int, int> coord[502];

int ans = (1<<30);

void run(int a, int b)
{
    vector<pair<int, int> > distances;
    for(int i = 1; i <= n; ++i)
        if(i != a && i != b)
            distances.pb({dist[a][i], i});
    sort(distances.begin(), distances.end());

    int maxb = 0, max2b = 0, busdistance = dist[a][b];

    for(int pos = distances.size() - 1; pos >= 0; --pos)
    {
        int cur_sum = maxb + max2b;
        cur_sum = max(cur_sum, distances[pos].fi + busdistance + maxb);
        if(pos)
            cur_sum = max(cur_sum, distances[pos].fi + distances[pos-1].fi);
        int nrbus = 0;
        while(1)
        {
            int cursum2 = maxb + max2b;
            int newid2 = pos - nrbus - 1;
            if(newid2 < 0)
                break;
            if(newid2)
                cursum2 = max(cursum2, distances[pos].fi + distances[newid2 - 1].fi);
            int removedid = distances[newid2].se;
            cursum2 = max(cursum2, distances[pos].fi + busdistance + max(maxb, dist[b][removedid]));
            if(cursum2 > cur_sum)
                break;
            if(dist[b][removedid] > maxb)
            {
                max2b = maxb;
                maxb = dist[b][removedid];
            }
            else
                if(dist[b][removedid] > max2b)
                    max2b = dist[b][removedid];
            cur_sum = cursum2;
            ++nrbus;
        }
        ans = min(ans, cur_sum);
        int id = distances[pos].se;
        if(dist[b][id] > maxb)
        {
            max2b = maxb;
            maxb = dist[b][id];
        }
        else
            if(dist[b][id] > max2b)
                max2b = dist[b][id];
        pos -= nrbus;
    }
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> coord[i].fi >> coord[i].se;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dist[i][j] = abs(coord[i].fi - coord[j].fi) + abs(coord[i].se - coord[j].se);
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j)
            run(i, j);
    cout << ans;
    return 0;
}

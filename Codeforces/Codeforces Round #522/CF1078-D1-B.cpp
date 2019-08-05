#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
int v[102];
bool can2[102][10002];
bool atins[10002];
bool luat[102];
int maxans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v+1, v+n+1);
    int st = 0, dr = 0, sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] != v[i-1])
            st = i, sum = 0;
        dr = i;
        sum += v[i];
        if(dr - st + 1 <= maxans)
            continue;
        memset(can2, 0, sizeof(can2));
        memset(atins, 0, sizeof(atins));
        can2[0][0] = 1;
        atins[0] = 1;
        int mxs = 0;
        bool rau = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(st <= j && j <= dr)
                continue;
            if(rau)
                break;
            for(int p = mxs; p >= 0; --p)
            {
                if(!atins[p])
                    continue;
                if(rau)
                    break;
                for(int q = dr - st; q >= 0; --q)
                    if(can2[q][p])
                    {
                        can2[q+1][p+v[j]] = 1, atins[p+v[j]] = 1;
                        if(v[j] != v[i] && (q + 1) * v[i] == p + v[j])
                        {
                            rau = 1;
                            break;
                        }
                    }
            }
            mxs += v[j];
        }
        if(rau == 0)
        {
            maxans = max(maxans, dr - st + 1);
            bool ok = 1;
            int prev = 0;
            for(int j = 1; j <= n; ++j)
            {
                if(st <= j && j <= dr)
                    continue;
                if(prev == 0)
                    prev = v[j];
                else
                    if(prev != v[j])
                        ok = 0;
            }
            if(ok)
            {
                cout << n;
                return 0;
            }
        }
    }
    cout << maxans << '\n';
    return 0;
}


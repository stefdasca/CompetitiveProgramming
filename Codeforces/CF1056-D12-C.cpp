#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m, t;
long long power[2002];
long long bad[2002];
bool scos[2002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; ++i)
        cin >> power[i];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;
        bad[a] = b;
        bad[b] = a;
    }
    cin >> t;
    int ax = t % 2;
    int next = 0;
    for(int i = 1; i <= 2 * n; ++i)
    {
        if(i % 2 != ax)
        {
            int aa;
            cin >> aa;
            scos[aa] = 1;
            if(bad[aa] && !scos[bad[aa]])
                next = bad[aa];
        }
        else
        {
            if(next)
            {
                cout << next << endl;
                scos[next] = 1;
                next = 0;
                continue;
            }
            long long max_dif = 0;
            long long pos = 0;
            long long mx_nr = 0;
            for(int j = 1; j <= 2 * n; ++j)
            {
                if(scos[j])
                    continue;
                if(bad[j])
                    if(power[j] - power[bad[j]] > max_dif)
                        max_dif = max(max_dif, power[j] - power[bad[j]]), pos = j;
                if(power[j] > power[mx_nr])
                    mx_nr = j;
            }
            if(max_dif > 0)
            {
                cout << pos << endl;
                scos[pos] = 1;
                continue;
            }
            else
            {
                cout << mx_nr << endl;
                scos[mx_nr] = 1;
                continue;
            }
        }
    }
    return 0;
}

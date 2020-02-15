/*
        USACO 16dec-roboherd-plat

    We can normalize the input and run binary search on the answer.

    Using some bruteforce optimizations, we can get a decent runtime using the bruteforce algorithm.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("roboherd.in");
ofstream g("roboherd.out");

int n, k;
vector<int> v[100002], mini;

long long smallest, smc;

int tot;
void bkt(int poz, long long rem)
{
    if(tot >= k)
        return;
    if(poz != 0 && rem < v[poz][0])
        poz = upper_bound(mini.begin(), mini.begin() + poz, (int)rem) - mini.begin() - 1;
    if(poz == 0)
    {
        tot++;
        return;
    }
    bkt(poz - 1, rem);
    for(int i = 0; i < v[poz].size() && v[poz][i] <= rem; i++)
        bkt(poz - 1, rem - v[poz][i]);
}

void cnt(int poz, long long rem)
{
    if(poz != 0 && rem < v[poz][0])
        poz = upper_bound(mini.begin(), mini.begin() + poz, (int)rem) - mini.begin() - 1;
    if(poz == 0)
    {
        smc += rem + 1;
        return;
    }
    cnt(poz - 1, rem);
    for(int i = 0; i < v[poz].size() && v[poz][i] <= rem; i++)
        cnt(poz - 1, rem - v[poz][i]);
}
int main()
{
    f >> n >> k;
    long long st = 0, dr = 0;
    for(int i = 1; i <= n; ++i)
    {
        int sz;
        f >> sz;
        vector<int> vals(sz);
        for(int j = 0; j < sz; ++j)
            f >> vals[j];
        sort(vals.begin(), vals.end());
        smallest += vals[0];
        if(sz == 1)
        {
            --i;
            --n;
            continue;
        }
        for(int j = 1; j < sz; ++j)
            v[i].push_back(vals[j] - vals[0]);
        dr += v[i].back();
    }
    sort(v + 1, v + n + 1);
    mini.push_back(-1);
    for(int i = 1; i <= n; ++i)
        mini.push_back(v[i][0]);
    long long ans = 0;
    while(st <= dr)
    {
        long long mid = (st + dr) / 2;
        tot = 0;
        bkt(n, mid);
        if(tot >= k)
        {
            ans = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }
    if(ans > 0)
        cnt(n, ans - 1);
    g << 1LL * (smallest + ans) * k - smc << '\n';
    return 0;
}

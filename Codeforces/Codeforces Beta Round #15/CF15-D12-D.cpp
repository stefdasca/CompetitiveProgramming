#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, a, b, mat[1002][1002];
long long sp[1002][1002], mnL[1002][1002], mn[1002][1002];
struct sq
{
    int La, Ca;
    long long remuv;
};
sq v[1000002];
int aib[1002][1002];
void add(int L, int C)
{
    for(; L <= n; L += (L & (-L)))
        for(int i = C; i <= m; i += (i & (-i)))
            aib[L][i]++;
}
int compute(int L, int C)
{
    int ans = 0;
    for(; L; L -= (L & (-L)))
        for(int i = C; i; i -= (i & (-i)))
            ans += aib[L][i];
    return ans;
}
bool cmp(sq a, sq b)
{
    if(a.remuv == b.remuv && a.La == b.La)
        return a.Ca < b.Ca;
    if(a.remuv == b.remuv)
        return a.La < b.La;
    return a.remuv < b.remuv;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> mat[i][j];
            sp[i][j] = mat[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
        }
    for(int i = 1; i <= n; ++i)
    {
        deque<int>d;
        for(int j = 1; j <= m; ++j)
        {
            if(!d.empty() && d.front() == j - b)
                d.pop_front();
            while(!d.empty() && mat[i][j] < mat[i][d.back()])
                d.pop_back();
            d.push_back(j);
            mnL[i][j] = mat[i][d.front()];
        }
    }
    for(int j = 1; j <= m; ++j)
    {
        deque<int>d;
        for(int i = 1; i <= n; ++i)
        {
            if(!d.empty() && d.front() == i - a)
                d.pop_front();
            while(!d.empty() && mnL[i][j] < mnL[d.back()][j])
                d.pop_back();
            d.push_back(i);
            mn[i][j] = mnL[d.front()][j];
        }
    }
    int nr = 0;
    for(int i = 1; i + a - 1 <= n; ++i)
        for(int j = 1; j + b - 1 <= m; ++j)
        {
            int val = mn[i + a - 1][j + b - 1];
            long long diff = sp[i + a - 1][j + b - 1] - sp[i + a - 1][j - 1] - sp[i - 1][j + b - 1] + sp[i - 1][j - 1];
            diff = diff - 1LL * val * a * b;
            v[++nr] = {i, j, diff};
        }
    sort(v + 1, v + nr + 1, cmp);
    vector<int>poz;
    for(int i = 1; i <= nr; ++i)
    {
        int L = v[i].La;
        int C = v[i].Ca;
        int val = compute(L + a - 1, C + b - 1) - compute(L - 1, C + b - 1) - compute(L + a - 1, C - 1) + compute(L - 1, C - 1);
        if(val == 0)
        {
            poz.push_back(i);
            for(int x = L; x <= L + a - 1; ++x)
                for(int y = C; y <= C + b - 1; ++y)
                    add(x, y);
        }
    }
    cout << poz.size() << '\n';
    for(int i = 0; i < poz.size(); ++i)
        cout << v[poz[i]].La << " " << v[poz[i]].Ca << " " << v[poz[i]].remuv << '\n';
    return 0;
}

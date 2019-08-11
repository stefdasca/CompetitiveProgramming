/*
        infoarena engineer

    We can use parallel binary search to answer to the queries. Using BIT, we can find out for
each query its relative answer compared to the numbers in array and we will print the value in
the position found.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("engineer.in");
ofstream g("engineer.out");
int n, m, q, mat[1102][1102];
int aib[1102][1102];
struct queries
{
    int La, Lb, Ca, Cb, kk;
};
queries v[1002];
int ans[1002];
struct triplu
{
    int val, i, j;
};
vector<triplu>v2;
bool cmp(triplu a, triplu b)
{
    return a.val < b.val;
}
bool cmp2(int a, int b)
{
    return ans[a] < ans[b];
}
void add(int L, int C)
{
    for(; C <= m; C += (C & (-C)))
        aib[L][C]++;
}
int compute(int L, int C)
{
    int ans = 0;
    for(; C; C -= (C & (-C)))
        ans += aib[L][C];
    return ans;
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            int nr;
            f >> nr;
            v2.push_back({nr, i, j});
        }
    sort(v2.begin(), v2.end(), cmp);
    f >> q;
    for(int i = 1; i <= q; ++i)
        f >> v[i].La >> v[i].Ca >> v[i].Lb >> v[i].Cb >> v[i].kk;
    for(int i = (1<<20); i; i >>= 1)
    {
        vector<int>qa;
        for(int j = 1; j <= q; ++j)
            if(ans[j] + i <= v2.size())
                qa.push_back(j);
        if(!qa.size())
            continue;
        sort(qa.begin(), qa.end(), cmp2);
        memset(aib, 0, sizeof(aib));
        int pz = 0;
        for(int j = 0; j < v2.size(); ++j)
        {
            add(v2[j].i, v2[j].j);
            while(pz < qa.size() && j + 1 - i == ans[qa[pz]])
            {
                int ss = 0;
                for(int pp = v[qa[pz]].La; pp <= v[qa[pz]].Lb; ++pp)
                    ss = ss + compute(pp, v[qa[pz]].Cb) - compute(pp, v[qa[pz]].Ca - 1);
                if(ss < v[qa[pz]].kk)
                    ans[qa[pz]] += i;
                else
                    if(ss == v[qa[pz]].kk)
                        if(v[qa[pz]].La <= v2[j].i && v2[j].i <= v[qa[pz]].Lb && v[qa[pz]].Ca <= v2[j].j && v2[j].j <= v[qa[pz]].Cb)
                            ans[qa[pz]] += i;
                ++pz;
            }
        }
    }
    for(int i = 1; i <= q; ++i)
        g << v2[ans[i] - 1].val << '\n';
    return 0;
}

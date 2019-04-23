/*
        Balkan 17-CityAttractions

    We can use 2 DFS dp to find the next node for each node.
    Then, we can observe that the graph which will be built by adding a directed edge between a and b
if from a we go to b will have a simple cycle and we can find its period.

*/
#include<bits/stdc++.h>
using namespace std;
long long n, k, a[300002], nxt[300002], when[300002];
vector<int>tree[300002];
long long mx[300002];
int wh[300002];
void dfs(int dad, int nod)
{
    mx[nod] = -(1LL<<60);
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        dfs(nod, vecin);
        int q = 0;
        long long val = 0;
        if(mx[vecin] - 1 > a[vecin] - 1)
            q = wh[vecin], val = mx[vecin] - 1;
        else
            if(mx[vecin] - 1 == a[vecin] - 1)
                val = mx[vecin] - 1, q = min(wh[vecin], vecin);
            else
                val = a[vecin] - 1, q = vecin;
        if(val > mx[nod])
            mx[nod] = val, wh[nod] = q;
        else
            if(val == mx[nod])
                wh[nod] = min(wh[nod], q);
    }
}
void dfs2(int dad, int nod, long long qt, int who)
{
    if(nod != 1)
    {
        if(qt > mx[nod] || (qt == mx[nod] && who < wh[nod]))
            nxt[nod] = who;
        else
            nxt[nod] = wh[nod];
    }
    long long mxx = -(1LL<<60), mxx2 = -(1LL<<60);
    int wh1 = 0, wh2 = 0;
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        int q = 0;
        long long val = 0;
        if(mx[vecin] - 1 > a[vecin] - 1)
            q = wh[vecin], val = mx[vecin] - 1;
        else
            if(mx[vecin] - 1 == a[vecin] - 1)
                val = mx[vecin] - 1, q = min(wh[vecin], vecin);
            else
                val = a[vecin] - 1, q = vecin;
        if(val > mxx || (val == mxx && q < wh1))
            mxx2 = mxx, wh2 = wh1, wh1 = q, mxx = val;
        else
            if(val > mxx2 || (val == mxx2 && q < wh2))
                wh2 = q, mxx2 = val;
    }
    for(int i = 0; i < tree[nod].size(); ++i)
    {
        int vecin = tree[nod][i];
        if(vecin == dad)
            continue;
        if(nod == 1)
        {
            if(wh1 == vecin || wh1 == wh[vecin])
            {
                if(mxx2 - 1 > a[1] - 1)
                    dfs2(nod, vecin, mxx2 - 1, wh2);
                else
                    if(mxx2 - 1 == a[1] - 1)
                        dfs2(nod, vecin, mxx2 - 1, 1);
                    else
                        dfs2(nod, vecin, a[1] - 1, 1);
            }
            else
            {
                if(mxx - 1 > a[1] - 1)
                    dfs2(nod, vecin, mxx - 1, wh1);
                else
                    if(mxx - 1 == a[1] - 1)
                        dfs2(nod, vecin, mxx - 1, 1);
                    else
                        dfs2(nod, vecin, a[1] - 1, 1);
            }
        }
        else
        {
            if(wh1 == vecin || wh1 == wh[vecin])
            {
                long long aaa = a[nod] - 1;
                int whaa = nod;
                if(mxx2 - 1 > aaa)
                    aaa = mxx2 - 1, whaa = wh2;
                else
                    if(mxx2 - 1 == aaa)
                        whaa = min(whaa, wh2);
                if(qt - 1 > aaa)
                    aaa = qt - 1, whaa = who;
                else
                    if(qt - 1 == aaa)
                        whaa = min(whaa, who);
                dfs2(nod, vecin, aaa, whaa);
            }
            else
            {
                long long aaa = a[nod] - 1;
                int whaa = nod;
                if(mxx - 1 > aaa)
                    aaa = mxx - 1, whaa = wh1;
                else
                    if(mxx - 1 == aaa)
                        whaa = min(whaa, wh1);
                if(qt - 1 > aaa)
                    aaa = qt - 1, whaa = who;
                else
                    if(qt - 1 == aaa)
                        whaa = min(whaa, who);
                dfs2(nod, vecin, aaa, whaa);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0, 1);
    nxt[1] = wh[1];
    dfs2(0, 1, 0, 0);
    long long i = 1, poz = i;
    while(i <= k && !when[poz])
    {
        when[poz] = i;
        ++i;
        poz = nxt[poz];
    }
    if(i > k)
        cout << poz << '\n';
    else
    {
        long long dif = k - i + 1;
        dif %= (i - when[poz]);
        for(int j = 1; j <= dif; ++j)
            poz = nxt[poz];
        cout << poz << '\n';
    }
    return 0;
}

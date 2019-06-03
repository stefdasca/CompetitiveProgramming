#include<bits/stdc++.h>
using namespace std;
int dis, INF = 1e9 + 5, N, M, ansMi, ansMa, ansPos, ma[280009], aint[280009], lzy[280009], a[100009], real_val[100009], ans[300009];
vector<pair<int, int> >qr[100009];
pair<int, int>v[100009];
void buildMax(int nod, int st, int dr)
{
    ma[nod] = 0;
    if(st == dr)
        return;
    int mij = (st + dr) / 2;
    buildMax(nod << 1, st, mij);
    buildMax(nod << 1|1, mij + 1, dr);
}
void updMax(int nod, int st, int dr, int pos, int val)
{
    if(st == dr)
    {
        ma[nod] = val;
        return;
    }
    int mij = (st + dr) / 2;
    if(pos <= mij)
        updMax(nod << 1, st, mij, pos, val);
    else
        updMax(nod << 1|1, mij + 1, dr, pos, val);
    ma[nod] = max(ma[nod << 1], ma[nod << 1|1]);
}
void qryMax(int nod, int st, int dr, int x, int y)
{
    if(x <= st && dr <= y)
    {
        if(x == st || ma[nod] > ansMa)
            ansMa = ma[nod], ansPos = a[ansMa];
        return ;
    }
    int mij = (st + dr) / 2;
    if(x <= mij)
        qryMax(nod << 1, st, mij, x, y);
    if(mij < y)
        qryMax(nod << 1|1, mij + 1, dr, x, y);
}

void Build(int nod, int st, int dr)
{
    aint[nod] = INF;
    lzy[nod] = -1;
    if(st == dr)
        return ;
    int mij = (st + dr) / 2;
    Build(nod << 1, st, mij);
    Build(nod << 1|1, mij + 1, dr);
}
void split(int nod, int f1, int f2)
{
    if(lzy[nod] == -1)
        return ;
    int val = lzy[nod];
    if(lzy[f1] == -1 || lzy[f1] > val)
        lzy[f1] = val;
    if(lzy[f2] == -1 || lzy[f2] > val)
        lzy[f2] = val;
    aint[f1] = min(aint[f1], val);
    aint[f2] = min(aint[f2], val);
    lzy[nod] = -1;
}
void Update(int nod, int st, int dr, int x, int y, int val)
{
    if(x <= st && dr <= y)
    {
        if(val < lzy[nod] || lzy[nod] == -1)
            lzy[nod] = val;
        aint[nod] = min(aint[nod], val);
        return ;
    }
    int mij = (st + dr) / 2;
    split(nod, nod << 1, nod << 1|1);
    if(x <= mij)
        Update(nod << 1, st, mij, x, y, val);
    if(mij < y)
        Update(nod << 1|1, mij + 1, dr, x, y, val);
    aint[nod] = min(aint[nod << 1], aint[nod << 1|1]);
}
void Query(int nod, int st, int dr, int x, int y)
{
    if(x <= st && dr <= y)
    {
        if(x == st || aint[nod] < ansMi)
            ansMi = aint[nod];
        return ;
    }
    int mij =(st + dr) / 2;
    split(nod, nod << 1, nod << 1|1);
    if(x <= mij)
        Query(nod << 1, st, mij, x, y);
    if(mij < y)
        Query(nod << 1|1, mij + 1, dr, x, y);
}
int biggestSmaller(int val)
{
    int p = 1, u = dis, ras = 0, mij;
    while(p <= u)
    {
        mij = (p + u) / 2;
        if(real_val[mij] <= val)
            ras = mij, p = mij + 1;
        else
            u = mij - 1;
    }
    return ras;
}
void Solve()
{
    Build(1, 1, N);
    buildMax(1, 1, dis);
    for(int R = 1; R <= N; R++)
    {
        ansMa = 0, qryMax(1, 1, dis, a[R], dis);
        if(ansMa == 0);
        else
        {
            int j = ansMa, y = ansPos;
            Update(1, 1, N, 1, j, real_val[y] - real_val[a[R]]);
            while(1)
            {
                int upY = biggestSmaller(min(real_val[a[R]] +(real_val[y] - real_val[a[R]]) / 2, real_val[y] - 1));
                if(upY < a[R])
                    break;
                ansMa = 0, qryMax(1, 1, dis, a[R], upY);
                if(ansMa == 0)
                    break;
                Update(1, 1, N, 1, ansMa, real_val[ansPos] - real_val[a[R]]);
                y = ansPos;
            }
        }
        for(auto it = qr[R].begin(); it != qr[R].end(); it ++)
        {
            Query(1, 1, N, it->first, R);
            if(ansMi < ans[it->second])
                ans[it->second] = ansMi;
        }
        updMax(1, 1, dis, a[R], R);
    }
}
int main()
{
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> v[i].first, v[i].second = i;
    sort(v + 1, v + N + 1), dis = 0;
    for(int i=1; i<=N; i++)
    {
        dis += (i == 1 || v[i].first != v[i - 1].first);
        a[v[i].second] = dis, real_val[dis] = v[i].first;
    }
    cin >> M;
    for(int i=1; i<=M; i++)
    {
        int x, y;
        cin >> x >> y;
        qr[y].push_back({x, i});
        ans[i] = INF;
    }
    Solve();
    for(int i=1; i<=N; i++)
        a[i] = dis + 1 - a[i];
    for(int i=1; i<=dis; i++)
        real_val[i] = real_val[dis] + 1 - real_val[i];
    reverse(real_val + 1, real_val + dis + 1);
    Solve();
    for(int i=1; i<=M; i++)
        cout << ans[i] << '\n';
    return 0;
}

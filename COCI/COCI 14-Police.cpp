/*
        COCI 14-Police

    Let's build an undirected graph where we connect lines i and j if we have some number which starts on line i and has to end up being in line j.

    For each connected component, there are two cases we have to deal with:

    Let's define some notations:

    a) sum_val = the number of values in lines from the connected component
    b) sum_lis = the sum of LIS of each line. For a line, we define its LIS to be the max increasing subsequence such that if we
would only have those numbers from the subsequence in the line, we can place them without lifting a single element.

    1) the connected component has a free slot => we add to the answer sum_val - sum_lis
    2) the connected component doesn't have a free slot => we add to the answer sum_val - sum_lis + 1, unless the connected component has
a single line and all of the elements from that line are placed in the right positions.

    The proof for the statements said above is explained in the official editorial.

*/
#include<bits/stdc++.h>
using namespace std;

int n, m, mat[1002][1002], tg[1002][1002], mx;
int pozL[1000002], pozC[1000002];
int poztgL[1000002], poztgC[1000002];

int aib[1002];
void add(int nod, int val)
{
    for(; nod <= m; nod += (nod & (-nod)))
        aib[nod] = max(aib[nod], val);
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans = max(ans, aib[nod]);
    return ans;
}

int fr[1002], ans;
int lis[1002], summ[1002], tag[1002];

bool adj[1002][1002], viz[1002];
vector<int> v[1002];

bool oki;
int szcc;
void dfs(int nod)
{
    ++szcc;
    viz[nod] = 1;
    if(fr[nod])
        oki = 1;
    ans += summ[nod];
    ans -= lis[nod];
    for(int i = 0; i < v[nod].size(); ++i)
    {
        int vecin = v[nod][i];
        if(viz[vecin])
            continue;
        dfs(vecin);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    bool free = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> mat[i][j];
            mx = max(mx, mat[i][j]);
            pozL[mat[i][j]] = i;
            pozC[mat[i][j]] = j;
            free |= (mat[i][j] == 0);
        }
   for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> tg[i][j];
            if(tg[i][j])
                tag[i]++;
            poztgL[tg[i][j]] = i;
            poztgC[tg[i][j]] = j;
        }
    for(int i = 1; i <= n; ++i)
    {
        memset(aib, 0, sizeof(aib));
        for(int j = 1; j <= m; ++j)
        {
            if(!mat[i][j])
            {
                fr[i]++;
                continue;
            }
            ++summ[i];
            if(poztgL[mat[i][j]] == i)
            {
                int val = compute(poztgC[mat[i][j]]) + 1;
                lis[i] = max(lis[i], val);
                add(poztgC[mat[i][j]], val);
            }
            else
                if(!adj[i][poztgL[mat[i][j]]])
                {
                    adj[i][poztgL[mat[i][j]]] = 1;
                    adj[poztgL[mat[i][j]]][i] = 1;
                    v[i].push_back(poztgL[mat[i][j]]);
                    v[poztgL[mat[i][j]]].push_back(i);
                }
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            oki = 0;
            szcc = 0;
            int anss = ans;
            dfs(i);
            if(!oki)
            {
                if(szcc == 1 && anss == ans);
                else
                    ++ans;
            }
        }
    if(!free)
    {
        if(ans == 0)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    return 0;
}

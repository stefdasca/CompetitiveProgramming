#include<bits/stdc++.h>
using namespace std;
ifstream f("pesaptecarari.in");
ofstream g("pesaptecarari.out");
int n, m;
long long k;
vector<int>v[100002];
long long cost[100002], nr[100002];
int sum[100002];
int pth[100002], mn, lg, prv[100002], po;
struct cmp
{
    bool operator()(int a, int b)
    {
        return sum[a] > sum[b];
    }
};
priority_queue<int, vector<int>, cmp>q;
void djk()
{
    for(int i = 1; i <= n; ++i)
        sum[i] = (1<<30);
    sum[1] = cost[1];
    q.push(1);
    while(!q.empty())
    {
        int nod = q.top();
        q.pop();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vec = v[nod][i];
            if(sum[nod] + cost[vec] < sum[vec])
            {
                sum[vec] = cost[vec] + sum[nod];
                prv[vec] = nod;
                q.push(vec);
            }
        }
    }
    if(sum[n] / po < mn)
    {
        lg = 0;
        mn = sum[n] / po;
        int nn = n;
        while(nn)
            pth[++lg] = nn, nn = prv[nn];
        reverse(pth + 1, pth + lg + 1);
    }
}
int main()
{
    f >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        f >> nr[i];
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
    }
    mn = (1<<30);
    for(long long i = 2; i * i <= k; ++i)
    {
        if(k % i == 0)
        {
            po = 0;
            while(k % i == 0)
                po++, k /= i;
            for(int j = 1; j <= n; ++j)
            {
                cost[j] = 0;
                while(nr[j] % i == 0)
                    ++cost[j], nr[j] /= i;
            }
            djk();
        }
    }
    if(k > 1)
    {
       po = 1;
       for(int j = 1; j <= n; ++j)
       {
            cost[j] = 0;
            while(nr[j] % k == 0)
                ++cost[j], nr[j] /= k;
       }
       djk();
    }
    g << mn << '\n';
    for(int i = 1; i <= lg; ++i)
        g << pth[i] << " ";
    return 0;
}

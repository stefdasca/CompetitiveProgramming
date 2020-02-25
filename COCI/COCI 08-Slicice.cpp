/*
        COCI 08-Slicice

    editorial: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2009/contest6_solutions/solutions.pdf

*/
#include<bits/stdc++.h>

#define maxn 100
#define maxd 1000
#define maxf (maxn+maxd+2)
#define source 0
#define sink 1

using namespace std;

int n, m, d, buys[maxn], shop[maxd][2];
int cost[maxf][maxf], dad[maxf], flow[maxf];

vector<int> nxt[maxf];

void add_edge(int a, int b, int c)
{
    cost[a][b] = c;
    nxt[a].push_back(b);
    nxt[b].push_back(a);
}

int aug_flow()
{
    memset(dad, -1, sizeof(dad));
    memset(flow, 0, sizeof(flow));

    queue<int> Q;
    flow[source] = maxf;
    Q.push(source);
    while(!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        if(curr == sink)
            return 1;
        for(int i = 0; i < nxt[curr].size(); ++i)
        {
            int t = nxt[curr][i];
            if(cost[curr][t] == 0 || dad[t] != -1)
                continue;
            dad[t] = curr;
            flow[t] = min(flow[curr], cost[curr][t]);
            Q.push(t);
        }
    }

    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        cin >> buys[i];
        d += buys[i];
    }
    d /= 2;
    for(int i = 0; i < m; ++i)
        cin >> shop[i][0] >> shop[i][1];
    for(int i = 0; i < d; ++i)
        add_edge(source, 2+i, 2);
    for(int i = 0; i < m; ++i)
    {
        add_edge(2 + i, 1 + d + shop[i][0], 2);
        add_edge(2 + i, 1 + d + shop[i][1], 2);
    }
    for(int i = m; i < d; ++i)
        for(int j = 0; j < n; ++j)
            add_edge(2 + i, 2 + d + j, 2);
    for(int i = 0; i < n; ++i)
        add_edge(2 + d + i, sink, buys[i]);
    while(aug_flow())
        for(int t = sink; t != source; t = dad[t])
        {
            cost[dad[t]][t] -= flow[sink];
            cost[t][dad[t]] += flow[sink];
        }

    cout << d << '\n';
    for(int i = 0; i < m; ++i)
        cout << shop[i][0] << " " << shop[i][1] << " " << cost[1 + d + shop[i][0]][2+i] << '\n';
    for(int i = m; i < d; ++i)
    {
        vector<int> tmp;
        for(int j = 0; j < n; ++j)
            if(cost[2 + d + j][2 + i])
                tmp.push_back(j+1);
        if(tmp.size() == 2)
            cout << tmp[0] << " " << tmp[1] << " " << 1 << '\n';
        else
            cout << tmp[0] << " " << (1 + (tmp[0] == 1)) << " " << 2 << '\n';
    }
    return 0;
}

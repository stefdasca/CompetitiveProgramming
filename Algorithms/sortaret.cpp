// https://www.infoarena.ro/problema/sortaret

#include<bits/stdc++.h>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
int n, grad[100002], m;
vector<int>v[100002];
deque<int>d;
int main()
{
    f >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        int a, b;
        f >> a >> b;
        v[a].push_back(b);
        grad[b]++;
    }
    for(int i = 1; i <= n; ++i)
        if(!grad[i])
            d.push_back(i);
    while(!d.empty())
    {
        int nod = d[0];
        g << nod << " ";
        d.pop_front();
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            --grad[vecin];
            if(grad[vecin] == 0)
                d.push_back(vecin);
        }
    }
    return 0;
}

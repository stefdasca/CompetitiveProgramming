#include<bits/stdc++.h>
using namespace std;
ifstream f("calancea.in");
ofstream g("calancea.out");
int n;
long long s, sn, cost;
int v[1000002];
deque<int>d;
int main()
{
    f >> n >> s;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    long long countiee = 0;
    int pr = n;
    for(int i = n; i >= 1; --i)
    {
        sn += v[i];
        cost += 1LL * v[i];
        while(!d.empty() && v[i] >= v[d.back()])
        {
            if(d.size() == 1)
            {
                cost -= 1LL * (pr - d.back() + 1) * v[d.back()];
                cost += 1LL * (pr - d.back() + 1) * v[i];
                d.pop_back();
            }
            else
            {
                int val = d.back();
                d.pop_back();
                cost -= 1LL * (d.back() - val) * v[val];
                cost += 1LL * (d.back() - val) * v[i];
            }
        }
        d.push_back(i);
        while(cost - sn > s)
        {
            cost -= v[d.front()];
            sn -= v[pr];
            --pr;
            if(pr < d.front())
                d.pop_front();
        }
        countiee += (pr - i + 1);
    }
    g << countiee;
    return 0;
}

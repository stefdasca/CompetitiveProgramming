
#include<bits/stdc++.h>
using namespace std;
ifstream f("base3.in");
ofstream g("base3.out");
string a, b, c;
long long len[100002];
bool viz[100002];
int v[5];
void fct(string a)
{
    for(int i = 0; i < a.size(); ++i)
        if(a[i] == '1')
        {
            long long aa = i;
            long long bb = (a.size() - i - 1);
            long long nr = a.size();
            len[(aa - bb + 50000)] = min(len[(aa - bb + 50000)], nr);
        }
}
struct cmp
{
    bool operator()(long long a, long long b)
    {
        return len[a] > len[b];
    }
};
priority_queue<long long, vector<long long>, cmp>q;
int main()
{
    f >> a;
    f >> b;
    f >> c;
    for(int i = 0; i <= 100000; ++i)
        len[i] = (1LL<<60);
    fct(a);
    fct(b);
    fct(c);
    for(int i = 0; i <= 100000; ++i)
        if(len[i] != (1LL<<60))
            q.push(i);
    v[1] = a.size();
    v[2] = b.size();
    v[3] = c.size();
    while(!q.empty())
    {
        long long dif = q.top();
        q.pop();
        if(viz[dif] == 1)
            continue;
        viz[dif] = 1;
        for(int i = 1; i <= 3; ++i)
        {
            if(dif >= v[i] && len[dif - v[i]] > len[dif] + v[i])
                len[dif - v[i]] = len[dif] + v[i], q.push(dif - v[i]);
            if(dif + v[i] <= 100000 && len[dif + v[i]] > len[dif] + v[i])
                len[dif + v[i]] = len[dif] + v[i], q.push(dif + v[i]);
        }
    }
    if(len[50000] == (1LL<<60))
        g << 0 << '\n';
    else
        g << len[50000] << '\n';
    return 0;
}

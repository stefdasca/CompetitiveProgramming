#include<bits/stdc++.h>
using namespace std;
ifstream f("fotbal3.in");
ofstream g("fotbal3.out");
int n;
int v[100002];
int is[300002];
deque<int>d1;
deque<int>d2;
int mxl[300002];
int mnl[300002];
int mxr[300002];
int mnr[300002];
long long sol;
void build()
{
    for(int i = 1; i <= n; ++i)
    {
        while(!d1.empty() && v[i] > v[d1.back()])
            d1.pop_back();
        if(d1.empty())
            mxl[v[i]] = 0;
        else
            mxl[v[i]] = d1.back();
        while(!d2.empty() && v[i] < v[d2.back()])
            d2.pop_back();
        if(d2.empty())
            mnl[v[i]] = 0;
        else
            mnl[v[i]] = d2.back();
        d1.push_back(i);
        d2.push_back(i);
    }
    d1.clear();
    d2.clear();
    for(int i = n; i >= 1; --i)
    {
        while(!d1.empty() && v[i] > v[d1.back()])
            d1.pop_back();
        if(d1.empty())
            mxr[v[i]] = n+1;
        else
            mxr[v[i]] = d1.back();
        while(!d2.empty() && v[i] < v[d2.back()])
            d2.pop_back();
        if(d2.empty())
            mnr[v[i]] = n+1;
        else
            mnr[v[i]] = d2.back();
        d1.push_back(i);
        d2.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i], is[v[i]] = i;
    build();
    for(int i = 1; i <= 300000; ++i)
    {
        if(!is[i])
            continue;
        for(int j = i; j <= 300000; j+=i)
        {
            if(!is[j])
                continue;
            if(mnl[i] > is[j] || mnr[i] < is[j])
                continue;
            if(mxl[j] > is[i] || mxr[j] < is[i])
                continue;
            int MM = max(mxl[j], mnl[i]);
            int NN = min(mnr[i], mxr[j]);
            if(is[j] < is[i])
                sol += 1LL * (is[j] - MM) * (NN - is[i]);
            else
                sol += 1LL * (NN - is[j]) * (is[i] - MM);
        }
    }
    g << sol << '\n';
    return 0;
}

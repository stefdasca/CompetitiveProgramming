#include<bits/stdc++.h>
using namespace std;
ifstream f("vmin.in");
ofstream g("vmin.out");
struct points
{
    long long a, b, pi;
};
points v[100002];
bool cmp(points a, points b)
{
    if(a.a == b.a)
        return a.b < b.b;
    return a.a > b.a;
}
long long n, m, a, b;
long long t;
int pointer;
vector<long long>slope;
vector<long long>ypoint;
vector<long long>position;
bool bad(int l1,int l2,int l3)
{
    long long product1 = (ypoint[l3] - ypoint[l1]) * (slope[l1] - slope[l2]);
    long long product2 = (ypoint[l2] - ypoint[l1]) * (slope[l1] - slope[l3]);
    if(product1 < product2)
        return 1;
    else
        return 0;
}
void insertLine(long long panta, long long start, long long poz)
{
    if(slope.size() > 0 && slope.back() == panta)
        return;
    slope.push_back(panta);
    ypoint.push_back(start);
    position.push_back(poz);
    while(slope.size()>=3 && bad(slope.size()-3,slope.size()-2,slope.size()-1))
    {
        slope.erase(slope.end() - 2);
        ypoint.erase(ypoint.end() - 2);
        position.erase(position.end() - 2);
    }
}
long long query(long long x)
{
    while(pointer < slope.size()-1 && slope[pointer+1] * x + ypoint[pointer+1] < slope[pointer] * x + ypoint[pointer])
        pointer++;
    return position[pointer];
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> v[i].a >> v[i].b, v[i].pi = i;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
        insertLine(v[i].a, v[i].b, v[i].pi);
    for(int i = 1; i <= m; ++i)
    {
        f >> t;
        g << query(t) << " ";
    }
    return 0;
}

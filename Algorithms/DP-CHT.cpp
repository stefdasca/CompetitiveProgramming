// implementation based on this romanian problem
// https://www.infoarena.ro/problema/vmin

#include<bits/stdc++.h>
using namespace std;
struct points
{
    long long a, b, pi;
};
points v[100002];
// Sort lines based on decreasing slope and in case of tie, increasing starting point
// for max value, reverse the sorting
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
    /*
    intersection(l1,l2) has x-coordinate (b1-b2) / (m2-m1)
    intersection(l1,l3) has x-coordinate (b1-b3) / (m3-m1)
    set the former greater than the latter, and cross-multiply to
    eliminate division
    */
    long long product1 = (ypoint[l3] - ypoint[l1]) * (slope[l1] - slope[l2]);
    long long product2 = (ypoint[l2] - ypoint[l1]) * (slope[l1] - slope[l3]);
    if(product1 < product2)
        return 1;
    else
        return 0;
}
void insertLine(long long panta, long long start, long long poz)
{
    if(slope.size() > 0 && slope.back() == m)
        return;
    //First, let's add it to the end
    slope.push_back(panta);
    ypoint.push_back(start);
    position.push_back(poz);
    //If the penultimate is now made irrelevant between the antepenultimate
    //and the ultimate, remove it. Repeat as many times as necessary
    while(slope.size()>=3 && bad(slope.size()-3,slope.size()-2,slope.size()-1))
    {
        slope.erase(slope.end() - 2);
        ypoint.erase(ypoint.end() - 2);
        position.erase(position.end() - 2);
    }
}
long long query(long long x)
{
    //Any better line must be to the right, since query values are
    //non-decreasing
    while(pointer < slope.size()-1 && slope[pointer+1] * x + ypoint[pointer+1] < slope[pointer] * x + ypoint[pointer])
        pointer++;
    return position[pointer];
    // return slope[pointer] * x + ypoint[pointer] (value)
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> v[i].a >> v[i].b, v[i].pi = i;
    sort(v+1, v+n+1, cmp);
    for(int i = 1; i <= n; ++i)
        insertLine(v[i].a, v[i].b, v[i].pi);
    /// If the queries were not sorted, sorting is necessary
    for(int i = 1; i <= m; ++i)
    {
        cin >> t;
        cout << query(t) << " ";
    }
    return 0;
}

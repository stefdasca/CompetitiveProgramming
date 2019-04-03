/*
        https://www.infoarena.ro/problema/munte4
        
    "Given a circular array of size n, find the suitable place to start from, such that 
    max of (v[start], v[start+1]+1, ..., v[(start+n-1) % n + 1] + (n-1)) is minimal"
    
    Create a 2 * n array, where v[i] = v[i % n + 1] + (i - 1) and we can use classical sliding window to solve the problem.
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("munte4.in");
ofstream g("munte4.out");
int n, v[2000002];
deque<int>d;
int mn = (1<<30), u;
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i], v[n+i] = v[i];
    for(int i = 2; i <= 2 * n; ++i)
        v[i] += (i-1);
    for(int i = 1; i <= 2 * n - 1; ++i)
    {
        while(!d.empty() && v[d.back()] < v[i])
            d.pop_back();
        if(d.front() == n - i)
            d.pop_front();
        d.push_back(i);
        if(i >= n)
        {
            int tp = v[d.front()] - (i - n);
            if(tp < mn)
                mn = tp, u = i - n + 1;
        }
    }
    g << u << " " << mn;
    return 0;
}

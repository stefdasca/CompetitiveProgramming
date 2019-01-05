/*
    As it is usual for such problems, we can binary search the answer

    At each step, we will try to assign toys to the weak robots, then to the small robots. Since we will use a priority queue, checking will be done
at each step in O(T log T)

    Therefore, the total complexity will be O(T log^2 T)

*/

#include"robots.h"
#include<bits/stdc++.h>
using namespace std;
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[])
{
    int j = 0;
    sort(X, X+A);
    sort(Y, Y+B);
    vector<pair<int, int> >v;
    for(int i = 0; i < T; ++i)
        v.push_back({W[i], S[i]});
    sort(v.begin(), v.end());
    int b = 0;
    int e = 10000002;
    bool findd = 0;
    int ans = 0;
    while(b <= e)
    {
        int mid = (b + e) / 2;
        priority_queue<int>D;
        int ptra = 0;
        for(int i = 0; i < A; ++i)
        {
            while(ptra < T && X[i] > v[ptra].first)
                D.push(v[ptra].second), ++ptra;
            for(int j = 1; j <= mid && !D.empty(); ++j)
                D.pop();
        }
        for(; ptra < T; ++ptra)
            D.push(v[ptra].second);
        for(int i = B-1; i >= 0; --i)
        {
            for(int j = 1; j <= mid && !D.empty(); ++j)
                if(D.top() < Y[i])
                    D.pop();
                else
                    break;
        }
        bool gg = (D.empty());
        if(gg)
            findd = 1, ans = mid, e = mid - 1;
        else
            b = mid + 1;
    }
    if(!findd)
        return -1;
    return ans;
}

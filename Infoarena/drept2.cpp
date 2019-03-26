/*
            Infoarena drept2(https://www.infoarena.ro/problema/drept2)
            
     "Given a N*M binary matrix, where in each line, there is just one segment with elements equal to one, find the number of rectangles
of size A*B which have full 1"

    One can solve this problem using deques and sliding window minimum and maximum, while also being careful at case when A = B
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("drept2.in");
ofstream g("drept2.out");
int n, m, a, b;
int bg[2100002], sf[2100002], ln;
int main()
{
    f >> m >> n >> a >> b;
    f >> bg[1] >> ln;
    sf[1] = bg[1] + ln - 1;
    for(int i = 2; i <= n; ++i)
    {
        int x;
        f >> bg[i];
        f >> x;
        ln += x;
        sf[i] = bg[i] + ln - 1;
    }
    deque<int>lft, rgt;
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!lft.empty() && lft.front() == i - a)
            lft.pop_front();
        if(!rgt.empty() && rgt.front() == i - a)
            rgt.pop_front();
        while(!lft.empty() && bg[i] > bg[lft.back()])
            lft.pop_back();
        while(!rgt.empty() && sf[i] < sf[rgt.back()])
            rgt.pop_back();
        lft.push_back(i);
        rgt.push_back(i);
        if(i >= a)
            if(sf[rgt.front()] - bg[lft.front()] + 1 >= b)
                ans += 1LL * ((sf[rgt.front()] - bg[lft.front()] + 1) - b + 1);
    }
    lft.clear();
    rgt.clear();
    for(int i = 1; i <= n; ++i)
    {
        if(!lft.empty() && lft.front() == i - b)
            lft.pop_front();
        if(!rgt.empty() && rgt.front() == i - b)
            rgt.pop_front();
        while(!lft.empty() && bg[i] > bg[lft.back()])
            lft.pop_back();
        while(!rgt.empty() && sf[i] < sf[rgt.back()])
            rgt.pop_back();
        lft.push_back(i);
        rgt.push_back(i);
        if(i >= b)
            if(sf[rgt.front()] - bg[lft.front()] + 1 >= a)
                ans += 1LL * ((sf[rgt.front()] - bg[lft.front()] + 1) - a + 1);
    }
    if(a == b)
        ans /= 2;
    g << ans;
    return 0;
}

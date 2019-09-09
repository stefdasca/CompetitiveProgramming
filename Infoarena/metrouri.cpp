/*
        infoarena metrouri - Romanian IOI selection task(2011)

    "Given a subway line with n stations, m people, (ai, bi) = ith people arrives at station ai at time bi and k trains,
find a way to schedule the trains such that the sum of the costs of each train is minimal. The cost of a train is the maximum
amount of time one of its passengers had to wait for it"

    Let's move the passengers to station 1 and sort the resulting times, therefore the problem transforms in finding k non-overlapping
subarrays such that sum of (maxi - mini) is minimal, where maxi and mini = the max and the min value of subarray i. This can easily be
done using any data structure which gets min value in O(log n).

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("metrouri.in");
ofstream g("metrouri.out");
int n, m, k;
int ar[100002];
multiset<int>dif;
int main()
{
    f >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
    {
        int s, t;
        f >> s >> t;
        t -= (s-1);
        ar[i] = t;
    }
    sort(ar+1, ar+m+1);
    for(int i = 1; i < m; ++i)
        dif.insert(ar[i+1] - ar[i]);
    k = max(0, m - k);
    int ans = 0;
    while(k)
    {
        ans += *dif.begin();
        dif.erase(dif.begin());
        --k;
    }
    g << ans;
    return 0;
}

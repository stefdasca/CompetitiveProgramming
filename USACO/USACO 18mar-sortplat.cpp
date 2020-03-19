/*
            USACO 18mar-sortplat

    Instead of finding the number of operations which will be done by the bubble sort algorithm, we can find instead for each i when
will we have the sorted sequence 1...i at the first i positions and the ith position has the element equal to the ith number in the sorted
order.

    We can observe that we firstly have to find the rightmost number smaller than the ith number and count how many bigger numbers than
the ith number we're left with in range [1, position_of_rightmost_smaller]. Finding both position_of_rightmost_smaller and the number of
bigger numbers can be done with fenwick tree.

    Last but not least, we need to add one to the number of steps necessary to bring the ith number to the right position if
position_of_rightmost_smaller is bigger than position of ith number and if the counter for some number is equal to zero, we
need to make it equal to 1 because every number will be counted at least once by the quickish sort algorithm.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("sort.in");
ofstream g("sort.out");
int n, v[100002], sz, sa[100002], stp[100002];

bool cmp(int a, int b)
{
    if(v[a] == v[b])
        return a < b;
    return v[a] < v[b];
}
int aib[100002];
void add(int nod, int val)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += val;
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
int mxpoz[100002];
int main()
{
    f >> n;
    sz = n;
    for(int i = 1; i <= n; ++i)
    {
        f >> v[i];
        sa[i] = i;
        add(i, 1);
    }
    sort(sa + 1, sa + n + 1, cmp);
    for(int i = n; i >= 1; --i)
    {
        add(sa[i], -1);
        int vx = compute(n);
        int st = sa[i];
        int dr = n;
        int ans = n;
        if(vx - compute(sa[i]))
            stp[sa[i]]++;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(compute(mid) == vx)
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        mxpoz[sa[i]] = ans;
    }
    for(int i = 1; i <= n; ++i)
        add(i, 1);
    for(int i = 1; i <= n; ++i)
    {
        int poz = sa[i];
        add(poz, -1);
        stp[sa[i]] += compute(mxpoz[poz]);
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(stp[i] == 0)
            stp[i] = 1;
        ans += stp[i];
    }
    g << ans << '\n';
    return 0;
}

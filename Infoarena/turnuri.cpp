/*
                    Infoarena turnuri

    * We can find using deques the rightmost position < i and the leftmost position > i such that v[i] is smaller than the values from both positions.

    * We will keep in vectors(or in DSU-like manner for time optimizations) the elements for which the leftmost position > i is i.

    * At each removal, we have to consider the contribution of position i to the sum, both directly and indirectly.
The direct contribution is the number of positions which are visible from i, and the indirect contribution is the difference created
when dropping element i(each position which can see up to position i will see up to a new position, this can be found using the vectors previously created)

    * After we considered the contribution to the sum for each position, we will sum up the values and print the answer, thus getting O(n).

    * The time limit is very tight(even O(n) can TLE), so in case you need to get 100 with O(n) you can use this
reader parsing template. https://www.infoarena.ro/parsare-fisier-intrare

    * Alternative solution without DSU-like data storing(it needs parsing)
        https://www.infoarena.ro/job_detail/2447490?action=view-source

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("turnuri.in");
ofstream g("turnuri.out");
int n, v[1000002];
long long sum1;
int am[1000002], nxt[1000002], ct[1000002];
long long total, drp[1000002];
int sp[1000002];
int tp[1000002], cr[1000002], nxxt[1000002];
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    deque<int>d;
    for(int i = n; i >= 1; --i)
    {
        while(!d.empty() && v[i] > v[d.back()])
            d.pop_back();
        if(!d.empty())
        {
            if(!tp[d.back()])
                tp[d.back()] = cr[d.back()] = i;
            else
                nxxt[cr[d.back()]] = i, cr[d.back()] = i;
        }
        d.push_back(i);
    }
    d.clear();
    for(int i = 1; i <= n; ++i)
    {
        while(!d.empty() && v[i] > v[d.back()])
            d.pop_back();
        if(!d.empty())
        {
            int z = d.back();
            nxt[i] = z;
            int pp = tp[z];
            while(tp[z] && v[i] > v[tp[z]])
                tp[z] = nxxt[tp[z]];
            pp = tp[z];
            if(!pp)
                drp[z] += (z - nxt[z] - (nxt[z] == 0));
            else
                drp[z] = drp[z] + (z - pp);
        }
        if(nxt[i] == 0)
            am[i] = (i - 1), sum1 = sum1 + (i - 1);
        else
            am[i] = i - nxt[i], sum1 = sum1 + i - nxt[i];
        d.push_back(i);
    }
    for(int i = 1; i <= n; ++i)
        sp[nxt[i]]++, sp[i]--;
    for(int i = 1; i <= n; ++i)
    {
        sp[i] += sp[i-1];
        long long sum2 = sum1 - am[i];
        sum2 = sum2 - sp[i] + drp[i];
        total = total + sum2;
    }
    g << total << '\n';
    return 0;
}

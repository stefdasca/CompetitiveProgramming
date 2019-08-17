/*
    "Given a permutation of the first n natural numbers, perform the following algorithm: at step i, find the position of value i and put
all the elements left of i at the end of the array, while keeping the original order of the array and remove i from array. Output the sum of positions"

    * It is obvious that we are required to implement the replacing process as fast as possible.

    * We can observe that the remaining array will be a cyclic permutation of the original array, with some elements removed. Thus, we can use BIT to implement the update/query functions.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("permsort.in");
ofstream g("permsort.out");
int n, poz[1000002], st;
int aib[1000002];
void add(int nod, int qt)
{
    for(; nod <= n; nod += (nod & (-nod)))
        aib[nod] += qt;
}
int compute(int nod)
{
    int ans = 0;
    for(; nod; nod -= (nod & (-nod)))
        ans += aib[nod];
    return ans;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        f >> nr;
        poz[nr] = i;
        add(i, 1);
    }
    st = 1;
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(poz[i] >= st)
            ans += (compute(poz[i]) - compute(st - 1));
        else
            ans = ans + (compute(n) - compute(st - 1)) + compute(poz[i]);
        st = poz[i] + 1;
        if(st > n)
            st = 1;
        add(poz[i], -1);
    }
    g << ans;
    return 0;
}

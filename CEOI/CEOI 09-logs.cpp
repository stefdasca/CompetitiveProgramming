/*
            CEOI 09-logs

    The time limit is very tight, so we need an O(n * m) solution.

    * It's obvious that the optimal solution is to take for each row the columns with the most consecutive ones.
    * But here is the catch, O(n * m) time and memory solution gets TLE so we need to get something new.
    * One can observe that we can keep the list sorted in O(m) instead of O(m log m), if we iterate through
the sorted order of the list of elements so far from the right to the left. Afterwards, we are simply going
to iterate in descending order in this list to update the answer.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("logs.in");
ofstream g("logs.out");
int n, m;
char linie[1502];
int ans, sp[1502], init[1502];
int sp2[1502], init2[1502];
int main()
{
    f >> n >> m;
    for(int i = 0; i < m; ++i)
        init[i] = i;
    for(int i = 1; i <= n; ++i)
    {
        f >> linie;
        int a = 0;
        int b = m-1;
        for(int j = m-1; j >= 0; --j)
        {
            if(linie[init[j]] == '0')
            {
                sp2[a] = 0;
                init2[a] = init[j];
                ++a;
            }
            else
            {
                sp2[b] = sp[j] + 1;
                init2[b] = init[j];
                --b;
            }
        }
        for(int j = m-1; j >= 0; --j)
        {
            if((m - j) * sp2[j] > ans)
                ans = (m - j) * sp2[j];
            sp[j] = sp2[j];
            init[j] = init2[j];
        }
    }
    g << ans << '\n';
    return 0;
}

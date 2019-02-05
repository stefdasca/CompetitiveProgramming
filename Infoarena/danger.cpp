/*
        Infoarena danger(https://www.infoarena.ro/problema/danger)

    "Given a n*m matrix, transform it in a m*n matrix such that ith column is formed by elements from ith line
and max value of sum of the largest 2 elements in a line is minimal"

    We can use greedy to solve this problem, line by line. At each step, we will take the biggest element and match it
with the smallest possible elements from the other rows


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("danger.in");
ofstream g("danger.out");
int n, m;
multiset<int>s[100002];
multiset<pair<int, int> >t;
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            int nr;
            f >> nr;
            s[i].insert(nr);
            t.insert({nr, i});
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        pair<int, int> p = *t.rbegin();
        t.erase(t.find(p));
        s[p.second].erase(s[p.second].find(p.first));
        for(int j = 1; j <= n; ++j)
        {
            if(j == p.second)
                g << p.first << " ";
            else
            {
                int x = *s[j].begin();
                t.erase(t.find(make_pair(x, j)));
                g << x << " ";
                s[j].erase(s[j].begin());
            }
        }
        g << '\n';
    }
    return 0;
}

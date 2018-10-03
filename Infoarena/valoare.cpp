#include<bits/stdc++.h>
using namespace std;
ifstream f("valoare.in");
ofstream g("valoare.out");
int n;
bool froze = 0;
int v[50002];
long long s, mx;
multiset<long long>ss;
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i], ss.insert(v[i]);
    sort(v+1, v+n+1);
    for(int i = 1; i <= n; ++i)
    {
        if(froze)
        {
            g << mx << '\n';
            continue;
        }
        multiset<long long> ::iterator it;
        it = ss.begin();
        if(*it > mx+1)
            froze = 1;
        else
        {
            it = ss.lower_bound(mx+1);
            if(it == ss.end() || *it > mx+1)
                --it;
            mx += *it;
            ss.erase(it);
        }
        g << mx << '\n';
    }
    return 0;
}

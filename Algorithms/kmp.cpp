// https://www.infoarena.ro/problema/strmatch

#include<bits/stdc++.h>
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
int n, m;
string a, b;
int pi[2000002];
vector<int>ans;
int main()
{
    f >> a;
    f >> b;
    a = ' ' + a;
    b = ' ' + b;
    m = a.size(), n = b.size();
    int k = 0;
    for(int i = 2; i < m; ++i)
    {
        while(k && a[k + 1] != a[i])
            k = pi[k];
        if(a[k + 1] == a[i])
            k++;
        pi[i] = k;
    }
    int q = 0;
    for(int i = 1; i < n; ++i)
    {
        while(q && a[q + 1] != b[i])
            q = pi[q];
        if(a[q + 1] == b[i])
            ++q;
        if(q == m - 1)
            ans.push_back(i - m + 1);
    }
    g << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
    {
        g << ans[i] << " ";
        if(i == 999)
            break;
    }
    return 0;
}

#include<bits/stdc++.h>
#define maxdim 100005
using namespace std;
ifstream f("taietura.in");
ofstream g("taietura.out");
int n;
int v[maxdim], st[maxdim], ed[maxdim];
unordered_map<long long, int> fr;
int main()
{
    f>>n;
    for (int i = 1; i <= n; ++i)
        f>>v[i];
    fr[0] = 1;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += v[i];
        ed[i] = fr[sum];
        ++fr[sum];
    }
    fr.clear();
    fr[0] = 1;
    sum = 0;
    for (int i = n; i >= 1; --i) {
        sum += v[i];
        st[i] = fr[sum];
        ++fr[sum];
    }
    long long sol = 0;
    for (int i = 1; i <= n; ++i) {
        sol += st[i] - ed[i - 1];
        g<<sol<<" ";
    }
    return 0;
}

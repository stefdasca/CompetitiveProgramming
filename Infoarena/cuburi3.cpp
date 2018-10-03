#include <bits/stdc++.h>
using namespace std;
ifstream in("cuburi3.in");
ofstream out("cuburi3.out");
int n, dp[4010], s[4010], k, v;
struct lol{
    int l, g, x;
};
lol a[4010];
vector <int> sol;
bool cmp(lol a, lol b){
    if(a.l == b.l)
        return a.g < b.g;
    return a.l < b.l;
}
int main(){
    in >> n;
    for(int i = 1; i <= n; i++)
        in >> a[i].l >> a[i].g, a[i].x = i;
    sort(a+1, a+n+1, cmp);
    dp[1] = a[1].l;
    for(int i = 2; i <= n; i++){
        k = v = 0;
        for(int j = 1; j < i; j++)
            if(dp[j] > k && a[j].g <= a[i].g)
                k = dp[j], v = j;
        dp[i] = k + a[i].l;
        s[i] = v;
    }
    k = 0;
    for(int i = n; i; i--)
        if(dp[i] > k)
            k = dp[i],v = i;
    sol.push_back(a[v].x);
    while(s[v])
        sol.push_back(a[s[v]].x), v = s[v];
    out << sol.size() << ' ' << k << '\n';
    for(auto i : sol)
        out << i << '\n';
    return 0;
}

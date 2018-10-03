#include<bits/stdc++.h>
#define DIM 5005
using namespace std;
ifstream fin("inversari.in");
ofstream fout("inversari.out");
int n, m;
int solution[100010], v[DIM];
int OLD = 0;
int NEW = 1;
int dp[2][DIM], d[2][DIM];
vector< pair<int, int> > L[DIM];
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= m; i++) {
        int x, y;
        fin >> x >> y;
        L[y - x + 1].push_back(make_pair(y, i));
    }
    for (int lg = 1; lg <= n; lg++) {
        for (int i = 0; i < L[lg].size(); i++)
            solution[L[lg][i].second] = dp[OLD][L[lg][i].first];
        for (int i = lg + 1; i <= n; i++)
            d[NEW][i] = d[OLD][i] + (v[i - lg] > v[i]);
        for (int i = lg + 1; i <= n; i++)
            dp[NEW][i] = dp[OLD][i - 1] + d[NEW][i];
        swap(OLD,NEW);
    }
    for (int i = 1; i <= m; i++)
        fout << solution[i] <<'\n';
    return 0;

}

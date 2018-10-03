#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void Update(vector<int>&frecv, vector<int>&buckets, int bucket, int i, int val)
{
    if (frecv[i] == 0)
        buckets[i/bucket]++;
    frecv[i] += val;
    if (frecv[i] == 0)
        buckets[i/bucket]--;
}
int Query(vector<int>&frecv,vector<int>&buckets, int bucket)
{
    int i;
    for(i = 0; buckets[i] == bucket; i++);
    for(i = bucket*i;frecv[i] != 0; i++);
    return i;
}
int main() {
    freopen("mexitate.in", "r", stdin);
    freopen("mexitate.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<int>>a(n, vector<int>(m,0));
    vector<int>frecv(n * m + 5), buckets(n * m + 5);
    int bucket = 1;
    for(;bucket*bucket < n*m ;bucket++);
    Update(frecv, buckets, bucket, 0, 1);
    for(auto&line: a)
        for(auto &elem: line)
        {
            cin >> elem;
            assert(1 <= elem && elem <= n * m);
        }
    if(k > l)
    {
        vector<vector<int>> b = a;
        swap(n, m);
        swap(k, l);
        a = vector<vector<int>>(n, vector<int>(m,0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = b[j][i];
    }
    for(int i = 0; i < k; i++)
        for (int j = 0;j < l;j ++)
            Update(frecv, buckets, bucket, a[i][j], 1);
    const int left[] = {0, m - 1};
    const int right[] = {m, -1};
    long long sol = 1;
    auto mat = vector<vector<int>>(n, vector<int>(m,0));;
    for(int i = 0; i + k  - 1 < n; i++) {
        int dir = 1;
        if (i&1)
            dir = -1;
        for(int j = left[i&1]; j + dir * (l - 1) != right[i&1]; j += dir)
         {
            int mex = Query(frecv, buckets, bucket);
            mat[i][min(j, j + dir * (l - 1))] = mex;
            sol = 1LL*sol*mex%MOD;
            int nextCol = j + dir * l;
            if(0 <= nextCol &&  nextCol < m)
                for(int step = 0; step < k; step++) {
                    Update(frecv, buckets, bucket, a[i+step][j], -1);
                    Update(frecv, buckets, bucket, a[i+step][nextCol], 1);
                }
        }
        if (i + k < n)
            for(int step = 0 ; step < l; step++) {
                int col = left[(i & 1) xor 1] + (-1) *dir * step;
                Update(frecv, buckets, bucket, a[i][col], -1);
                Update(frecv, buckets, bucket, a[i + k][col], 1);
            }
    }
    cout << sol <<"\n";
    return 0;
}



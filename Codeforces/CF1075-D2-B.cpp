#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m;
int q[200002];
bool tx[200002];
int v[200002];
int v2[200002];
int ans[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n + m; ++i)
        cin >> q[i];
    for(int i = 1; i <= m + n; ++i)
        cin >> tx[i];
    int a = 0;
    int b = 0;
    for(int i = 1; i <= n + m; ++i)
    {
        if(tx[i])
            v2[++b] = q[i];
        else
            v[++a] = q[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] <= v2[1]){
            ans[1]++;
            continue;
        }
        if(v[i] >= v2[m]){
            ans[m]++;
            continue;
        }
        int b = 1;
        int e = m;
        int anss = 0;
        while(b <= e)
        {
            int mid = (b+e)/2;
            if(v2[mid] < v[i] && v[i] < v2[mid + 1])
            {
                anss = mid;
                break;
            }
            else
                if(v2[mid] < v[i])
                    b = mid + 1;
                else
                    e = mid - 1;
        }
        if(v[i] - v2[anss] <= v2[anss+1] - v[i])
            ans[anss]++;
        else
            ans[anss+1]++;
    }
    for(int i = 1; i <= m; ++i)
        cout << ans[i] << " ";
    return 0;
}

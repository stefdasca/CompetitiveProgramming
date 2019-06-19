#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct wilted
{
    int val;
    int pi;
};
wilted v[200002];
bool cmp(wilted a, wilted b)
{
    return a.val < b.val;
}
bool isProgression[200002], isProgressionR[200002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i].val;
        v[i].pi = i;
    }
    sort(v+1, v+n+1, cmp);
    if(n <= 3)
    {
        cout << 1;
        return 0;
    }
    isProgression[1] = isProgression[2] = 1;
    int df = v[2].val - v[1].val;
    for(int i = 3; i <= n; ++i)
        if(v[i].val - v[i-1].val == df && isProgression[i-1])
            isProgression[i] = 1;
    isProgressionR[n] = isProgressionR[n-1] = 1;
    df = v[n].val - v[n-1].val;
    for(int i = n-2; i >= 1; --i)
        if(v[i+1].val - v[i].val == df && isProgressionR[i+1])
            isProgressionR[i] = 1;
    if(isProgression[n])
    {
        cout << v[1].pi;
        return 0;
    }
    if(isProgression[n-1])
    {
        cout << v[n].pi;
        return 0;
    }
    if(isProgressionR[2])
    {
        cout << v[1].pi;
        return 0;
    }
    for(int i = 2; i < n; ++i)
    {
        if(isProgression[i-1] && isProgressionR[i+1])
        {
            if(i == 2)
            {
                if(v[4].val - v[3].val == v[3].val - v[1].val)
                {
                    cout << v[2].pi;
                    return 0;
                }
            }
            if(i == n-1)
            {
                if(v[n-2].val - v[n-3].val == v[n].val - v[n-2].val)
                {
                    cout << v[n-1].pi;
                    return 0;
                }
            }
            int aa = v[i-1].val - v[i-2].val;
            int bb = v[i+1].val - v[i-1].val;
            int cc = v[i+2].val - v[i+1].val;
            if(aa == bb && bb == cc)
            {
                cout << v[i].pi;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}


/*
        IZhO 17-money

    It is obvious that we split the array in continuous and increasing sequences. If we know the first element we are going to insert at a step i,
we need to know the boundaries of the interval we can add at this step, and this can be done using sets.

    Since the time limit is tight, I had to add several constant factor optimization in order to make my approach pass.

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

using namespace std;

typedef long long ll;

int n, ans = 1, v[1000002], mx[1000002];
bool iz[1000002];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        mx[i] = max(mx[i-1], v[i]);
    }
    iz[v[1]] = 1;
    s.insert(v[1]);
    int i = 2;
    while(i <= n && v[i] >= v[i-1])
    {
        if(!iz[v[i]])
            s.insert(v[i]);
        ++i;
    }
    for(; i <= n; )
    {
        ++ans;
        if(v[i] >= mx[i])
        {
            int j = i+1;
            if(!iz[v[i]])
                iz[v[i]] = 1, s.insert(v[i]);
            while(j <= n && v[j] >= v[j-1])
            {
                if(!iz[v[j]])
                    iz[v[j]] = 1, s.insert(v[j]);
                ++j;
            }
            i = j;
        }
        else
        {
            set<int> ::iterator it = s.lower_bound(v[i]);
            set<int> ::iterator it2 = it;
            int val = *it;
            if(it == s.begin() && v[i] < val)
            {
                int j = i+1;
                if(!iz[v[i]])
                    iz[v[i]] = 1, s.insert(v[i]);
                while(j <= n && v[j] >= v[j-1] && v[j] <= val)
                {
                    if(!iz[v[j]])
                        iz[v[j]] = 1, s.insert(v[j]);
                    ++j;
                }
                i = j;
            }
            else
            {
                if(val == v[i])
                {
                    ++it2;
                    if(it2 == s.end())
                    {
                        int j = i+1;
                        if(!iz[v[i]])
                            iz[v[i]] = 1, s.insert(v[i]);
                        while(j <= n && v[j] >= v[j-1])
                        {
                            if(!iz[v[j]])
                                iz[v[j]] = 1, s.insert(v[j]);
                            ++j;
                        }
                        i = j;
                    }
                    else
                    {
                        int j = i+1;
                        int val2 = *it2;
                        if(!iz[v[i]])
                            iz[v[i]] = 1, s.insert(v[i]);
                        while(j <= n && v[j] >= v[j-1] && v[j] <= val2)
                        {
                            if(!iz[v[j]])
                                iz[v[j]] = 1, s.insert(v[j]);
                            ++j;
                        }
                        i = j;
                    }
                }
                else
                {
                    int j = i+1;
                    if(!iz[v[i]])
                        iz[v[i]] = 1, s.insert(v[i]);
                    while(j <= n && v[j] >= v[j-1] && v[j] <= val)
                    {
                        if(!iz[v[j]])
                            iz[v[j]] = 1, s.insert(v[j]);
                        ++j;
                    }
                    i = j;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

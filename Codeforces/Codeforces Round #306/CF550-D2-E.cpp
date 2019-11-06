#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, v[100002], pd[100002], pi[100002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    if(v[n] == 1)
    {
        cout << "NO";
        return 0;
    }
    if(n == 1)
    {
        cout << "YES\n0";
        return 0;
    }
    vector<pair<int, int> >seg;
    int st = 1;
    int dr = 1;
    for(int i = 2; i <= n-1; ++i)
    {
        if(v[i] == v[i-1])
            ++dr;
        else
        {
            seg.pb({st, dr});
            st = dr = i;
        }
    }
    seg.pb({st, dr});
    for(int i = seg.size() - 1; i >= 0; --i)
    {
        if(v[seg[i].fi] == 0)
        {
            if(i == seg.size() - 1)
            {
                if(seg[i].fi == seg[i].se)
                {
                    if(i <= 1)
                    {
                        cout << "NO";
                        return 0;
                    }
                    else
                    {
                        pd[seg[i-1].fi]++;
                        pi[seg[i].se]++;
                        deque<int>zero;
                        zero.push_back(seg[i].fi);
                        for(int j = seg[i-2].se; j >= seg[i-2].fi; --j)
                             zero.push_front(j);
                        while(zero.size() >= 2)
                        {
                            pi[zero.back()]++;
                            zero.pop_back();
                            pd[zero.back()]++;
                            zero.pop_back();
                        }
                        i -= 2;
                    }
                }
                else
                {
                    deque<int>zero;
                    for(int j = seg[i].se; j >= seg[i].fi; --j)
                         zero.push_front(j);
                    while(zero.size() >= 2)
                    {
                        pi[zero.back()]++;
                        zero.pop_back();
                        pd[zero.back()]++;
                        zero.pop_back();
                    }
                }
            }
            else
            {
                deque<int>zero;
                for(int j = seg[i].se; j >= seg[i].fi; --j)
                     zero.push_front(j);
                while(zero.size() >= 2)
                {
                    pi[zero.back()]++;
                    zero.pop_back();
                    pd[zero.back()]++;
                    zero.pop_back();
                }
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= pd[i]; ++j)
            cout << "(";
        cout << v[i];
        for(int j = 1; j <= pi[i]; ++j)
            cout << ")";
        if(i < n)
            cout << "->";
    }
    return 0;
}

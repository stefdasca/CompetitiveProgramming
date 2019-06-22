#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, q;
int ansA[1000002];
int ansB[1000002];
int period, start;
map<pair<int, int>, int>mp;
int v[100002];
deque<int>pozitii;
long long pv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], pozitii.push_back(i);
    for(int i = 1; i <= 1000000; ++i)
    {
        int pA = pozitii.front();
        pozitii.pop_front();
        int pB = pozitii.front();
        ansA[i] = pA;
        ansB[i] = pB;
        pozitii.pop_front();
        if(mp.find({pA, pB}) != mp.end())
        {
            period = i - mp[{pA, pB}];
            start = mp[{pA, pB}];
            break;
        }
        mp[{pA, pB}] = i;
        if(v[pA] > v[pB])
        {
            pozitii.push_front(pA);
            pozitii.push_back(pB);
        }
        else
        {
            pozitii.push_front(pB);
            pozitii.push_back(pA);
        }
    }
    for(int i = 1; i <= q; ++i)
    {
        cin >> pv;
        if(pv < start)
            cout << v[ansA[pv]] << " " << v[ansB[pv]] << '\n';
        else
        {
            long long rest = (pv - start) % period;
            cout << v[ansA[start + rest]] << " " << v[ansB[start + rest]] << '\n';
        }
    }
    return 0;
}


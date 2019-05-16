#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, x;
int v[1000002];
bool sorted[1000002];
int fi[1000002], lst[1000002];
int prvv[1000002];
long long soll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(fi[v[i]] == 0)
            fi[v[i]] = i;
        lst[v[i]] = i;
    }
    int nr = 0;
    int prvnenul = 0;
    deque<int>d;
    deque<int>nnn;
    int nn = 0;
    for(int i = x; i >= 1; --i)
    {
        if(fi[i] == 0)
            sorted[i] = 1, nr = i, d.push_front(i);
        else
            if(!prvnenul)
                sorted[i] = 1, nr = i, prvnenul = fi[i], d.push_front(i), ++nn, nnn.push_front(i);
            else
                if(lst[i] <= prvnenul)
                    sorted[i] = 1, prvnenul = fi[i], nr = i, d.push_front(i), ++nn, nnn.push_front(i);
                else
                    break;
    }
    prvnenul = 0;
    for(int i = 1; i <= x; ++i)
    {
        if(!d.empty() && d.front() == i)
        {
            if(fi[d.front()] != 0)
                --nn;
            if(!nnn.empty() && nnn.front() == d.front())
                nnn.pop_front();
            d.pop_front();
        }
        if(i > 1)
            while(!d.empty() && lst[i-1] > fi[d.front()] && nn)
            {
                if(lst[i-1] <= fi[nnn.front()])
                    break;
                if(fi[d.front()] != 0)
                    --nn;
                if(!nnn.empty() && nnn.front() == d.front())
                    nnn.pop_front();
                d.pop_front();
            }
        soll = soll + d.size() + 1;
       // cout << i << " " << soll << '\n';
        if(fi[i])
        {
            if(prvnenul < fi[i]);
            else
                break;
            prvnenul = lst[i];
        }
    }
    cout << soll;
    return 0;
}

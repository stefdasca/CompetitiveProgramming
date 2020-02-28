/*
        POI 04-Gates

    We can fix the gate states to 0, respectively to 1 and see what happens(I will use 1-indexing for my explanations)

    During one such run(the other one is similar), we are going to correct the gate states based on the gate states with different state(at the beginning,
gate 1 and gate 2 will have different color, and one of them will be used to start correcting the gate states of the other gates.

    Processing the gate updates can be done using BFS in O(n + m) time.

*/
#include<bits/stdc++.h>
using namespace std;

int n;

vector<int> v[10002];

int val[10002], delta[10002];

int ansa[10002], ansb[10002];

int viz[10002];

int chk(int x)
{
    if(x == 0)
        return 2;
    if(x > 0)
        return 1;
    return 0;
}
void bfs(int wh)
{
    deque<int> d;
    for(int i = 1; i <= n; ++i)
        viz[i] = 0;
    for(int i = 1; i <= n; ++i)
        if(val[i] != chk(delta[i]))
            d.push_back(i);

    while(!d.empty())
    {
        int nod = d[0];
        d.pop_front();
        if(viz[nod] >= 2)
            continue;
        ++viz[nod];
        int x = val[nod];
        int y = chk(delta[nod]);
        for(int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i];
            if(x == 0)
                ++delta[vecin];
            if(x == 1)
                --delta[vecin];
            if(y == 0)
                --delta[vecin];
            if(y == 1)
                ++delta[vecin];
            if(val[vecin] != chk(delta[vecin]))
                d.push_back(vecin);
        }
        val[nod] = y;
    }
    for(int i = 1; i <= n; ++i)
        if(wh == 1)
            ansa[i] = val[i];
        else
            ansb[i] = val[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 3; i <= n; ++i)
    {
        int x;
        cin >> x;
        for(; x; --x)
        {
            int vec;
            cin >> vec;
            ++vec;
            v[vec].push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        delta[i] = 0;
        val[i] = 0;
    }
    delta[1] = -1, delta[2] = 1;
    val[1] = 0, val[2] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < v[i].size(); ++j)
        {
            int vecin = v[i][j];
            if(i == 2)
                delta[vecin]++;
            else
                delta[vecin]--;
        }
    bfs(1);
    for(int i = 1; i <= n; ++i)
    {
        delta[i] = 0;
        val[i] = 1;
    }
    delta[1] = -1, delta[2] = 1;
    val[1] = 0, val[2] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < v[i].size(); ++j)
        {
            int vecin = v[i][j];
            if(i == 1)
                delta[vecin]--;
            else
                delta[vecin]++;
        }
    bfs(2);
    for(int i = 1; i <= n; ++i)
    {
        if(ansa[i] != ansb[i])
            cout << "?\n";
        else
            cout << (ansa[i] == 0 ? "0\n" : (ansa[i] == 1 ? ("1\n") : ("1/2\n")));
    }
    return 0;
}

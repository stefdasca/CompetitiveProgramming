#include<bits/stdc++.h>
using namespace std;
ifstream fi("banuti.in");
ofstream fo("banuti.out");
int n, mini, valmin[5002], gg, v[50002], mincost[5002];
bool viz[5002], wasst[5002];
int main()
{
    fi >> n;
    for(int i = 1; i <= n; ++i)
    {
        int nr;
        fi >> nr;
        if(i==1)
            gg = nr;
        else
            gg = __gcd(nr, gg);
        v[i] = nr;
    }
    if(gg > 1)
    {
        return fo << -1, 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1)
            mini = v[i];
        else
            mini = min(mini, v[i]);
    }
    int st = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(valmin[v[i] % mini] == 0)
            valmin[v[i] % mini] = v[i];
        else
            valmin[v[i] % mini] = min(valmin[v[i] % mini], v[i]);
    }
    if(mini == 1)
    {
        return fo << 0, 0;
    }
    st = 0;
    int nrviz = 0;
    viz[st] = 1;
    for(int R = 1; R <= mini; ++R)
    {
        wasst[st] = 1;
        if(R == mini)
        {
            fo << mincost[st] - mini;
            return 0;
        }
        for(int j = 0; j < mini; ++j)
        {
            if(!valmin[j])
                continue;
            int qx = (st + valmin[j]) % mini;
            if(!viz[qx] || mincost[st] + valmin[j] < mincost[qx])
            {
                viz[qx] = 1;
                mincost[qx] = mincost[st] + valmin[j];
            }
        }
        st = -1;
        for(int j = 0; j < mini; ++j)
        {
            if(wasst[j])
                continue;
            if(!viz[j])
                continue;
            if(st == -1 || mincost[j] < mincost[st])
                st = j;
        }
    }
    return 0;
}

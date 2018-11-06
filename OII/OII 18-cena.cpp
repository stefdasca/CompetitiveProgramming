#include<bits/stdc++.h>
using namespace std;
long long conta(int S, int s[], int P, int p[])
{
    long long ans = 0;
    vector<int>v[102];
    for(int i = 0; i < P; ++i)
        v[p[i]].push_back(i);
    int mini[102][50002];
    bool viz[102][50002];
    memset(mini, 0, sizeof(mini));
    memset(viz, 0, sizeof(viz));
    for(int i = S - 1; i >= 0; --i)
    {
        int nr = s[i];
        for(int a = 0; a < v[nr].size(); ++a)
        {
            int pp = v[nr][a];
            if(viz[p[pp+1]][pp+1])
            {
                if(!viz[nr][pp])
                    viz[nr][pp] = 1, mini[nr][pp] = mini[p[pp+1]][pp+1];
                else
                    mini[nr][pp] = min(mini[nr][pp], mini[p[pp+1]][pp+1]);
            }
        }
        if(s[i] == p[P - 1])
            viz[s[i]][P - 1] = 1, mini[s[i]][P - 1] = i;
        if(viz[p[0]][0])
            ans += (S - mini[p[0]][0]);
    }
    return ans;
};

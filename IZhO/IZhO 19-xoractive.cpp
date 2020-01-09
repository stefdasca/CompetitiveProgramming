/*
        IZhO 19-xoractive

    Let's find the value in position 1 at first. Then, for every i from 0 to 6, we will find the positions which have bit i equal to 1
and then we will ask for two queries: pairwise xors of the set found at this step, and pairwise xors of this set on which we add 1.
One can observe that the extra values obtained are val_1 ^ val_a0, val_1 ^ val_a1 and so on, where a is the set of values.

    Using this observation, we can find the positions of the values obtained in exactly 15 queries, which is enough for getting 100.

*/
#include "interactive.h"
#include<bits/stdc++.h>
using namespace std;

int n, sol[102];
vector<int> guess(int n)
{
    sol[1] = ask(1);
    map<int, int> ind;
    for(int i = 0; i <= 6; ++i)
    {
        vector<int> vec;
        for(int j = 2; j <= n; ++j)
            if(j & (1<<i))
                vec.push_back(j);
        if(vec.empty())
            continue;
        vector<int> vv = vec;
        vv.push_back(1);
        vv = get_pairwise_xor(vv);
        vec = get_pairwise_xor(vec);
        map<int, int> frq;
        for(int j = 0; j < vv.size(); ++j)
            if(vv[j] != 0)
                frq[vv[j]]++;
        for(int j = 0; j < vec.size(); ++j)
            if(vec[j] != 0)
                frq[vec[j]]--;
        for(int j = 0; j < vv.size(); ++j)
            if(frq[vv[j]] != 0)
                ind[(vv[j] ^ sol[1])] |= (1<<i);
    }
    for(auto poz : ind)
        sol[poz.second] = poz.first;
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
        ans.push_back(sol[i]);
    return ans;
}

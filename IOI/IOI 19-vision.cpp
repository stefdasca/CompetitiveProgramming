/*
            IOI 19-vision

    Let's find prefix xor on main and secondary diagonals. It's obvious that for at least one of the sets of
diagonals, we will have both black squares on different diagonals. So, we have to find some positions a and b,
such that b - a + 1 = k and prefix xor will be 1 on both positions, but a and b+1 won't have 1 on both positions.

    We can check the condition above using a for-loop.

    One has to be careful at implementing this task, because there are many cases which can mess up one's code if they're
implemented poorly.

*/
#include "vision.h"
#include<bits/stdc++.h>

using namespace std;
vector<int> fct(int K, vector<int>mn)
{
    vector<int>k1;
    for(int i = K; i < mn.size(); ++i)
        k1.push_back(add_xor({add_and({mn[i-K], mn[i]})}));
    return k1;
}
void construct_network(int H, int W, int K)
{
    vector<int>mn, sc;
    for(int i = H - 1; i >= 0; --i)
    {
        vector<int>pz;
        for(int a = i, b = 0; a < H && b < W; ++a, ++b)
            pz.push_back(a * W + b);
        if(i == H-1)
            mn.push_back(add_xor(pz));
        else
            mn.push_back(add_xor({mn.back(), add_xor(pz)}));
    }
    for(int i = 1; i < W; ++i)
    {
        vector<int>pz;
        for(int a = 0, b = i; a < H && b < W; ++a, ++b)
            pz.push_back(a * W + b);
        mn.push_back(add_xor({mn.back(), add_xor(pz)}));
    }
    for(int i = 0; i < W; ++i)
    {
        vector<int>pz;
        for(int a = 0, b = i; a < H && b >= 0; ++a, --b)
            pz.push_back(a * W + b);
        if(i == 0)
            sc.push_back(add_xor(pz));
        else
            sc.push_back(add_xor({sc.back(), add_xor(pz)}));
    }
    for(int i = 1; i < H; ++i)
    {
        vector<int>pz;
        for(int a = i, b = W - 1; a < H && b >= 0; ++a, --b)
            pz.push_back(a * W + b);
        sc.push_back(add_xor({sc.back(), add_xor(pz)}));
    }
    add_and({add_or({add_or(fct(K-1, mn)), add_or(fct(K-1, sc))}), add_not(add_or(fct(K, mn))), add_not(add_or(fct(K, sc)))});
}

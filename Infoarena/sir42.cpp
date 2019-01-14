/*
        Infoarena sir42(https://www.infoarena.ro/problema/sir42)

    Given an array with N elements where q[i] = the leftmost position such that v[i] + v[i+1] + .... + v[q[i]] = K or -1
if there is no such position, restore the original binary array v

    One can greedily put the ones necessary, firstly in positions q[i] which are not -1, then one can assign ones from right to left.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("sir42.in");
ofstream g("sir42.out");
int n, k, v[252];
bool q[252];
int main()
{
    f >> n >> k;
    int lst = -1;
    for(int i = 0; i < n; ++i)
    {
        f >> v[i];
        if(v[i] != -1)
            q[v[i]] = 1, lst = i;
    }
    for(int i = lst; i >= 0; --i)
    {
        int ct = 0;
        for(int j = i; j <= v[i]; ++j)
            ct += q[j];
        if(v[i] != v[i+1])
        {
            for(int j = i; j <= v[i]; ++j)
                if(ct < k && q[j] == 0)
                    q[j] = 1, ++ct;
        }
    }
    for(int i = 0; i < n; ++i)
        g << q[i];
    return 0;
}


/*
            APIO 16-gap

     For subtask 1, we can use the following approach. First call MinMax(0, 1e18, st, dr), then call MinMax(st, dr, st2, dr2) until
you build the whole array.

     For subtask 2, one can observe that the answer is at least (max_val - min_val) / (n - 1) and from that point we can use a while loop
to find the next element for each position. If we found some other element present in the range (x, x + ans), we will jump to x + ans + 1, since the elements
in the range can't bring us the maximum answer, because of their too small differences. 

*/
#include<bits/stdc++.h>
#include "gap.h"

using namespace std;

long long v[100002];

long long findGap(int T, int N)
{
    long long ans = 0;
    long long st = 0;
    long long dr = 1;
    for(int i = 1; i <= 18; ++i)
        dr = dr * 10LL;
    if(T == 1)
    {
        int a = 1;
        int b = N;
        while(a <= b)
        {
            long long st2;
            long long dr2;
            if(a == 1)
                MinMax(st, dr, &st2, &dr2);
            else
                MinMax(st+1, dr-1, &st2, &dr2);
            v[a] = st2;
            v[b] = dr2;
            ++a;
            --b;
            st = st2;
            dr = dr2;
        }
        for(int i = 1; i < N; ++i)
            ans = max(ans, v[i+1] - v[i]);
    }
    else
    {
        long long st2;
        long long dr2;
        MinMax(st, dr, &st2, &dr2);
        st = st2;
        dr = dr2;
        long long max_val = dr;
        ans = (dr - st) / (N - 1);
        while(st <= max_val)
        {
            dr = min(max_val, st + ans);
            if(max_val - st <= ans)
                break;
            long long sst = st + 1;
            while(1)
            {
                long long st2;
                long long dr2;
                MinMax(sst, dr, &st2, &dr2);
                if(dr2 == -1)
                {
                    sst = dr + 1;
                    dr = min(max_val, dr + ans);
                }
                else
                {
                    ans = max(ans, st2 - st);
                    st = dr2;
                    break;
                }
            }
        }
    }
    return ans;
}

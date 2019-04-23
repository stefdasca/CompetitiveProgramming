/*
        IOI 13-Cave

    The 70.000 queries limit suggests us that we should find the switch for each node in O(log n) questions.
    At each step, we will firstly find out which is the state for switch corresponding to door i, and then
we will use binary search on the possible range of the answer

*/
#include "cave.h"
#include<bits/stdc++.h>
void exploreCave(int N)
{
    int S[N+2], D[N+2];
    memset(S, 0, sizeof(S));
    memset(D, 0, sizeof(D));
    int P[N+2], pus[N+2];
    memset(P, 0, sizeof(P));
    memset(pus, 0, sizeof(pus));
    for(int i = 0; i < N; ++i)
    {
        int st = 0;
        int dr = N-1;
        for(int j = 0; j < N; ++j)
            if(pus[j])
                P[j] = S[j];
            else
                P[j] = 1;
        int ans = tryCombination(P);
        bool ce = 0;
        if(ans > i || ans == -1)
            ce = 1;
        while(st < dr)
        {
            int mid = (st + dr) / 2;
            for(int j = 0; j < N; ++j)
            {
                if(pus[j])
                    P[j] = S[j];
                else
                    if(st <= j && j <= mid)
                        P[j] = ce;
                    else
                        P[j] = ce ^ 1;
            }
            ans = tryCombination(P);
            if(ans > i || ans == -1)
                dr = mid;
            else
                st = mid + 1;
        }
        pus[st] = 1;
        D[st] = i;
        S[st] = ce;
    }
    answer(S, D);
}


#include<bits/stdc++.h>
#include "assistant.h"
using namespace std;

void Assist(unsigned char *A, int N, int K, int R)
{
    int frq[100002];
    memset(frq, 0, sizeof(frq));
    int poz = 0;
    for(int i = 0; i < R; ++i)
    {
        if(A[i] == 1)
            ++poz;
        else
            ++frq[poz];
    }
    set<int>good;
    set<int>bad;
    for(int i = 0; i < K; ++i)
        if(A[i] == 1)
            good.insert(i);
        else
            bad.insert(i);
    for(int i = 0; i < N; ++i)
    {
        int req = GetRequest();
        if(bad.find(req) == bad.end() && good.find(req) == good.end())
        {
            PutBack(*bad.begin());
            bad.erase(bad.begin());
            if(A[i + K] == 1)
                good.insert(req);
            else
                bad.insert(req);
        }
        else
            if(bad.find(req) == bad.end())
            {
                good.erase(req);
                if(A[i + K] == 1)
                    good.insert(req);
                else
                    bad.insert(req);
            }
            else
            {
                bad.erase(req);
                if(A[i + K] == 1)
                    good.insert(req);
                else
                    bad.insert(req);
            }
    }
}

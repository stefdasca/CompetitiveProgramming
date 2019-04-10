/*
            Info1Cup 18-Hidden

    First, find out min(count1, count0), which can be found by trying to find a subsequence with x 1's/0's
    Secondly, we will test at each step either 1111...1(used1 + 1)00..0(count0 - used0) or 0000...0(used0 + 1)11..1(count1 - used1)
whichever is shorter.
    After some casework, we will get to the solution

*/
#include<bits/stdc++.h>
#include "grader.h"
using namespace std;
vector<int>findSequence(int N)
{
    vector<int> ans (N, 0);
    vector<int> qu;
    vector<int> qu1;
    vector<int> qu2;
    int nr0 = 0, nr1 = 0;
    while(1)
    {
        qu.push_back(0);
        qu1.push_back(1);
        if(isSubsequence(qu))
            ++nr0;
        else
        {
            nr1 = N - nr0;
            break;
        }
        if(isSubsequence(qu1))
            ++nr1;
        else
        {
            nr0 = N - nr1;
            break;
        }
    }
    int cntsf0 = nr0, cntsf1 = nr1;
    for(int i = 0; i < N; ++i)
    {
        if(cntsf0 == 0)
        {
            for(int j = i; j < N; ++j)
                ans[j] = 1;
            break;
        }
        if(cntsf1 == 0)
        {
            for(int j = i; j < N; ++j)
                ans[j] = 0;
            break;
        }
        qu.clear();
        qu2.clear();
        for(int j = 0; j < nr0 - cntsf0 + 1; ++j)
            qu.push_back(0);
        for(int j = 0; j < cntsf1; ++j)
            qu.push_back(1);
        for(int j = 0; j < nr1 - cntsf1 + 1; ++j)
            qu2.push_back(1);
        for(int j = 0; j < cntsf0; ++j)
            qu2.push_back(0);
        if(qu.size() <= (N/2+1))
        {
            if(isSubsequence(qu))
                ans[i] = 0, --cntsf0;
            else
                ans[i] = 1, --cntsf1;
        }
        else
        {
            if(isSubsequence(qu2))
                ans[i] = 1, --cntsf1;
            else
                ans[i] = 0, --cntsf0;
        }

    }
    return ans;
}

/*
    IOI 00-median

    * We are going to solve this problem recursively. At first, we are going to randomly choose two elements a and b, and
split the numbers in input in three sets, based on the value of the median(in between (M), closer to the first (L), closer to the second (R))

    * if len(L) or len(R) are equals to floor(n/2), then a or b, respectively, are the median.

    * Otherwise, at each step, we are going to run the algorithm described previously on the bigger set, because we are sure that we are
going to find the median there.

    * Let's assume len(L) >= len(R).

     - if the length of L is > floor(n/2), we are going to run the algorithm on L,
thus L becomes M + R + b, M is going to become X(set where we keep elements such that the median of a,
new pivot and that element is equal to the new pivot) and R is going to become Y(set where we keep the elements which are not in X).
     - Otherwise, we are going to run the algorithm on M, in a similar fashion.


*/

#include<bits/stdc++.h>
#include "device.h"

using namespace std;

int Med3(int a, int b, int c);

int random(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

int solve(int n, vector<int> L, vector<int> M, vector<int> R, int a, int b)
{
    if (L.size() == n/2)
        return a;
    if (R.size() == n/2)
        return b;
    if (R.size() > L.size())
    {
        swap(L, R);
        swap(a, b);
    }
    vector<int> X, Y;
    if (L.size() > n/2)
    {
        int b2 = L[random(1, L.size()) - 1];
        for(int oo = 0; oo < L.size(); ++oo)
        {
            int e = L[oo];
            if (b2 == e)
                continue;
            int x = Med3(a, b2, e);
            if (x == b2)
                X.push_back(e);
            else
                Y.push_back(e);
        }
        L.clear();
        for(int oo = 0; oo < M.size(); ++oo)
        {
            int e = M[oo];
            L.push_back(e);
        }
        L.push_back(b);
        for(int oo = 0; oo < R.size(); ++oo)
        {
            int e = R[oo];
            L.push_back(e);
        }
        M = Y;
        R = X;
        b = b2;
    }
    else
    {
        R.push_back(b);
        b = M[random(1, M.size()) - 1];
        for(int oo = 0; oo < M.size(); ++oo)
        {
            int e = M[oo];
            if (e == b)
                continue;
            int x = Med3(a, b, e);
            if (x == b)
                X.push_back(e);
            else
                Y.push_back(e);
        }
        if (X.size() + R.size() > n/2)
        {
            M = X;
            for(int oo = 0; oo < Y.size(); ++oo)
            {
                int e = Y[oo];
                L.push_back(e);
            }
            L.push_back(a);
            a = b;
            b = R.back();
            R.pop_back();
        }
        else
        {
            M = Y;
            for(int oo = 0; oo < X.size(); ++oo)
            {
                int e = X[oo];
                R.push_back(e);
            }
        }
    }
    return solve(n, L, M, R, a, b);
}

int Median(int n)
{
    srand(time(0));
    int a, b;
    do
    {
        a = random(1, n);
        b = random(1, n);
    }
    while (a == b);
    vector<int> L, M, R;
    for (int i = 1; i <= n; ++i)
    {
        if (i == b || i == a)
            continue;
        int x = Med3(a, b, i);
        if (x == a)
            L.push_back(i);
        else
            if (x == b)
                R.push_back(i);
            else
                M.push_back(i);
    }
    return solve(n, L, M, R, a, b);
}

/*
        infoarena poarta2(https://infoarena.ro/problema/poarta2)
        
   "Given an infinite matrix with n columns, which will be completed with natural numbers from 1 to infinity line after line, left to right,
we have to get to the position labeled with k(a number with <= 1000 digits) by using the following moves.
    - go from position x to position x + 1(cost 1)
    - go from position x to position 2 * x(cost 2)
    The first move is free and we can go to a position from the first line.
    We have to find the minimal number of positions visited, respectively the minimal cost to get to k"
    
    We need to find the binary representation of k, and we will use prefix sums to find the values required.


*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("poarta2.in");
ofstream g("poarta2.out");
int c, n;
int bn[10002], cc;
char p[1002];
int nrmare[1002], st[10002];
int bn2[20], cc2;
int main()
{
    f >> c;
    f >> n;
    f >> (p + 1);
    nrmare[0] = strlen(p + 1);
    for(int j = 1; j <= nrmare[0]; ++j)
        nrmare[nrmare[0] - j + 1] = (p[j] - '0');
    while(nrmare[0])
    {
        ++cc;
        if(nrmare[1] % 2 == 1)
            bn[cc] = 1;
        int tr = 0;
        for(int j = nrmare[0]; j >= 1; --j)
        {
            nrmare[j] += 10 * tr;
            tr = nrmare[j] % 2;
            nrmare[j] /= 2;
        }
        while(nrmare[nrmare[0]] == 0 && nrmare[0])
            --nrmare[0];
    }
    reverse(bn + 1, bn + cc + 1);
    for(int j = cc; j >= 1; --j)
        st[j] = st[j+1] + bn[j];
    int ans1 = (1<<30);
    int ans2 = (1<<30);
    for(int j = 1; j <= n; ++j)
    {
        int a = j;
        cc2 = 0;
        while(a)
        {
            bn2[++cc2] = a % 2;
            a /= 2;
        }
        reverse(bn2 + 1, bn2 + cc2 + 1);
        int nr = 0;
        for(int j = 1; j <= cc2; ++j)
            nr = nr * 2 + bn[j];
        if(nr >= j)
        {
            ans1 = min(ans1, nr - j + 1 + cc - cc2 + st[cc2 + 1]);
            ans2 = min(ans2, nr - j + (cc - cc2) * 2 + st[cc2 + 1]);
        }
        else
        {
            ++cc2;
            nr = nr * 2 + bn[cc2];
            ans1 = min(ans1, nr - j + 1 + cc - cc2 + st[cc2 + 1]);
            ans2 = min(ans2, nr - j + (cc - cc2) * 2 + st[cc2 + 1]);
        }
        if(cc2 == cc)
        {
            bool eq = 1;
            for(int j = 1; j <= cc2; ++j)
                if(bn[j] != bn2[j])
                    eq = 0;
            if(eq)
                break;
        }
    }
    if(c == 1)
        g << ans1;
    else
        g << ans2;
    return 0;
}

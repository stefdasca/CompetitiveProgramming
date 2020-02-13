/*
        CEOI 05-Fence

    editorial: https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/CEOI/official/2005/solfence.pdf

*/
#include<bits/stdc++.h>
#include "lookup.h"
using namespace std;

struct punct
{
    bool st, cross;
};
punct p[100002];

int n, i, i1, side, ti, ti1, leftpart, leftmost, iend, d, m;

bool st(int i, int j)
{
    int i1, j1;
    i1 = (i == n ? 1 : i+1);
    j1 = (j == n ? 1 : j+1);
    bool ok = 0;
    if(p[i1].st && Drift(i, i1, j) <= 0 && Drift(i, i1, j1) <= 0)
        ok = 1;
    if(p[i].st && Drift(i, i1, j) >= 0 && Drift(i, i1, j1) >= 0)
        ok = 1;
    if(p[j1].st && Drift(j, j1, i) >= 0 && Drift(j, j1, i1) >= 0)
        ok = 1;
    if(p[j].st && Drift(j, j1, i) <= 0 && Drift(j, j1, i1) <= 0)
        ok = 1;
    return ok;
}

int main()
{
    n = GetN();
    for(i = 1; i <= n; ++i)
    {
        i1 = (i == n ? 1 : i+1);
        ti = Drift(n+1, n+2, i);
        ti1 = Drift(n+1, n+2, i1);
        if(ti * ti1 < 0)
        {
            p[i].cross = 1;
            ++m;
            p[i].st = (ti > 0);
            if(!leftmost)
                leftmost = i;
            else
            {
                if(st(i, leftmost))
                    leftmost = i;
            }
        }
        else
        {
            p[i].cross = 0;
            p[i].st = (ti > 0);
        }
    }
    if(m == 0)
    {
        if(p[1].st)
            Answer(1, 0);
        else
            Answer(0, 1);
        return 0;
    }
    side = 1;
    i = leftmost;
    d = (p[leftmost].st ? -1 : 1);
    leftpart = 0;
    do
    {
        iend = i;
        do
        {
            iend += d;
            if(iend < 1)
                iend = n;
            if(iend > n)
                iend = 1;
        }while(p[iend].cross == 0);
        if(side && st(i, iend))
            ++leftpart;
        i = iend;
        side = !side;
    }while(i != leftmost);
    Answer(leftpart, m/2 + 1 - leftpart);
    return 0;
}

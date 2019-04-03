#include<bits/stdc++.h>
using namespace std;
ifstream f("pav.in");
ofstream g("pav.out");
int A[513][513], nrp = 0;
int n, l, c;
void divide(int ls, int cs, int lf, int cf, int pl, int pc)
{
    if(ls == lf && cs == cf)
        return;
    int ml = (ls + lf) >> 1, mc = (cs + cf) >> 1, z;
    if(pl <= ml)
        if(pc <= mc)
            z = 2;
        else
            z = 1;
    else
        if(pc <= mc)
            z = 3;
        else
            z = 4;
    nrp++;
    if(z == 1)
    {
        A[ml][mc] = A[ml + 1][mc + 1] = A[ml + 1][mc] = nrp;
        divide(ls, mc + 1, ml, cf, pl, pc);
        divide(ls, cs, ml, mc, ml, mc);
        divide(ml + 1, cs, lf, mc, ml + 1, mc);
        divide(ml + 1, mc + 1, lf, cf, ml + 1, mc + 1);
    }
    if(z == 2)
    {
        A[ml][mc + 1] = A[ml + 1][mc + 1] = A[ml + 1][mc] = nrp;
        divide(ls, mc + 1, ml, cf, ml, mc + 1);
        divide(ls, cs, ml, mc, pl, pc);
        divide(ml + 1, cs, lf, mc, ml + 1, mc);
        divide(ml + 1, mc + 1, lf, cf, ml + 1, mc + 1);
    }
    if(z == 3)
    {
        A[ml][mc] = A[ml][mc + 1] = A[ml + 1][mc + 1] = nrp;
        divide(ls, mc + 1, ml, cf, ml, mc + 1);
        divide(ls, cs, ml, mc, ml, mc);
        divide(ml + 1, cs, lf, mc, pl, pc);
        divide(ml + 1, mc + 1, lf, cf, ml + 1, mc + 1);
    }
    if(z == 4)
    {
        A[ml][mc] = A[ml][mc + 1] = A[ml + 1][mc] = nrp;
        divide(ls, mc + 1, ml, cf, ml, mc + 1);
        divide(ls, cs, ml, mc, ml, mc);
        divide(ml + 1, cs, lf, mc, ml + 1, mc);
        divide(ml + 1, mc + 1, lf, cf, pl, pc);
    }
}
int main()
{
    f >> n >> l >> c;
    int dim = 1 << n;
    divide(1, 1, dim, dim, l, c);
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
            g << A[i][j] << ' ';
        g << '\n';
    }
    return 0;
}

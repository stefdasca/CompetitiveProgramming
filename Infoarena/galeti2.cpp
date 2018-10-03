#include<bits/stdc++.h>
using namespace std;
ifstream in("galeti2.in");
ofstream out("galeti2.out");
long long n, q;
void rec(int st, int dr, long long e)
{
    if(e == 0)
        return;
    int zz = dr - st + 1;
    if(2 * zz - 3 <= e)
    {
        rec(st + 1, dr, e - zz + 1);
        out << st + 1 << " " <<st << '\n';
    }
    else
    {
        rec(st, dr - 1, e - 1);
        out << dr << " " << st << '\n';
    }
}
int main()
{
    in >> n >> q;
    rec(1, n, q);
    return 0;
}

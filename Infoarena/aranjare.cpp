/*
                    Infoarena-aranjare(infoarena.ro/problema/aranjare)

    "Given a string of size 2 * n + 2, where n of the positions have "B"(a boy sits on that chair),
n of the positons have "F"(a girl sits on that chair) and the remaining 2 positions have "S"(they are adjacent),
nobody sits there, use moves of type (we move kids on positions k and k + 1 to the free places) so that the girls are
on the left side, the boys are on the right side and the 2 free places separate the rows of boys and girls."

    We will use a greedy approach, where at each step we will try to maximize the number of the girls in left part
of the row of chairs. By using a proper data structure to find the positions of boys and girls and treating some corner
cases, you should get a solution which manages to move everyone in his suitable places in around O(n) moves. Depending on
implementation, one can solve the problem in O(n^2) or in O(n log n), since the small constraint of n makes both of the
approaches acceptable.

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("aranjare.in");
ofstream g("aranjare.out");
int n, pL;
char c[10002];
set<int>s[2];
void movv(int pz)
{
    g << pz << '\n';
    c[pL] = c[pz];
    c[pL + 1] = c[pz + 1];
    c[pz] = 'S';
    c[pz + 1] = 'S';
    int v1 = c[pL] - '0';
    s[v1].erase(pz);
    s[v1].insert(pL);
    v1 = c[pL + 1] - '0';
    s[v1].erase(pz + 1);
    s[v1].insert(pL + 1);
    pL = pz;
}
int main()
{
    f >> n;
    f >> (c + 1);
    for(int i = 1; i <= 2 * n + 2; ++i)
    {
        if(c[i] == 'B')
            c[i] = '1';
        if(c[i] == 'F')
            c[i] = '0';
        if(c[i] == 'S' && c[i + 1] == 'S')
            pL = i;
        if(c[i] == '0')
            s[0].insert(i);
        if(c[i] == '1')
            s[1].insert(i);
    }
    int pF = 1;
    bool again = 0;
    while(pF <= n)
    {
        while(c[pF] == '0')
            s[0].erase(pF), ++pF;
        if(pF == n + 1)
            break;
        if(*s[0].begin() == 2 * n + 2)
        {
            if(pL == 2 * n)
                movv(2 * n - 2);
            movv(2 * n + 1);
            if(again)
                movv(*s[0].begin());
            else
                again = 1;
        }
        else
            if(pL == pF)
                movv(*s[0].begin());
            else
                if(pL == pF + 1)
                {
                    set<int> ::iterator it = s[1].begin();
                    ++it;
                    movv(*it);
                }
                else
                    movv(pF);
    }
    if(pL == n + 2)
    {
        g << n + 4 << '\n';
        g << n + 1 << '\n';
    }
    else
        if(pL > n + 2)
            g << n + 1 << '\n';
    return 0;
}

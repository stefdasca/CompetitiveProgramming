/*
        POI 05-Parties

    * Firstly, it can be proved by induction that we can split the graph into two subsets such that the degree of each vertex in its
subset is even.

    * A recursive O(n^3) solution for this problem works as follows:
        1. We will check if the current graph has any vertex with odd degree. If it's not the case, we will stop the algorithm here.
        2. Otherwise, we will add or drop some edges among those involving the neighbors of the vertex with odd degree, and call the function
for the new graph.
        3. After we solved the problem for the new graph, all we have to do is to check in which of the subsets of the graph we're going to
add the removed vertex. Because this vertex has odd degree, we're sure that we will find such a set(only sum of numbers with different parity
is odd, otherwise it's even)

    * For an detailed proof of the solution presented by me, you can check https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2005/editrial/dwa.pdf
(it's in Polish, so you have to translate it in English using any online translator service)

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;

int n;
bool e[MAXN][MAXN], solution[MAXN], inGraph[MAXN];


void solve()
{
    int k;
    int neighbors = 0;
    int who[MAXN];
    for (k = 1; k <= n; ++k)
        if (inGraph[k])
        {
            neighbors = 0;
            for (int j = 1; j <= n; ++j)
                if (inGraph[j] && e[k][j])
                    who[++neighbors] = j;
            if (neighbors % 2 == 1)
                break;
        }
    if (k == n + 1)
        return;
    inGraph[k] = 0;
    for (int i = 1; i <= neighbors; ++i)
        for (int j = 1; j <= neighbors; ++j)
            if (i != j)
                e[who[i]][who[j]] = !e[who[i]][who[j]];
    solve();
    int party = 0;
    for (int i = 1; i <= neighbors; ++i)
        if (solution[who[i]])
            ++party;
    solution[k] = (party % 2 == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int d;
        cin >> d;
        for (int j = 1; j <= d; ++j)
        {
            int vecin;
            cin >> vecin;
            e[i][vecin] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        inGraph[i] = 1;
    solve();
    int countt = 0;
    for (int i = 1; i <= n; ++i)
        if (solution[i])
            ++countt;
    cout << countt << '\n';
    for (int i = 1; i <= n; ++i)
        if (solution[i])
        {
            cout << i;
            --countt;
            if(countt)
                cout << " ";
        }
    cout << '\n';
    return 0;
}

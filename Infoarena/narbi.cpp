#include<bits/stdc++.h>
using namespace std;
ifstream fin("narbi.in");
ofstream fout("narbi.out");
const int NR = 12345;
int N, K, X, p, t;
int rez;
int v[NR];
int main()
{
    int i, j;
    for ( i = 0, j = 1; i < 31; i++, j *= 2 )
        v[j % NR] = i;
    fin >> N >> K >> X;
    p = 0; t = X; j = 1;
    for ( i = 1; i <= N; i++ )
    {
        for ( ; j <= t; j++ )
        {
            p = p + 1 - ( v[(( j & ( j - 1 ) ) xor j) % NR] );
            rez = rez + p;
        }
        if ( N - i + 1 <= K )
            fout << rez << '\n';
        t = t + ( rez % 16 ) + 1;
    }
    return 0;
}

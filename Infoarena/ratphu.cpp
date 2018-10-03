#include <fstream>
using namespace std;
ifstream fin ("ratphu.in");
ofstream fout ("ratphu.out");
const int nmax = 18;
const int pmax = 20;
int cif[nmax + 1];
long long d[(1 << nmax)][ pmax ];
int n, p;
long long x;
int main() {
    fin >> x >> p;
    n = 0;
    while (x > 0) {
        cif[n ++] = x % 10;
        x /= 10;
    }
    d[ 0 ][ 0 ] = 1;
    for (int i = 0; i < (1 << n) - 1; ++ i)
        for (int j = 0; j < n; ++ j) {
            if (i & (1 << j))
                continue;
            int st = i + (1 << j);
            for (int r = 0; r < p; ++ r)
                d[ st ][(r * 10 + cif[ j ]) % p] += d[ i ][ r ];
        }
    fout << d[(1 << n) - 1][ 0 ] << "\n";
    return 0;
}

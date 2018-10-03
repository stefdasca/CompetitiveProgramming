#include <fstream>
#define MOD 9901
using namespace std;
ifstream fin("cod2.in");
ofstream fout("cod2.out");
int n, f[130];
char c, all, doi;
int aranj(int n, int k) {
    int r = 1, i;
    for (i=n-k+1; i<=n; i++)
        r = r * i % MOD;
    return r;
}
int comb2(int n) {
    return n*(n-1)/2%MOD;
}
int main () {
    fin>>n;
    while (fin>>c){
        f[c]++;
        if (f[c] == 1)
            all++;
        if (f[c] == 2)
            doi++;
    }
    fout<<(aranj(all, n) + doi * comb2(n) % MOD * aranj(all-1, n-2) % MOD) % MOD;
    return 0;
}

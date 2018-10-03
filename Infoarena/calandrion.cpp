#include<bits/stdc++.h>
using namespace std;
ifstream f("calandrinon.in");
ofstream g("calandrinon.out");
int N,ct[27];
string S;
int main() {
    f >> N;
    f >> S;
    for (int i = 0; i < N; ++i)
        ++ct[S[i] - 'a'];
    int t = 0;
    for (int i = 0; i < 26; ++i)
        t += (ct[i] > 0);
    int start = 0;
    for (int i = 0; i < t; ++i) {
        vector<int> aux(26, 0);
        char best = 'z' + 1;
        int where = -1;
        for (int j = start; j < N; ++j) {
            ++aux[S[j] - 'a'];
            if (ct[S[j] - 'a'] > 0 && S[j] < best) {
                best = S[j];
                where = j;
            }
            if (aux[S[j] - 'a'] == ct[S[j] - 'a'])
                break;
        }
        g<< best;
        ct[best - 'a'] = -1;
        for (int j = start; j <= where; ++j)
            --ct[S[j] - 'a'];
        start = where + 1;
    }
}

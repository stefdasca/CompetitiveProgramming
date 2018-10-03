#include <bits/stdc++.h>
using namespace std;
ifstream fin("numere7.in");
ofstream fout("numere7.out");
long long N,fact[25];
string X;
int freq[11];
int main()
{
    fin >> N >> X;
    fact[0] = 1;
    for(int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;
    for(int i = 0; i < X.size(); i++)
        freq[X[i] - '0']++;
    for(int i = 0; i < X.size(); i++)
        for(int j = 1; j <= 9; j++)
            if(freq[j] != 0)
            {
                long long val = fact[X.size() - i - 1];
                for(int k = 1; k <= 9; k++)
                    val /= fact[freq[k] - (k == j)];
                if(N > val)
                    N -= val;
                else
                {
                    fout << j;
                    freq[j]--;
                    break;
                }
            }
    return 0;
}

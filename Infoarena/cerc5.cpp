#include <fstream>
using namespace std;
ifstream fin ("cerc5.in");
ofstream fout ("cerc5.out");
int T, N, K, P[50010], V[100010], last[100010];
bool fr[620000];
void Ciur()
{
    int k = 1, i = 3;
    P[k] = 2;
    while (k <= K)
    {
        if (!fr[i]) P[++k] = i;
        for (int j = i + i; j <= 620000; j += i) {
            fr[j] = 1;
        }
        i += 2;
    }
}
void Afla_Copil(int &poz, int prim)
{
    if (poz == prim % N + 1) {
        poz = 1;
    }
    else
    {
        int opa = prim / N % (N - 1);
        if (prim % N >= poz) poz++;
        if (opa) poz += opa;
        if (poz > N) poz = poz - N + 1;
    }
}

int main()
{
    fin >> T >> N >> K;
    for (int i = 1; i <= N; i++) fin >> V[i];
    if (T == 1)
    {
        int L = 1;
        last[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            int st = 1, dr = L, mij;
            while (st <= dr)
            {
                mij = (st + dr) / 2;
                if (V[i] > V[last[mij]]) st = mij + 1;
                else dr = mij - 1;
            }

            if (st == L + 1)
                L += 1;
            last[st] = i;
        }

        fout << L << '\n';
    }
    else
    {
        Ciur();
        int poz = 1, opa, poz_st, poz_dr;
        for (int i = 1; i <= K; i++)
        {
            if (poz == 1) {
                poz += P[i] % N;
            }
            else
            {
                opa = P[i] / N % (N - 1);
                if (opa) poz -= opa;
                if (poz < 2) poz = poz + N - 1;
                if (P[i] % N + 1 >= poz) poz--;
            }
        }
        poz_st = (poz - 1 == 0 ? N : poz - 1);
        poz_dr = (poz + 1 == N + 1 ? 1 : poz + 1);

        for (int i = K; i >= 1; i--)
        {
            Afla_Copil(poz_st, P[i]);
            Afla_Copil(poz_dr, P[i]);
        }

        fout << poz_dr << ' ' << poz_st << '\n';
    }

    fout.close();
    return 0;
}

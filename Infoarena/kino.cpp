#include<bits/stdc++.h>
#define modulo 666013
using namespace std;
ifstream fin("kino.in");
ofstream fout("kino.out");
string sir;
const int NMAX = 20000;
int i, n, k, j,contor,st,dr,x,y,maxim[NMAX + 5],a[NMAX + 5][53],v[NMAX + 5],poz[NMAX + 5];
long long sol;
struct frecventa
{
    int viz;
    short index;
};
frecventa w[NMAX + 5];
bool cmp(frecventa a, frecventa b)
{
    return a.viz < b.viz;
}
void clear(int maxi)
{
    for(int i = 1; i <= maxi; i++)
    {
        w[i].viz = 0;
        w[i].index = i;
    }
}
int main()
{
    fin >> n >> k;
    for(i = 1; i <= k; i++)
    {
        fin >> x;
        maxim[i] = min(x, NMAX);
    }
    getline(fin,sir);
    for(i = 1; i <= n; i++)
    {
        getline(fin,sir);
        int lung = sir.length();
        int index = 0;
        for(j = 1; j <= k; j++)
        {
            int aux = 0;
            while(sir[index] <= '9' && sir[index] >= '0' && index < lung)
            {
                aux = aux * 10 + (sir[index] - '0');
                index++;
            }
            index++;
            a[i][j] = aux;

        }
    }
    sol = 0;
    for(i = 1; i <= k; i++)
    {
        int liber = 0,dr = 0;
        clear(maxim[i]);
        for(j = 1; j <= n; j++)
        {
            if(a[j][i] == 0)
                liber++;
            else
                if(a[j][i] <= NMAX)
                    w[a[j][i]].viz++;
        }
        sort(w + 1, w + maxim[i]+1,cmp);
        j = 1;
        while(liber > 0)
        {
            for(int p = 1; p <= maxim[i]; p++)
            {
                if(w[p].viz > j)
                    break;
                while(w[p].viz < j && liber > 0 && p <= maxim[i])
                {
                    liber--;
                    w[p].viz++;
                    poz[++dr] = w[p].index;
                }
            }
            j++;
        }
        int p = 1;
        int aux = 0;
        for(j = 1; j <= n; j++)
        {
            if(a[j][i] == 0)
                a[j][i] = poz[p++];
            v[++aux] = a[j][i];
        }
        sort(v+1,v + n + 1);
        for(j = 1; j <= n; j++)
        {
            int nr = 1;
            while(v[j] == v[j + 1] && j <= n)
                j++,nr++;
            sol = sol + ((n - nr) * nr );
        }
    }
    fout << sol/2<<"\n";
    return 0;
}

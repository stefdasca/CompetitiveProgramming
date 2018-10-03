#include <fstream>
#include <bitset>
#include <queue>
#include <cstring>
#define US short
using namespace std;
ifstream f("zmeu2.in");
ofstream g("zmeu2.out");
US x,y, nr;
const US f_mare = 3e+4;
US i, j;
US n,p,k,c[205],d[205];
bitset<202> mat[202];
US sol[205][505];
US solmin = f_mare;
bool deja[202];
queue <US> coada;
void bf()
{
    US x, y, i, j;
    bool ok;
    coada.push(1);
    while (!coada.empty())
    {
        x = coada.front();
        coada.pop();
        deja[x] = 0;
        for (i = 2; i <= p-(x==1); i++)
            if (mat[x][i] == 0)
            {
                ok = 0;
                for (j = n; j > c[i]; j--)
                    if (sol[x][j] > 0)
                        {
                            if (sol[x][j] + d[i] < sol[i][j-c[i]] || sol[i][j-c[i]] == 0)
                                sol[i][j-c[i]] = sol[x][j] + d[i], ok = 1;
                            if (i == p)
                                solmin = min(solmin, sol[i][j-c[i]]);
                        }
                if (ok && i < p && !deja[i])
                {
                    deja[i] = 1;
                    coada.push(i);
                }
            }
    }
}
int main() {

    f >> n >> p >> k;
    for (i = 1; i <= p; i++)
        f >> d[i] >> c[i];
    while (k--)
    {
        f >> x >> y;
        mat[x][y] = 1;
    }
    sol[1][n-c[1]]=d[1];
    bf();
    if (solmin == f_mare)
        g << "-1";
    else
        g << solmin;
    return 0;
}

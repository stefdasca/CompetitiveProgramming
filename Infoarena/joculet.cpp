#include <fstream>
using namespace std;
ifstream f("joculet.in");
ofstream g("joculet.out");
long long n,i,j,d[2][2001],v[2001];
int main()
{
    f >> n;
    for (i=1; i<=n; i++)
        f >> v[i];
    d[0][n] = v[n];
    for (i=n-1; i>=1; i--)
    {
        for (j=i; j<=n; j++)
            if (i == j)
                d[1][i] = v[i];
            else
            {
                d[1][j] = max(v[i]-d[0][j], v[j]-d[1][j-1]);
                d[1][j] = max(d[1][j], v[i]+v[j]-d[0][j-1]);
            }
        for (j=i; j<=n; j++)
            d[0][j] = d[1][j];
    }
    g << d[1][n];
    return 0;
}

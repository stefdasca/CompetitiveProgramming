#include<fstream>
#include<bitset>
using namespace std;
ifstream f("bile6.in");
ofstream g("bile6.out");
int difa, difb, n, i, j, k, l, gol, cnt;
int main()
{
    f >> n;
    for(i = 1, j = n; i < j; ++i, --j)
        if(i+1 >= j-1)
        {
            if(i+1 == j-1)
                gol = i+1;
            break;
        }
    for(k = n+1, l = 2*n+1; k < l; ++k, --l)
        if(k+1 >= l-1)
        {
            if(k+1 == l-1)
                gol = k+1;
            break;
        }
    while(cnt < n)
    {
        difa = 150654345, difb = 195605456;
        if(k >= n+1)
            difb = l - k;
        if(i >= 1)
            difa = j - i;
        if(difa < difb)
        {
            g << i << " " << j << '\n';
            --i;
            ++j;
        }
        else
        {
            g << k << " " << l << '\n';
            --k;
            ++l;
        }
        ++cnt;
    }
    g << gol << '\n';
    return 0;
}

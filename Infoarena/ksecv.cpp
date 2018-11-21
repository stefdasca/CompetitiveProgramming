#include<fstream>
#include<cstring>
using namespace std;
ifstream f("ksecv.in");
ofstream g("ksecv.out");
int n, k, dp[3][100002], v[100002];
int val[100002], pmax[100002], pmin[100002], sz;
int main()
{
    f >> n >> k;
    for(int i = 1; i <= n; ++i)
        f >> v[i];
    int mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] > mx)
            mx = v[i];
        dp[1][i] = mx;
    }
    int z = (n+1) * sizeof(int);
    for(int i = 2; i <= k; ++i)
    {
        sz = 0;
        for(int j = i; j <= n; ++j)
        {
            int zmin = j-1;
            while(sz && v[j] > v[val[sz]])
            {
                if(dp[1][pmin[sz]] < dp[1][zmin])
                    zmin = pmin[sz];
                --sz;
            }
            ++sz;
            val[sz] = j;
            pmin[sz] = zmin;
            int summ = dp[1][zmin] + v[j];
            if(sz == 1 || pmax[sz - 1] > summ)
                pmax[sz] = summ;
            else
                pmax[sz] = pmax[sz - 1];
            dp[2][j] = pmax[sz];
        }
        memcpy(dp[1], dp[2], z);
    }
    g << dp[1][n] << '\n';
    return 0;
}

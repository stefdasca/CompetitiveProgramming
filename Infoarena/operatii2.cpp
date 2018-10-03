#include<fstream>
#include<cmath>
using namespace std;
ifstream f("operatii2.in");
ofstream g("operatii2.out");
int n,m;
int a[201][201];
int dp[10002];
int solmax=0;
void getMinSquares(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = i;
        for (int x = 1; x <= i; x++) {
            int temp = x*x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1+dp[i-temp]);
        }
    }
}
int main()
{
    f>>n>>m;
    getMinSquares(10002);
    solmax=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            f>>a[i][j];
            solmax=max(solmax,dp[a[i][j]]);
        }
    g<<solmax<<'\n';
    for(int i=1;i<=solmax;++i)
        for(int i=1;i<=n;g<<'\n',++i)
            for(int j=1;j<=m;++j)
                if(a[i][j]==0)
                    g<<0<<" ";
                else
                    for(int z=0;z*z<=a[i][j];++z)
                        if(dp[a[i][j]-z*z]==dp[a[i][j]]-1){
                            g<<z<<" ";
                            a[i][j]-=z*z;
                            break;
                        }
    return 0;
}

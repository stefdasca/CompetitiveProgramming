/// #bettercoderthanshebeautiful
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("peisaj.in");
ofstream g("peisaj.out");
int n,k,z=1;
long long dp[4][28][27][2][2];
int main()
{
    f>>n>>k;
    dp[1][1][0][(k==1)][1]=1;
    for(int i=1;i<n;++i)
    {
        z=3-z;
        memset(dp[z],0,sizeof(dp[z]));
        for(int j=0;j<=n/2;++j)
            for(int p=0;p<=n/2;++p)
            {
                dp[z][j+1][p][(k==j+1)][1]+=dp[3-z][j][p][0][1]+dp[3-z][j][p][0][0];
                dp[z][j+1][p][1][1]+=dp[3-z][j][p][1][1]+dp[3-z][j][p][1][0];
                if(j>0)
                {
                    dp[z][j-1][p+1][0][0]+=dp[3-z][j][p][0][1];
                    dp[z][j-1][p][0][0]+=dp[3-z][j][p][0][0];
                    dp[z][j-1][p+1][1][0]+=dp[3-z][j][p][1][1];
                    dp[z][j-1][p][1][0]+=dp[3-z][j][p][1][0];
                }
            }
    }
    long long sol=0;
    long long sol2=0;
    for(int j=0;j<=n/2;++j)
    {
        sol2+=dp[z][0][j][1][0];
        sol+=dp[z][0][j][0][0]+dp[z][0][j][1][0];
    }
    long long sol3=dp[z][0][k][0][0]+dp[z][0][k][1][0];
    g<<sol<<" "<<sol2<<" "<<sol3<<'\n';
    return 0;
}

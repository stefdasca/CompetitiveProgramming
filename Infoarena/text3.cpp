#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
ifstream fin("text3.in");
ofstream fout("text3.out");
const int N=20001;
int dp[N], p[N], a[26];
char cuvs[N][21];
void afis(int i)
{
    if(p[i]!=-1)
        afis(p[i]);
    fout<<cuvs[i]<<'\n';
}
int main()
{
    int n=0;
    char cuv[21];
    while(fin>>cuv)
    {
        strcpy(cuvs[n], cuv);
        n++;
    }
    fill_n(a, 26, -1);
    int lmax=0, imax=-1;
    for(int i=0;i<n;++i)
    {
        char cc[21];
        strcpy(cc, cuvs[i]);
        dp[i]=dp[a[cc[0]-'a']]+1;
        p[i]=a[cc[0]-'a'];
        if(dp[i]>dp[a[cc[strlen(cc)-1]-'a']])
            a[cc[strlen(cc)-1]-'a']=i;
        if(dp[i]>lmax)
            lmax=dp[i], imax=i;
    }
    fout<<n<<'\n'<<n-lmax<<'\n';
    afis(imax);
    return 0;
}

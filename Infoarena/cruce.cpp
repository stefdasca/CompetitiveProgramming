#include<bits/stdc++.h>
using namespace std;
ifstream f("cruce.in");
ofstream g("cruce.out");
int n,m;
char c[102][102];
long long sol;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>c[i][j];
    for(int i=2;i<n;++i)
        for(int j=2;j<m;++j)
        {
            int lp=0;
            int cp=0;
            while(j>lp-1 && j+lp+1<=m && c[i][j-lp-1]==c[i][j+lp+1])
                ++lp;
            while(i>cp-1 && i+cp+1<=n && c[i-cp-1][j]==c[i+cp+1][j])
                ++cp;
            sol+=lp*cp;
        }
    g<<sol;
    return 0;
}

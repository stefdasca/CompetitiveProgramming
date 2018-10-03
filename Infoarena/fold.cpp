#include<bits/stdc++.h>
using namespace std;
ifstream f("fold.in");
ofstream g("fold.out");
int n,m;
bool v[2001][2001];
char c1[5002];
long long sol;
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i){
        f.get();
        f.get(c1,5000);
        for(int j=1;j<=m;++j)
            v[i][j]=c1[2*(j-1)]-'0';
    }
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
        {
            int nr=0;
            for(int k=1;k<=m;++k)
                nr+=(v[i][k]&v[j][k]);
            sol=sol+(nr-1)*nr/2;
        }
    g<<sol;
    return 0;
}

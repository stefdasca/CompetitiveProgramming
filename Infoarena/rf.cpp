#include<bits/stdc++.h>
using namespace std;
ifstream f("rf.in");
ofstream g("rf.out");
int n,a[302][302],k,i,j,st[302][302];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            f>>a[i][j];
            if(i!=j)
                st[i][j]=1;
        }
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (a[i][k] && a[k][j] && (a[i][j] > a[i][k] + a[k][j] || !a[i][j]) && i != j)
                        a[i][j] = a[i][k] + a[k][j],st[i][j]=st[i][k]+st[k][j];
                else
                    if (a[i][k] && a[k][j] && a[i][j] == a[i][k] + a[k][j] && i != j)
                        st[i][j]=max(st[i][j],st[i][k]+st[k][j]);
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=n;++j)
            g<<a[i][j]<<" ";
    for(int i=1;i<=n;g<<'\n',++i)
        for(int j=1;j<=n;++j)
            g<<st[i][j]<<" ";
    return 0;
}

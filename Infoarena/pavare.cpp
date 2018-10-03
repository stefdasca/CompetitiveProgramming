#include<bits/stdc++.h>
using namespace std;
ifstream f("pavare.in");
ofstream g("pavare.out");
int n,m,k,i,x,y,j,rez,dp[155][32770],a[155][32770],aux,b;
int val,init,ind;
void bt(int k, int cr)
{
    int i;
    dp[ind][cr]=dp[ind-1][((1<<m)-1)^cr]+val;
    for(i=k; i<m-1; i++)
        if(a[ind][i]==0 && a[ind][i+1]==0 && a[ind-1][i]==0 && a[ind-1][i+1]==0)
        {
            val++;
            bt(i+2,(cr|(1<<i))|(1<<(i+1)));
            val--;
        }
}
int main()
{
    f>>n>>m>>k;
    for(i=1; i<=k; i++)
    {
        f>>x>>y;
        a[x][y-1]=1;
    }
    for(i=2; i<=n; i++)
    {
        ind=i;
        bt(0,0);
        for(j=0; j<(1<<m); j++)
        {
            aux=j;
            while(aux)
            {
                b=(aux&(aux^(aux-1)));
                dp[i][j]=max(dp[i][j],dp[i][j-b]);
                aux=aux-b;
            }
        }
    }
    for(i=0; i<(1<<m); i++)
        rez=max(rez,dp[n][i]);
    g<<rez<<'\n';
    return 0;
}

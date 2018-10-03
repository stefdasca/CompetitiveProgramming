#include<bits/stdc++.h>
using namespace std;
ifstream f("tricouri.in");
ofstream g("tricouri.out");
int n,v[300002],m,nr[105],ax[105];
int sum[21][6][21],Ly,R,arr[21][21];
inline void prec()
{
    for(int Qt=2;Qt<=20;++Qt){
        for(int j=0;j<Qt;++j)
            for(int k=0;k<Qt;++k)
                arr[j][k]=(j+k)%Qt;
        int cnt=0;
        int l=Qt;
        memset(nr,0,sizeof(nr));
        for(int i=1;i<=n;++i)
            if(nr[v[i]%Qt] < 5){
                nr[v[i]%Qt]++;
                ax[++cnt] = v[i];
                if(nr[v[i]%Qt]==5){
                    l--;
                    if(l == 0){
                        break;
                    }
                }
            }
        for(int j=1;j<=cnt;++j){
            int Rose=ax[j]%Qt;
            for(int p=4;p>=1;--p)
                for(int k=0;k<Qt;++k)
                    if(sum[Qt][p][k]>0)
                        sum[Qt][p+1][arr[Rose][k]]=max(sum[Qt][p+1][arr[Rose][k]],sum[Qt][p][k]+ax[j]);
            sum[Qt][1][Rose]=max(sum[Qt][1][Rose],ax[j]);
        }
    }
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1,greater<int>());
    memset(sum,-1,sizeof(sum));
    prec();
    for(int i=1;i<=m;++i)
    {
        f>>Ly>>R;
        g<<sum[R][Ly][0]<<'\n';  ///g<<"Rose"<<'\n';
    }
    return 0;
}

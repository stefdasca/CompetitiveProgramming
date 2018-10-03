#include<bits/stdc++.h>
using namespace std;
ifstream f("palin3.in");
ofstream g("palin3.out");
string sir;
int t,d[110][110],n;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i){

        f>>sir;
        n=sir.size();
        memset(d,0,sizeof(d));
        for(int i=1;i<n;++i)
            for(int j=0;j<i;++j)
                d[i][j]=1;
        for(int l=3;l<=n;l+=3)
            for(int i=0;i<=n-l;++i){
                int j=i+l-1;
                if(sir[i]==sir[j])
                    for(int k=i+1;k<j && !d[i][j];++k)
                        if(d[i+1][k-1] && d[k+1][j-1])
                            d[i][j]=1;
                for(int k=i;k<j && !d[i][j];++k)
                    if(d[i][k] && d[k+1][j])
                        d[i][j]=1;
            }
        if(d[0][n-1])
            g<<"DA"<<'\n';
        else
            g<<"NU"<<'\n';
    }
    return 0;
}

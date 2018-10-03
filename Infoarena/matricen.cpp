/// OrangeWarrior #1
#include<bits/stdc++.h>
using namespace std;
ifstream f("matricen.in");
ofstream g("matricen.out");
int n,q,mat[301][301],pd[301][301],v[302];
int main()
{
    f>>n>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            f>>mat[i][j];
            pd[i][j]=pd[i][j-1]+mat[i][j];
        }
    for(int i=1;i<=q;++i)
    {
        int la,lb,ca,cb;
        f>>la>>ca>>lb>>cb;
        int s=0;
        for(int j=la;j<=lb;++j)
            v[j-la+1]=pd[j][cb]-pd[j][ca-1],s+=v[j-la+1];
        sort(v+1,v+lb-la+2);
        if(s%(cb-ca+1)!=0)
            g<<-1<<'\n';
        else
        {
            int s=0;
            int nrmov=0;
            for(int st=1,sf=lb-la+1;st<=sf;)
                if(s<(cb-ca+1-v[sf]))
                    s+=v[st],++st;
                else
                    nrmov+=(cb-ca+1-v[sf]),s-=(cb-ca+1-v[sf]),--sf;
            g<<nrmov<<'\n';
        }
    }
    return 0;
}

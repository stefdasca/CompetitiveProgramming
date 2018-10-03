#include<fstream>
using namespace std;
ifstream f("flori.in");
ofstream g("flori.out");
int n,k,i,j,x;
int t[1002],P[1002];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i)
      P[i]=i;
    for(i=1;i<=n;++i)
        for(j=1;j<=k;++j)
        {
            f>>x;
            if(t[x]) //daca tipul florii a fost cules inainte
            {
                if(P[i]>t[x])
                   P[i]=t[x];
                else
                   P[t[x]]=P[i];
            }
            else
                t[x]=i;
        }
    for(i=1;i<=n;++i)
        if(P[i]==i)
        {
            for(j=i;j<=n;++j)
                if(P[j]==i)
                    g<<j<<" ";
            g<<'\n';
        }
    return 0;
}

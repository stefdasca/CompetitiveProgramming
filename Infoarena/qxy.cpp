#include<fstream>
using namespace std;
int D[1010][1010],n,q,pos=1,v[10010];
ifstream f("qxy.in");
ofstream g("qxy.out");
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>v[i];
        D[pos][v[i]]++;
        if(i%10==0)
            ++pos;
    }
    for(int i=1;i<=pos;i++)
        for(int j=1;j<=1000;j++)
            D[i][j]+=D[i-1][j];
    for(int i=1;i<=pos;i++)
        for(int j=1;j<=1000;j++)
            D[i][j]+=D[i][j-1];
    f>>q;
    for(;q;--q)
    {
        int i,j,x,y;
        f>>i>>j>>x>>y;
        int fp=(i/10)+1;
        int ep=(j/10);
        int ans=0;
        for(int c=ep*10+1;c<=j;c++)
            if(v[c]>=x&&v[c]<=y)
                ++ans;
        for(int c=i;c<=fp*10;c++)
            if(v[c]>=x&&v[c]<=y)
                ++ans;
        int a=D[ep][y]-D[ep][x-1];
        int b=D[fp][y]-D[fp][x-1];
        g<<a-b+ans<<'\n';
    }
    return 0;
}

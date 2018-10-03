#include<bits/stdc++.h>
using namespace std;
ifstream f("hack.in");
ofstream g("hack.out");
int a[51][51];
int main()
{
    srand (time(NULL));
    for(int i=1;i<=50;i+=2)
        for(int j=1;j<=50;++j)
            a[i][j]=1;
    for(int i=2;i<=50;i+=2)
        if(i%4)
            a[i][50]=1;
        else
            a[i][1]=1;
    g<<50<<" "<<50<<" "<<1<<" "<<2<<'\n';
    for(int i=1;i<=50;g<<'\n',++i)
        for(int j=1;j<=50;++j)
            g<<a[i][j];
    return 0;
}

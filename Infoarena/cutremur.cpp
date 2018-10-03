#include<bits/stdc++.h>
using namespace std;
ofstream g("cutremur.out");
int main()
{
    g<<10000<<'\n';
    for(int i=1;i<=100;++i)
        for(int j=1;j<=100;++j)
            g<<i<<" "<<j<<" "<<1+rand()%2<<'\n';
}

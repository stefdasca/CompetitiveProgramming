#include<bits/stdc++.h>
using namespace std;
ifstream f("fenrir.in");
ofstream g("fenrir.out");
int main()
{
    g<<99<<'\n';
    int v1[]={1,3,5,7,9,11,13,15,17};
    int v2[]={2,4,6,8,10,12,14,16,18,19,20};
    for(int i=0;i<=8;++i)
        for(int j=0;j<=10;++j)
            g<<v1[i]<<" "<<v2[j]<<'\n';
    return 0;
}

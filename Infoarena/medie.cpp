#include<bits/stdc++.h>
using namespace std;
ifstream f("medie.in");
ofstream g("medie.out");
int n,nr,fr[7001];
int sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>nr,fr[nr]++;
    for(int i=1;i<=7000;++i)
    {
        sol+=fr[i]*(fr[i]-1)*(fr[i]-2)/2;
        if(fr[i])
            for(int j=1;j<i && i+j<=7000;++j)
                sol+=fr[i]*fr[i-j]*fr[i+j];
    }
    g<<sol;
    return 0;
}

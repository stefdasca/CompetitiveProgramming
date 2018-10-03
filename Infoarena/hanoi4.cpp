#include<bits/stdc++.h>
using namespace std;
ifstream f("hanoi4.in");
ofstream g("hanoi4.out");
int n;
long long v[1002];
int main()
{
    f>>n;
    v[1]=1;
    for(int i=2;i<=n;++i)
    {
        long long nm=3;
        v[i]=2*v[i-1]+1;
        for(int j=i-2;j>=0;nm=nm*2+1,--j)
            if(2*v[j]+nm<v[i])
                v[i]=2*v[j]+nm;
            else
                break;
    }
    g<<v[n];
    return 0;
}

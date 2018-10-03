#include<bits/stdc++.h>
#define Hmmm 666013
using namespace std;
ifstream f("rec.in");
ofstream g("rec.out");
int v[12005],S,N,F;
int main()
{
    f>>S>>N>>F;
    v[0]=1;
    S=S-N*F;
    for(int i=1;i<=N;++i)
        for(int j=i;j<=S;++j)
            v[j]=(v[j]+v[j-i])%Hmmm;
    g<<v[S];
    return 0;
}

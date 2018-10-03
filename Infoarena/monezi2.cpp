#include <bits/stdc++.h>
using namespace std;
ifstream f("monezi2.in");
ofstream g("monezi2.out");
int n,q,s,x;
bool S[100006];
int V[51];
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x;
        V[i]=V[i-1]+x;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=100005; j++)
        {
            if(S[j] && j+V[i]<=100005)
                S[j+V[i]]=1;
            if(j%V[i]==0)
                S[j]=1;
        }
    f>>q;
    for(int i=1; i<=q; i++)
    {
        f>>s;
        if(S[s])
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}

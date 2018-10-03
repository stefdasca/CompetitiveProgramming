#include <bits/stdc++.h>
using namespace std;
ifstream f("perioada01.in");
ofstream g("perioada01.out");
int N,P;
int V[2000000];
int Difference[2000000];
int Phi[2000000];
void read_data()
{
    f>>N>>P;
    for(int i=1;i<=P;i++)
        f>>V[i];
    for(int i=1;i<P;i++)
        Difference[i]=V[i+1]-V[i];
}
void solve()
{
    int k = 0;
    for(int i=2;i<P;i++)
    {
        while(k && Difference[k+1]!=Difference[i])
            k=Phi[k];
        if(Difference[i]==Difference[k+1])
            k++;
        Phi[i]=k;
    }
    int ans=P-1-Phi[P-1];
    if(P%ans!=0)
        g<<"-1";
    else
        g<<V[ans+1]-V[1];
}
int main()
{
    read_data();
    solve();
    return 0;
}

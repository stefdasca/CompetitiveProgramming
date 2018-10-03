#include<bits/stdc++.h>
using namespace std;
ifstream f("pp.in");
ofstream g("pp.out");
map <int,int> M;
int N,K;
int solve(int nr)
{
    if(M[nr])
        return M[nr];
    if(!nr)
        return M[nr]=2;
    int sol=2;
    for(int i=2;i<=K&&sol==2;++i)
        if(solve(nr/i)==2)
            sol=1;
    return M[nr]=sol;
}
int main()
{
    f>>N>>K;
    g<<2-solve(N);
}

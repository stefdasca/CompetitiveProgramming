#include<bits/stdc++.h>
using namespace std;
ifstream f("kprime.in");
ofstream g("kprime.out");
int n,k;
int v[100002],sol;
deque<int>d;
bool isPrim(int x)
{
    if(x<2)
        return 0;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=1;i<=n;++i)
        if(isPrim(v[i]))
            d.push_back(i);
    int l=d.size();
    int prv=0;
    d.push_back(n+1);
    for(int i=0;i<=l-k;++i){
        sol+=(d[i]-prv)*(d[i+k]-d[i+k-1]);
        prv=d[i];
    }
    g<<sol<<'\n';
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("mmsir.in");
ofstream g("mmsir.out");
int n,k;
int v[1000002],sol;
deque<int>d;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    for(int i=2;i<n;++i)
        if((v[i]>v[i-1] && v[i]>v[i+1]) || (v[i]<v[i-1] && v[i]<v[i+1]))
            d.push_back(i);
    int l=d.size();
    if(k==0){
        int b=0;
        for(int i=0;i<l;++i)
        {
            sol+=(d[i]-b)*(d[i]-b-1)/2;
            b=d[i];
        }
        g<<sol<<'\n';
    }
    else
    {
        int prv=1;
        d.push_back(n);
        for(int i=0;i<=l-k;++i){
            sol+=(d[i]-prv)*(d[i+k]-d[i+k-1]);
            prv=d[i];
        }
        g<<sol<<'\n';
    }
    return 0;
}

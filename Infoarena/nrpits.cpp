#include<bits/stdc++.h>
using namespace std;
ifstream f("nrpits.in");
ofstream g("nrpits.out");
int n,nr,v[1000002];
deque<int>d;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    long long sol=0;
    d.push_back(v[1]);
    for(int i=2;i<=n;++i)
    {
        while(d.size() && v[i]>d.back())
        {
            if(d.size()>1)
                ++sol;
            d.pop_back();
        }
        d.push_back(v[i]);
    }
    g<<sol;
    return 0;
}

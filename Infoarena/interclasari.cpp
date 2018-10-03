#include<bits/stdc++.h>
using namespace std;
ifstream f("interclasari.in");
ofstream g("interclasari.out");
int k;
int n,nr;
int s;
vector<int>v;
int main()
{
    f>>k;
    for(;k;--k)
    {
        f>>n;
        s+=n;
        for(;n;--n)
            f>>nr,v.push_back(nr);
    }
    sort(v.begin(),v.end());
    g<<s<<'\n';
    for(int i=0;i<v.size();++i)
        g<<v[i]<<" ";
    return 0;

}

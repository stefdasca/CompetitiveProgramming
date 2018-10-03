#include<bits/stdc++.h>
using namespace std;
ifstream f("alibaba.in");
ofstream g("alibaba.out");
int n,k;
char c[10002];
vector<int>v1;
int main()
{
    f>>n>>k;
    f>>(c+1);
    for(int i=1;i<=n;++i)
        v1.push_back(c[i]-'0');
    v1.push_back(12);
    for(int i=0;i<v1.size()-1 && k;++i)
        while(v1[i]<v1[i+1] && k)
            v1.erase(v1.begin()+i),--k,--i;
    for(int i=0;i<v1.size()-1;++i)
        g<<v1[i];
    return 0;
}

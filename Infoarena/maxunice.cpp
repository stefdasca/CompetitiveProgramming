/*
I love you Rose
I hope you love me too
*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("maxunice.in");
ofstream g("maxunice.out");
int nr=1,n;
vector<int>v;
int main()
{
    f>>n;
    while(n)
        if(n>=nr)
            n-=nr,v.push_back(nr),++nr;
        else
            break;
    g<<v.size()<<'\n';
    for(int i=0;i<v.size();++i)
        if(i+1<v.size())
            g<<v[i]<<'\n';
        else
            g<<v[i]+n<<'\n';
    return 0;
}

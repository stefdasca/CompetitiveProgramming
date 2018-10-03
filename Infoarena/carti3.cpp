#include<bits/stdc++.h>
using namespace std;
ifstream f("carti3.in");
ofstream g("carti3.out");
int n,c;
deque<int>v;
int nr,dir;
int main()
{
    f>>n>>c;
    for(int i=1;i<=c;++i)
        f>>nr,v.push_back(nr);
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        if(nr==-1)
            dir=1-dir;
        else
            if(dir==0)
                v.push_front(nr);
            else
                v.push_back(nr);
    }
    if(dir==0)
        for(int i=0;i<v.size();++i)
            g<<v[i]<<'\n';
    else
        for(int i=v.size()-1;i>=0;--i)
            g<<v[i]<<'\n';
    return 0;
}

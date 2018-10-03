#include<bits/stdc++.h>
using namespace std;
ifstream f("mutari.in");
ofstream g("mutari.out");
int n;
long long s;
int v[100002];
deque<int>mov;
int main()
{
    f>>n;
    int xs=0;
    for(int i=1;i<=n;++i)
        f>>v[i],s+=v[i];
    for(int i=1;i<=n;++i)
        if(v[i]%v[1]!=0){
            g<<-1;
            return 0;
        }
    while(s>v[1])
    {
        bool len=0;
        for(int i=n;i>1;--i){
            while(v[i]>v[i-1])
                mov.push_back(i-1),v[i]-=v[i-1],s-=v[i-1];
            if(v[i]==v[i-1] && len==0)
                mov.push_back(i-1),v[i]-=v[i-1],s-=v[i-1];
            if(v[i])
                len=1;
        }
    }
    g<<mov.size()<<'\n';
    for(int i=0;i<mov.size();++i)
        g<<mov[i]<<'\n';
    return 0;
}

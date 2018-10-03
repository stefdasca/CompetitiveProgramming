#include<bits/stdc++.h>
using namespace std;
ifstream f("ausoara.in");
ofstream g("ausoara.out");
int n,m,nr,v[1002];
deque<int>sol;
deque<int>ch;
deque<int>sol2;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        for(int j=1;j<=nr;++j)
            f>>v[j];
        if(i==1)
        {
            for(int j=1;j<=nr;++j)
                sol.push_back(v[j]);
            continue;
        }
        else
        {
            for(int j=1;j<=nr;++j)
                ch.push_back(v[j]);
            for(;!ch.empty() && !sol.empty();)
            {
                if(sol[0]==ch[0])
                    sol2.push_back(sol[0]),sol.pop_front(),ch.pop_front();
                else
                    if(sol[0]<ch[0])
                        sol.pop_front();
                    else
                        ch.pop_front();
            }
            sol.clear();
            ch.clear();
            for(int j=0;j<sol2.size();++j)
                sol.push_back(sol2[j]);
            sol2.clear();
        }
    }
    g<<sol.size()<<" ";
    for(int j=0;j<sol.size();++j)
        g<<sol[j]<<" ";
    return 0;
}

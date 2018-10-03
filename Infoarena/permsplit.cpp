/// OrangeWarrior #1
#include<bits/stdc++.h>
using namespace std;
ifstream f("permsplit.in");
ofstream g("permsplit.out");
int n;
int nr;
struct str{int min1,max1,exd;};
deque<str>d;
deque<int>moves;
int main()
{
    f>>n;
    int sz=0;
    for(int i=1;i<=n;++i)
    {
        f>>nr;
        d.push_back({nr,nr,i});
        ++sz;
        while(sz>1)
        {
            if(d[sz-1].min1-1==d[sz-2].max1 || d[sz-2].min1-1==d[sz-1].max1)
                moves.push_front(d[sz-2].exd),d[sz-2].min1=min(d[sz-2].min1,d[sz-1].min1),d[sz-2].max1=max(d[sz-2].max1,d[sz-1].max1),--sz,d[sz-1].exd=d[sz].exd,d.pop_back();
            else
                break;
        }
    }
    if(d.size()>1)
        g<<-1;
    else
        for(int i=0;i<moves.size();++i)
            g<<moves[i]<<" ";
    return 0;
}

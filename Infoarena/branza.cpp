#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
ifstream f("branza.in");
ofstream g("branza.out");
long long n,t,s,cost[100005],cant,rez;
deque<long long> deq;
int main()
{
    f>>n>>s>>t;
    for(long long i=1;i<=n;++i)
    {
        f>>cost[i]>>cant;
        if(!deq.empty() && i-deq.front()>t)
            deq.pop_front();
        while(!deq.empty() && cost[i]<=cost[deq.back()]+s*(i-deq.back()))
            deq.pop_back();
        deq.push_back(i);
        rez+=(cost[deq.front()]+s*(i-deq.front()))*cant;
    }
    g<<rez;
    return 0;
}

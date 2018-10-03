/// OrangeWarrior #1
#include<bits/stdc++.h>
using namespace std;
ifstream f("planificare.in");
ofstream g("planificare.out");
int n,k;
struct shows
{
    int st,sf;
};
shows v[100002];
bool test(shows a, shows b)
{
    return a.sf<b.sf;
}
multiset<int>s;
multiset<int>::iterator it;
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i].st>>v[i].sf;
    sort(v+1,v+n+1,test);
    for(int i=1;i<=k;++i)
        s.insert(0);
    for(int i=1;i<=n;++i)
        v[i].st*=-1,v[i].sf*=-1;
    int sol=n;
    for(int i=1;i<=n;++i)
    {
        it=s.lower_bound(v[i].st);
        if(it==s.end()){
            --sol;continue;
        }
        s.erase(it);
        s.insert(v[i].sf);
    }
    g<<sol<<" ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
struct strings
{
    string s;
};
strings v[5];
int n,sol;
long long cod;
unordered_map<long long,int>m;
unordered_map<long long,int> ::iterator it;
deque<long long>d;
int main()
{
    f>>n;
    int lmin=60;
    for(int i=1;i<=n;++i){
        f>>v[i].s;
        int nr=v[i].s.size();
        lmin=min(lmin,nr);
    }
    int b=1;
    int e=lmin;
    while(b<=e)
    {
        int mid=(b+e)/2;
        cod=0;
        long long nn=(1LL<<mid-1);
        d.clear();
        for(int p=1;p<=n;++p){
            m.clear();
            cod=0;
            for(int i=0;i<v[p].s.size();++i)
            {
                if(cod>=nn)
                    cod-=nn;
                cod<<=1;
                cod+=(v[p].s[i]=='b');
                if(i+1>=mid)
                    m[cod]++;
            }
            if(p==1)
                for(it=m.begin();it!=m.end();++it)
                    d.push_back(it->first);
            else
            {
                int z=d.size();
                for(int j=0;j<z;++j){
                    if(m[d[0]])
                        d.push_back(d[0]);
                    d.pop_front();
                }
            }
        }
        if(d.size())
        {
            sol=mid;
            b=mid+1;
        }
        else
            e=mid-1;
    }
    g<<sol;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("cifre4.in");
ofstream g("cifre4.out");
int t;
int n,p;
bool v[5000002];
deque<int>r;
deque<int>lc;
deque<int>pant;
deque<int>vsol;
int q[4]={2,3,5,7};
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>n>>p;
        memset(v,0,p+1);
        for(int i=0;i<=3;++i)
        {
            lc.push_back(q[i]);
            pant.push_back(-1);
            r.push_back(q[i]%p);
            v[q[i]%p]=1;
            if(q[i]%p==n){
                g<<q[i];
                break;
            }
        }
        int z=-1;
        bool ok=0;
        int sz=3;
        while(v[n]==0 && z<sz)
        {
            ++z;
            for(int i=0;i<=3;++i)
            {
                if((r[z]*10+q[i])%p==n){
                    ++sz;
                    lc.push_back(q[i]);
                    pant.push_back(z);
                    r.push_back(n);
                    v[n]=1;break;}
                else
                    if(v[(r[z]*10+q[i])%p]==0){
                        ++sz;
                        lc.push_back(q[i]);
                        pant.push_back(z);
                        r.push_back((r[z]*10+q[i])%p);
                        v[(r[z]*10+q[i])%p]=1;
                    }
            }
        }
        if(v[n]==1){
            while(pant[sz]!=-1)
                vsol.push_front(lc[sz]),sz=pant[sz];
            vsol.push_front(lc[sz]);
            for(int i=0;i<vsol.size();++i)
                g<<vsol[i];
            g<<'\n';
        }
        else
            g<<-1<<'\n';
        lc.clear();
        pant.clear();
        r.clear();
        vsol.clear();
    }
    return 0;
}

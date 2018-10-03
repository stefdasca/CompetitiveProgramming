#include<bits/stdc++.h>
using namespace std;
ifstream f("multiplu.in");
ofstream g("multiplu.out");
int a,b,mc,mpoz;
bool war[2000002];
int lcm(int x, int y)
{
    int z=0;
    while(y)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return a*b/x;
}
vector<int>r;
vector<int>c;
vector<int>lp;
deque<int>sol;
int main()
{
    f>>a>>b;
    mc=lcm(a,b);
    r.push_back(1);
    c.push_back(1);
    lp.push_back(-1);
    war[1]=1;
    int i=0,lv=0;
    bool ok=1;
    while(ok)
    {
        int nr=(r[i]*10)%mc;
        if(war[nr]==0)
        {
            r.push_back(nr);
            c.push_back(0);
            lp.push_back(i);
            ++lv;
            war[nr]=1;
            if(nr==0)
                break;
        }
        nr=(r[i]*10+1)%mc;
        if(war[nr]==0)
        {
            r.push_back(nr);
            c.push_back(1);
            lp.push_back(i);
            ++lv;
            war[nr]=1;
            if(nr==0)
                break;
        }
        ++i;
    }
    while(lv>=0)
    {
        sol.push_front(c[lv]);
        lv=lp[lv];
    }
    for(int i=0;i<sol.size();++i)
        g<<sol[i];
    return 0;
}

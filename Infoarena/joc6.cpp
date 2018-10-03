#include<bits/stdc++.h>
using namespace std;
ifstream f("joc6.in");
ofstream g("joc6.out");
int n,nr,x1,x2,d;
deque<int>a;
deque<int>b;
deque<int>m;
int fr[1002];
void read()
{
    f>>n;
    f>>nr;
    while(nr)
    {
        ++x1;
        a.push_back(nr);
        f>>nr;
    }
    f>>nr;
    while(nr)
    {
        ++x2;
        b.push_back(nr);
        f>>nr;
    }
}
void solve()
{
    for(int i=1;i<=n && (x1 && x2);++i)
    {
        if(i%2==1)
        {
            ++d;
            fr[a[0]]++;
            m.push_back(a[0]);
            a.pop_front();
            --x1;
            int val=m[d-1];
            if(fr[val]==2)
            while(fr[val])
            {
                a.push_back(m[d-1]);
                --d;
                ++x1;
                --fr[m[d]];
                m.pop_back();
            }
        }
        else
        {
            ++d;
            fr[b[0]]++;
            m.push_back(b[0]);
            b.pop_front();
            --x2;
            int val=m[d-1];
            if(fr[val]==2)
            while(fr[val])
            {
                b.push_back(m[d-1]);
                --d;
                ++x2;
                --fr[m[d]];
                m.pop_back();
            }
        }
    }
    if(x1==0)
        g<<"A"<<'\n';
    else{
        for(int i=0;i<x1;++i)
            g<<a[i]<<" ";
        g<<'\n';
    }
    if(x2==0)
        g<<"B"<<'\n';
    else{
        for(int i=0;i<x2;++i)
            g<<b[i]<<" ";
        g<<'\n';
    }
    if(d==0)
        g<<0<<'\n';
    else
    {
        for(int i=0;i<d;++i)
            g<<m[i]<<" ";
        g<<'\n';
    }
}
int main()
{
    read();
    solve();
    return 0;
}

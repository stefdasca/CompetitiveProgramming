#include<bits/stdc++.h>
using namespace std;
ifstream f("cstring.in");
ofstream g("cstring.out");
int n;
char a[1000002],b[1000002],c[1000002];
char sol[1000002];
int nr12,nr23,nr13,nrd;
vector<int>v[5];
int main()
{
    f>>n;
    f>>(a+1);
    f>>(b+1);
    f>>(c+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i]==b[i] && b[i]==c[i])
            sol[i]=a[i];
        else
            if(a[i]==b[i])
                ++nr12,v[1].push_back(i);
            else
                if(a[i]==c[i])
                    ++nr13,v[2].push_back(i);
                else
                    if(b[i]==c[i])
                        ++nr23,v[3].push_back(i);
                    else
                        ++nrd,v[4].push_back(i);
    }
    for(int i=v[4].size()-1;i>=0;--i)
    {
        if(!v[1].empty() && nr12>=nr13 && nr12>=nr23)
        {
            sol[v[1].back()]=a[v[1].back()];
            sol[v[4].back()]=c[v[4].back()];
            --nr12;
            v[1].pop_back();
            v[4].pop_back();
        }
        else
            if(!v[2].empty() && nr13>=nr12 && nr13>=nr23)
            {
                sol[v[2].back()]=a[v[2].back()];
                sol[v[4].back()]=b[v[4].back()];
                --nr13;
                v[2].pop_back();
                v[4].pop_back();
            }
            else
                if(!v[3].empty())
                {
                    sol[v[3].back()]=b[v[3].back()];
                    sol[v[4].back()]=a[v[4].back()];
                    --nr23;
                    v[3].pop_back();
                    v[4].pop_back();
                }
                else
                    break;
    }
    if(v[4].size())
    {
        int q=1;
        for(int j=0;j<v[4].size();++j)
        {
            if(q==1)
                sol[v[4][j]]=a[v[4][j]];
            if(q==2)
                sol[v[4][j]]=b[v[4][j]];
            if(q==3)
                sol[v[4][j]]=c[v[4][j]];
            q++;
            if(q==4)
                q=1;
        }
    }
    else
    {
        while(v[1].size() && v[2].size() && v[3].size())
        {
            sol[v[1].back()]=a[v[1].back()];
            sol[v[2].back()]=a[v[2].back()];
            sol[v[3].back()]=b[v[3].back()];
            v[1].pop_back();
            v[2].pop_back();
            v[3].pop_back();
        }
        while(v[1].size() && v[2].size())
        {
            sol[v[1].back()]=a[v[1].back()];
            v[1].pop_back();
            sol[v[2].back()]=a[v[2].back()];
            v[2].pop_back();
        }
        while(v[1].size() && v[3].size())
        {
            sol[v[1].back()]=b[v[1].back()];
            v[1].pop_back();
            sol[v[3].back()]=b[v[3].back()];
            v[3].pop_back();
        }
        while(v[2].size() && v[3].size())
        {
            sol[v[2].back()]=c[v[2].back()];
            v[2].pop_back();
            sol[v[3].back()]=c[v[3].back()];
            v[3].pop_back();
        }
        while(v[1].size()>=2)
        {
            sol[v[1].back()]=a[v[1].back()];
            v[1].pop_back();
            sol[v[1].back()]=c[v[1].back()];
            v[1].pop_back();
        }
        while(v[2].size()>=2)
        {
            sol[v[2].back()]=a[v[2].back()];
            v[2].pop_back();
            sol[v[2].back()]=b[v[2].back()];
            v[2].pop_back();
        }
        while(v[3].size()>=2)
        {
            sol[v[3].back()]=b[v[3].back()];
            v[3].pop_back();
            sol[v[3].back()]=a[v[3].back()];
            v[3].pop_back();
        }
        if(v[1].size())
        {
            sol[v[1].back()]=b[v[1].back()];
            v[1].pop_back();
        }
        if(v[2].size())
        {
            sol[v[2].back()]=a[v[2].back()];
            v[2].pop_back();
        }
        if(v[3].size())
        {
            sol[v[3].back()]=b[v[3].back()];
            v[3].pop_back();
        }
    }
    g<<(sol+1);
    return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("semne.in");
ofstream g("semne.out");
int n,v[50002];
long long s,s2;
vector<int>p,m;
int sz1,sz2;
int sgn[50002];
int main()
{
    f>>n>>s;
    srand(time(NULL));
    for(int i=1;i<=n;++i)
    {
        f>>v[i];
        int nr=v[i];
        if(s2<=s)
        {
            p.push_back(i);
            ++sz1;
            s2+=nr;
        }
        else
        {
            s2-=nr;
            m.push_back(i);
            ++sz2;
            sgn[i]=1;
        }
    }
    while(s2!=s)
    {
        if(s2>s)
        {
            int poz=rand()%sz1;
            swap(p[poz],p[sz1-1]);
            int nr=p[sz1-1];
            p.pop_back();
            m.push_back(nr);
            s2-=2*v[nr];
            sgn[nr]=1;
            --sz1,++sz2;
        }
        else
        {
            int poz=rand()%sz2;
            swap(m[poz],m[sz2-1]);
            int nr=m[sz2-1];
            sgn[nr]=0;
            m.pop_back();
            p.push_back(nr);
            s2+=2*v[nr];
            ++sz1,--sz2;
        }
    }
    for(int i=1;i<=n;++i)
        if(sgn[i])
            g<<"-";
        else
            g<<"+";
    return 0;
}

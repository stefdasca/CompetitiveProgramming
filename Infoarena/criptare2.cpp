/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("criptare2.in");
ofstream g("criptare2.out");
map<string,int>m;
string s;
int frq[27],N,M;
int main()
{
    f>>N;
    for(int i=1;i<=N;++i)
    {
        memset(frq,0,sizeof(frq));
        f>>s;
        int nr=0;
        for(int j=0;j<s.size();++j)
            if(!frq[s[j]-'a'])
                frq[s[j]-'a']=++nr;
        for(int j=0;j<s.size();++j)
            s[j]='a'+frq[s[j]-'a']-1;
        m[s]++;
    }
    f>>M;
    for(int i=1;i<=M;++i)
    {
        memset(frq,0,sizeof(frq));
        f>>s;
        int nr=0;
        for(int j=0;j<s.size();++j)
            if(!frq[s[j]-'a'])
                frq[s[j]-'a']=++nr;
        for(int j=0;j<s.size();++j)
            s[j]='a'+frq[s[j]-'a']-1;
        if(m[s])
            g<<1<<'\n';
        else
            g<<0<<'\n';
    }
    return 0;
}

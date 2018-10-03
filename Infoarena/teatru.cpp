#include<bits/stdc++.h>
using namespace std;
ifstream f("teatru.in");
ofstream g("teatru.out");
int n,c;
char s[55001];
int fr[27],nrc=0;
deque<char>d;
int lmax,st;
int main()
{
    f>>n>>c;
    f>>s;
    for(int i=0;i<n;++i)
    {
        d.push_back(s[i]);
        fr[s[i]-'A']++;
        if(fr[s[i]-'A']==1){
            ++nrc;
            if(nrc>c)
                while(nrc>c)
                {
                    fr[d[0]-'A']--;
                    if(fr[d[0]-'A']==0)
                        --nrc;
                    d.pop_front();
                }
        }
        if(d.size()>lmax)
            lmax=d.size(),st=i-d.size()+1;
    }
    g<<lmax<<'\n';
    for(int i=st;i<st+lmax;++i)
        g<<s[i];
    return 0;
}

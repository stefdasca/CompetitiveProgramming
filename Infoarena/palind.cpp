#include<bits/stdc++.h>
using namespace std;
ifstream f("palind.in");
ofstream g("palind.out");
int t,sol,L;
char c[200];
int frq[27];
void find_the_flower()
{
    for(int i=0,j=L-1;i<j;++i,--j)
    {
        if(frq[c[i]-'a']==1)
        {
            swap(c[i],c[i+1]);
            sol++;
        }
        int k=j;
        while(c[k]!=c[i])
            --k;
        while(k<j)
        {
            swap(c[k],c[k+1]);
            ++k;
            ++sol;
        }
        frq[c[i]-'a']-=2;
    }
    g<<sol<<'\n';
}
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>c;
        for(int i=0;i<26;++i)
            frq[i]=0;
        sol=0;
        L=strlen(c);
        for(int i=0;i<L;++i)
            frq[c[i]-'a']++;
        int sore=0;   /// sore = pain
        for(int i=0;i<26;++i)
            if(frq[i]%2==1)
                ++sore;
        if(sore>1)
            g<<-1<<'\n';
        else
            find_the_flower();
    }
    return 0;
}

/// OrangeWarrior #1
#include<bits/stdc++.h>
using namespace std;
ifstream f("secv5.in");
ofstream g("secv5.out");
long long n,a,b,nr;
bool ok=0,ok2=0;
unsigned int v[(1<<20)+3];
inline long long secv(int b)
{
    unordered_map < unsigned , int > m;
    long long nr=0,i=1,j=1;
    for(i=1; i<=n; i++)
    {
        m[v[i]]++;
        while(m.size()>b)
        {
            m[v[j]]--;
            if(m[v[j]]==0)
               m.erase(v[j]);
            j++;
        }
        nr+=(i-j+1);
    }
    return nr;
}
int main()
{
    f>>n>>a>>b;
    for(int i=1;i<=n;++i)
        f>>v[i];
    g<<secv(b)-secv(a-1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("pusculita.in");
ofstream g("pusculita.out");
int s,n;
int v[10002];
int gr,val;
int main()
{
    f>>s>>n;
    for(int i=1;i<=n;++i)
    {
        f>>gr>>val;
        if(v[gr]==0)
            v[gr]=val;
        else
            v[gr]=min(v[gr],val);
        for(int j=gr+1;j<=s;++j)
            if(v[j-gr])
                if(v[j]==0)
                    v[j]=v[j-gr]+val;
                else
                    v[j]=min(v[j],v[j-gr]+val);
    }
    g<<v[s]<<'\n';
    return 0;
}

/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("snowball.in");
ofstream g("snowball.out");
int m,n;
int v1[10002],Lp[10002];
int Wt[10002];
int losols[500002],isEnd,fo,nr;
int beg[500002];
int v2[500002];
vector<int>v[10002];
int main()
{
    f>>m>>n;
    for(int i=1;i<=m;++i)
        f>>v1[i];
    for(int i=1;i<=n;++i)
        f>>v2[i],v[v2[i]].push_back(i);
    for(int i=1;!isEnd && i<=n;++i)
        if(v2[i]==v1[1])
        {
            Lp[1]=i;
            for(int j=2;j<=m;++j)
            {
                if(Lp[j]>Lp[j-1])
                    continue;
                int b=Wt[j];
                int e=v[v1[j]].size()-1;
                bool kk=0;
                while(b<=e)
                {
                    int mi=(b+e)/2;
                    if(v[v1[j]][mi]>Lp[j-1] && (mi==0 || v[v1[j]][mi-1]<Lp[j-1]))
                    {
                        Lp[j]=v[v1[j]][mi];
                        kk=1;
                        Wt[j]=mi;
                        break;
                    }
                    else
                        if(v[v1[j]][mi]>Lp[j-1])
                            e=mi-1;
                        else
                            b=mi+1;
                }
                if(!kk)
                    isEnd=1;
            }
            if(!isEnd)
                losols[++nr]=Lp[m],beg[nr]=i;
        }
    int poz=1;
    long long sols=0;
    int maxlen=0;
    losols[nr+1]=n+1;
    for(int i=1;i<=n;++i){
        while(poz<=nr)
        {
            if(beg[poz]>=i)
                break;
            ++poz;
        }
        maxlen=max(maxlen,losols[poz]-i);
        sols=sols+1LL*(losols[poz]-i);
    }
    g<<maxlen<<" "<<sols<<'\n';
    return 0;
}

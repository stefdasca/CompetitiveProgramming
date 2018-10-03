#include<bits/stdc++.h>
using namespace std;
ifstream f("drum2.in");
ofstream g("drum2.out");
int n,v[10002];
int who[10002],maxs[10002];
int sm[35];
deque<int>d;
int main()
{
    f>>n;
    int L=n*(n+1)*(2*n+1)/6;
    for(int i=1;i<=n;++i)
        sm[i]=sm[i-1]+i*i;
    for(int i=1;i<=L;++i)
        f>>v[i];
    maxs[1]=v[1];
    int lvl=1;
    L=1;
    int C=1;
    for(int i=1;i<=sm[n-1];++i)
    {
        if(i>sm[lvl])
        {
            ++lvl;
            L=1;
            C=1;
        }
        if(maxs[i]+v[sm[lvl]+L*(lvl+1)+C]>maxs[sm[lvl]+L*(lvl+1)+C])
            maxs[sm[lvl]+L*(lvl+1)+C]=maxs[i]+v[sm[lvl]+L*(lvl+1)+C],who[sm[lvl]+L*(lvl+1)+C]=i;
        else
            if(maxs[i]+v[sm[lvl]+L*(lvl+1)+C]==maxs[sm[lvl]+L*(lvl+1)+C])
                who[sm[lvl]+L*(lvl+1)+C]=min(who[sm[lvl]+L*(lvl+1)+C],i);
        if(maxs[i]+v[sm[lvl]+L*(lvl+1)+C+1]>maxs[sm[lvl]+L*(lvl+1)+C+1])
            maxs[sm[lvl]+L*(lvl+1)+C+1]=maxs[i]+v[sm[lvl]+L*(lvl+1)+C+1],who[sm[lvl]+L*(lvl+1)+C+1]=i;
        else
            if(maxs[i]+v[sm[lvl]+L*(lvl+1)+C+1]==maxs[sm[lvl]+L*(lvl+1)+C+1])
                who[sm[lvl]+L*(lvl+1)+C+1]=min(who[sm[lvl]+L*(lvl+1)+C+1],i);
        if(maxs[i]+v[sm[lvl]+(L-1)*(lvl+1)+C+1]>maxs[sm[lvl]+(L-1)*(lvl+1)+C+1])
            maxs[sm[lvl]+(L-1)*(lvl+1)+C+1]=maxs[i]+v[sm[lvl]+(L-1)*(lvl+1)+C+1],who[sm[lvl]+(L-1)*(lvl+1)+C+1]=i;
        else
            if(maxs[i]+v[sm[lvl]+(L-1)*(lvl+1)+C+1]==maxs[sm[lvl]+(L-1)*(lvl+1)+C+1])
                who[sm[lvl]+(L-1)*(lvl+1)+C+1]=min(who[sm[lvl]+(L-1)*(lvl+1)+C+1],i);
        ++C;
        if(C>lvl)
            ++L,C=1;
    }
    int mx=0,wh=0;
    for(int i=sm[n-1]+1;i<=sm[n];++i){
        if(maxs[i]>mx)
            mx=maxs[i],wh=i;
    }
    g<<mx<<'\n';
    while(wh)
    {
        d.push_front(wh);
        wh=who[wh];
    }
    for(int i=0;i<d.size();++i)
        g<<d[i]<<" ";
    return 0;
}

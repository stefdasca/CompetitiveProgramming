/// #bettercoderthanshebeautiful
#include<bits/stdc++.h>
using namespace std;
ifstream f("submatrix.in");
ofstream g("submatrix.out");
int a[302][302],n,m,k;
unordered_map<int,int>R;
int frq[302*302];
inline bool gut(int L)
{
    memset(frq,0,sizeof(frq));
    int nrd=0;
    for(int i=1;i<=L;++i)
        for(int j=1;j<=L;++j)
        {
            frq[a[i][j]]++;
            if(frq[a[i][j]]==1)
                ++nrd;
        }
    if(nrd<=k)
        return 1;
    for(int i=1;i<=n-L+1;++i)
        if(i&1)
            for(int j=1;j<=m-L+1;++j)
                if(j==1)
                {
                    if(i!=1)
                        for(int o=1;o<=L;++o)
                        {
                            frq[a[i-1][o]]--;
                            if(!frq[a[i-1][o]])
                                --nrd;
                            if(!frq[a[i+L-1][o]])
                                ++nrd;
                            frq[a[i+L-1][o]]++;
                        }
                    if(nrd<=k)
                        return 1;
                }
                else
                {
                    for(int o=i;o<i+L;++o)
                    {
                        frq[a[o][j-1]]--;
                        if(!frq[a[o][j-1]])
                            --nrd;
                        if(!frq[a[o][j+L-1]])
                            ++nrd;
                        frq[a[o][j+L-1]]++;
                    }
                    if(nrd<=k)
                        return 1;
                }
        else
            for(int j=m;j>=L;--j)
                if(j==m)
                {
                    for(int o=m-L+1;o<=m;++o)
                    {
                        frq[a[i-1][o]]--;
                        if(!frq[a[i-1][o]])
                            --nrd;
                        if(!frq[a[i+L-1][o]])
                            ++nrd;
                        frq[a[i+L-1][o]]++;
                    }
                    if(nrd<=k)
                        return 1;
                }
                else
                {
                    for(int o=i;o<i+L;++o)
                    {
                        if(!frq[a[o][j-L+1]])
                            ++nrd;
                        frq[a[o][j-L+1]]++;
                        frq[a[o][j+1]]--;
                        if(!frq[a[o][j+1]])
                            --nrd;
                    }
                    if(nrd<=k)
                        return 1;
                }
    return 0;
}
int main()
{
    f>>n>>m>>k;
    int ct=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            f>>a[i][j];
            if(!R[a[i][j]])
            {
                ++ct;
                R[a[i][j]]=ct;
            }
            a[i][j]=R[a[i][j]];
        }
    int i, step, mn = min(n, m);
    for(step = 1; step <= mn; step <<= 1);
    for(i = 0; step; step >>= 1)
        if(i+step <= mn && gut(i+step))
            i += step;
    g<< i << "\n";
    return 0;
}

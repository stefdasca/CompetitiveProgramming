#include<bits/stdc++.h>
using namespace std;
ifstream f("text5.in");
ofstream g("text5.out");
int n;
char c[1000002];
vector<int>v[202]; // numerele de la 00 la 99, n%2=1, n%2=0
vector<int>v2[3002]; // numerele de la 000 la 999, n%3=0, n%3=1,n%3=2
int dp[1000002];
int nr3[1000002],nr2[1000002],nr;
int last2[1000002],last3[1000002];
bool gut[1000002];
int lm[1000002];
int tip[1000002];
void p2()
{
    nr=10*(c[1]-'0')+(c[2]-'0');
    v[nr].push_back(1);
    nr2[1]=nr;
    for(int i=2;i<n;++i)
    {
        nr%=10;
        nr=nr*10+(c[i+1]-'0');
        nr2[i]=nr+100*(1-i&1);
        if(i&1)
            v[nr].push_back(i);
        else
            v[100+nr].push_back(i);
    }
    for(int i=0;i<=199;++i)
    {
        if(!v[i].size())
            continue;
        for(int j=0;j<v[i].size();++j)
            last2[v[i][j]]=v[i].back();
    }
}
void p3()
{
    nr=100*(c[1]-'0')+10*(c[2]-'0')+(c[3]-'0');
    v2[1000+nr].push_back(1);
    nr3[1]=nr+1000;
    for(int i=2;i<n-1;++i)
    {
        nr%=100;
        nr=nr*10+(c[i+2]-'0');
        nr3[i]=nr+1000*(i%3);
        if(i%3==2)
            v2[2000+nr].push_back(i);
        else
            if(i%3==0)
                v2[nr].push_back(i);
            else
                v2[1000+nr].push_back(i);
    }
    for(int i=0;i<=2999;++i)
    {
        if(!v2[i].size())
            continue;
        for(int j=0;j<v2[i].size();++j)
            last3[v2[i][j]]=v2[i].back();
    }
}
void solve()
{
    gut[1]=1;
    for(int i=1;i<n;++i)
    {
        if(!gut[i])
            continue;
        /// 3
        int nxtp=n+1;
        int q=i;
        if(n-i>=2)
        {
            while(nxtp>=q)
            {
                q+=3;
                int R=last3[q-3];
                if(nxtp==n+1 && R==n+1)
                    break;
                if(R!=n+1)
                    if(nxtp==n+1)
                        nxtp=R;
                    else
                        nxtp=max(nxtp,R);
                if(nxtp>=n-2)
                {
                    q=nxtp+3;
                    break;
                }
                if(q>n)
                    break;
            }
            if(dp[i]+1>dp[q])
            {
                gut[q]=1;
                dp[q]=dp[i]+1;
                lm[q]=i;
                tip[q]=3;
            }
        }
        nxtp=n+1;q=i;
        while(nxtp>=q)
        {
            q+=2;
            int R=last2[q-2];
            if(nxtp==n+1 && R==n+1)
                break;
            if(R!=n+1)
                if(nxtp==n+1)
                    nxtp=R;
                else
                    nxtp=max(nxtp,R);
            if(q>n)
                break;
            if(nxtp>=n-1)
            {
                q=nxtp+2;
                break;
            }
        }
        if(dp[i]+1>dp[q])
        {
            gut[q]=1;
            dp[q]=dp[i]+1;
            lm[q]=i;
            tip[q]=2;
        }
    }
}
void sol()
{
    deque<pair<int,int> >d;
    g<<dp[n+1]<<'\n';
    int poz=n+1;
    while(poz!=1)
    {
        d.push_front({lm[poz],tip[poz]});
        poz=lm[poz];
    }
    for(int i=0;i<d.size();++i)
        g<<d[i].first<<" "<<d[i].second<<'\n';
}
int main()
{
    f>>n;
    f>>c+1;
    p2();
    p3();
    solve();
    sol();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("stive.in");
ofstream g("stive.out");
int n,v[30002];
void mare()
{
    for(int i=1;i<=n;++i)
        v[i]=i;
    const int N=n;
    int n1=n;
    int sol=0;
    while(n1)
    {
        n1-=(n1+1)/2;
        ++sol;
    }
    g<<sol<<'\n';
    while(n)
    {
        int x=(n+1)/2;
        vector<int>q;
        for(int i=1;i<=N;++i)
            if(v[i]>=x)
                q.push_back(i);
        g<<q.size()<<" ";
        int l=q.size();
        for(int i=0;i<l;++i)
        {
            g<<q[i]<<" ";
            v[q[i]]-=x;
        }
        g<<x<<'\n';
        n-=x;
    }
}
int main()
{
    f>>n;
    mare();
    return 0;
}

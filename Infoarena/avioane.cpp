#include<bits/stdc++.h>
using namespace std;
ifstream f("avioane.in");
ofstream g("avioane.out");
int n,v[100002];
long long sol,p[100002];
int Lp=0;
void conquer(int L, int R)
{
    if(L>R)
        return;
    int mid=(L+R)/2;
    long long ans=0;
    long long val=0;
    for(int i=p[L-1]; i<=p[R+1] && i<mid; i++)
    {
        val=1LL*(mid-i)*v[i]+1LL*(n-mid+1)*v[mid];
        if(val>ans)
        {
            ans=val;
            p[mid]=i;
        }
    }
    if(ans>sol)
        sol=ans;
    conquer(L,mid-1);
    conquer(mid+1,R);
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    p[0]=1;
    p[n+1]=n;
    conquer(1,n);
    g<<sol;
    return 0;
}

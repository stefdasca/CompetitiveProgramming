#include<bits/stdc++.h>
using namespace std;
ifstream f("marbles.in");
ofstream g("marbles.out");
int n,m;
int AIB[100002][70];
struct pos
{
    int val, col;
};
pos v[100002];
bool test(pos a, pos b)
{
    return a.val<b.val;
}
void Add(int nod, int unde)
{
    for(;nod<=n;nod+=(nod&(-nod)))
        AIB[nod][unde]++;
}
int Compute(int nod, int unde)
{
    int sol=0;
    for(;nod;nod-=(nod&(-nod)))
        sol+=AIB[nod][unde];
    return sol;
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>v[i].val>>v[i].col;
    sort(v+1,v+n+1,test);
    for(int i=1;i<=n;++i)
        Add(i,v[i].col);
    v[0].val=1-(1<<30)-(1<<30);
    v[n+1].val=-1+(1<<30)+(1<<30);
    for(int i=1;i<=m;++i)
    {
        int tip,A,B;
        f>>tip>>A>>B;
        if(tip==0)
        {
            int b=1;
            int e=n;
            while(b<=e)
            {
                int m=(b+e)/2;
                if(v[m].val==A){
                    v[m].val=A+B;
                    break;
                }
                if(v[m].val>A)
                    e=m-1;
                else
                    b=m+1;
            }
        }
        else
        {
            int sola=0;
            int solb=0;
            int b=1;
            int e=n;
            while(b<=e)
            {
                int m=(b+e)/2;
                if(v[m].val>=A && v[m-1].val<A){
                    sola=m;
                    break;
                }
                if(v[m].val<=A)
                    b=m+1;
                else
                    e=m-1;
            }
            b=1;
            e=n;
            while(b<=e)
            {
                int m=(b+e)/2;
                if(v[m].val<=B && v[m+1].val>B){
                    solb=m;
                    break;
                }
                if(v[m].val<=B)
                    b=m+1;
                else
                    e=m-1;
            }
            int max1=0;
            for(int pp=1;pp<=64;++pp)
                max1=max(max1,Compute(solb,pp)-Compute(sola-1,pp));
            g<<max1<<'\n';
        }
    }
    return 0;
}

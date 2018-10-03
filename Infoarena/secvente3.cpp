#include<bits/stdc++.h>
#define maxM 10005
using namespace std;
long long a,b,p,x;
int m;
int sol[maxM];
struct tip
{
    int st;
    long long sum;
    int ind;
};
tip qry[maxM];
bool cmp1(tip a,tip b)
{
    return a.st<b.st;
}
bool cmp2(tip a,tip b)
{
    return a.sum<b.sum;
}
int st;
long long s;
int main()
{
    freopen("secvente3.in","r",stdin);
    freopen("secvente3.out","w",stdout);
    scanf("%lld%lld%lld%d",&a,&b,&p,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%lld",&st,&s);
        qry[i]={st,s,i};
    }
    sort(qry+1,qry+m+1,cmp1);
    long long s=0LL;
    int ind=1;
    for(int i=1;ind<=m;i++)
    {
        if(i==1)
            x=a;
        else
            x=(x*b)%p;
        s=s+x;
        while(ind<=m && qry[ind].st==(i+1))
        {
            qry[ind].sum+=s;
            ind++;
        }
    }
    sort(qry+1,qry+m+1,cmp2);
     s=0LL;
     ind=1;
    for(int i=1;ind<=m;i++)
    {
        if(i==1)
            x=a;
        else
            x=(x*b)%p;
        s=s+x;
        while(ind<=m && qry[ind].sum<s)
        {
            sol[qry[ind].ind]=i-1;
            ind++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d ",sol[i]);
    printf("\n");
    return 0;
}

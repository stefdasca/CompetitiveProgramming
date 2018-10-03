#include<bits/stdc++.h>
#define maxN 100005
using namespace std;
ifstream f("secv4.in");
ofstream g("secv4.out");
deque<int>q[2];
int n,i,j,x,y,poz,len;
int semn[maxN];
double value,sum[maxN],sol=numeric_limits <double>::min();
int main()
{
    f>>n>>x>>y;
    for(i=1;i<=n;i++)
    {
        f>>value;
        if(value>0)
            semn[i]=semn[i-1];
        else
            semn[i]=!semn[i-1],value=-value;
        value=log(value);
        sum[i]=sum[i-1]+value;
    }
    for(i=x;i<=n;i++)
    {
        while(!q[semn[i-x]].empty() && sum[q[semn[i-x]].back()]>sum[i-x])
            q[semn[i-x]].pop_back();
        q[semn[i-x]].push_back(i-x);
        while(!q[semn[i]].empty() && q[semn[i]].front()<i-y)
            q[semn[i]].pop_front();
        if(!q[semn[i]].empty() && sum[i]-sum[q[semn[i]].front()]>sol)
        {
            sol=sum[i]-sum[q[semn[i]].front()];
            poz=q[semn[i]].front();
            len=i-poz+1;
        }
    }
    g<<len-1<<" "<<poz+1;
    return 0;
}

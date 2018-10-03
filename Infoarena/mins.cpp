#include<bits/stdc++.h>
using namespace std;
ifstream f("mins.in");
ofstream g("mins.out");
bool pr[1000002];
int a,b,val;
int nr[1000002];
void ciur(int UB)
{
    for(int i=2;i<=UB;++i)
    {
        if(nr[i])
            continue;
        for(int j=i;j<=UB;j+=i)
            nr[j]++;
        if(UB/i<i)
            continue;
        for(int j=i*i;j<=UB;j+=i*i)
            pr[j]=1;
    }
}
int main()
{
    f>>a>>b;
    --a;
    --b;
    if(a>b)
        swap(a,b);
    ciur(a);
    long long ss=1LL*a*b;
    for(int R=2;R<=a;++R)
    {
        if(pr[R])
            continue;
        if(nr[R]%2==0)
            ss+=1LL*(a/R)*(b/R);
        else
            ss-=1LL*(a/R)*(b/R);
    }
    g<<ss<<'\n';
    return 0;
}

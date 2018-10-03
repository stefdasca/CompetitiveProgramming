#include<bits/stdc++.h>
using namespace std;
ifstream f("teams.in");
ofstream g("teams.out");
int n,a,B,sol=0;
int v[100002],nr;
int main()
{
    f>>n>>a>>B;
    for(int i=1;i<=n;++i)
        f>>v[i];
    sort(v+1,v+n+1);
    v[n+1]=(1<<29);
    for(int i=1;v[i]+v[i+1]<=B;++i)
    {
        int b=i+1;
        int e=n;
        int s1=0,s2=0;
        int m=0;
        while(b<=e)
        {
            m=(b+e)/2;
            if(v[m]+v[i]>=a && v[m-1]+v[i]<a)
            {
                s1=m;
                break;
            }
            else
                if(v[m]+v[i]<a)
                    b=m+1;
                else
                    e=m-1;
        }
        if(s1==0)
            s1=i+1;
        b=i+1;
        e=n;
        m=0;
        while(b<=e)
        {
            m=(b+e)/2;
            if(v[m]+v[i]<=B && v[m+1]+v[i]>B)
            {
                s2=m;
                break;
            }
            else
                if(v[m]+v[i]>B)
                    e=m-1;
                else
                    b=m+1;
        }
        sol+=s2-s1+1;
    }
    g<<sol;
    return 0;
}

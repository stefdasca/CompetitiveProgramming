#include<bits/stdc++.h>
using namespace std;
ifstream f("compact.in");
ofstream g("compact.out");
int n,v[1000002];
deque<int>pmax;
deque<int>pmin;
int nr,dim1=1,dim2=1;
long long sol;
inline void CautBin(int i)
{
    int b=0;
    int e=dim2-1;
    int stp,sfp=i-2;
    if(dim1==1)
        stp=1;
    else
        stp=pmax[dim1-2]+1;
    int sol2=0;
    int sol1=0;
    if(stp>sfp)
        return;
    bool fs1=0,fs2=0;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(pmin[m]>=stp && (m==0 || pmin[m-1]<stp))
        {
            sol1=m;
            fs1=1;
            break;
        }
        else
            if(pmin[m]<stp)
                b=m+1;
            else
                e=m-1;
    }
    b=0;
    e=dim2-1;
    while(b<=e)
    {
        int m=(b+e)/2;
        if(pmin[m]<=sfp && (m==dim2-1 || pmin[m+1]>sfp))
        {
            sol2=m;
            fs2=1;
            break;
        }
        else
            if(pmin[m]>sfp)
                e=m-1;
            else
                b=m+1;
    }
    if(fs1==1 && fs2==1)
        sol+=sol2-sol1+1;
}
int main()
{
    f>>n;
    f>>v[1];
    pmax.push_back(1);
    pmin.push_back(1);
    for(int i=2;i<=n;++i)
    {
        f>>v[i];
        while(dim1 && v[i]>v[pmax.back()])
            --dim1,pmax.pop_back();
        pmax.push_back(i);++dim1;
        while(!pmin.empty() && v[i]<v[pmin.back()])
            --dim2,pmin.pop_back();
        pmin.push_back(i);++dim2;
        if(i>=3)
            CautBin(i);
    }
    g<<sol<<'\n';
    return 0;
}

#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

ifstream fin("sum2.in");
ofstream fout("sum2.out");

const int NMAX = 100005;

int n, min_lg, max_lg;
int vec[NMAX];
long long sum[NMAX];
long long sum_max;
deque<int> dq;

int main() {
    fin >> n >> min_lg >> max_lg;
    for (int i = 1; i <= n; ++ i)
        fin >> vec[i];
    fin.close();
    sum[0] = 0;
    for (int i = 1; i <= n; ++ i)
        sum[i] = sum[i - 1] + vec[i];
    sum_max = -1000000000;
    for (int i = min_lg; i <= n; ++ i) {
        while (!dq.empty() && sum[i - min_lg] <= sum[dq.back()])
            dq.pop_back();
        dq.push_back(i - min_lg);
        if (dq.front() == i - max_lg - 1)
            dq.pop_front();
        sum_max = max(sum_max, sum[i] - sum[dq.front()]);
    }
    fout << sum_max << "\n";
    fout.close();
    return 0;
}

// segment tree sol
/*
#include<bits/stdc++.h>
using namespace std;
ifstream f("sum2.in");
ofstream g("sum2.out");
int n,small,big,val,poz,start,sfarsit,min1;
int sp[100002],aint[500002];
void build(int nod, int st, int sf)
{
    if(st==sf){
        aint[nod]=val;
        return;
    }
    int m=(st+sf)/2;
    if(poz<=m)
        build(2*nod,st,m);
    else
        build(2*nod+1,m+1,sf);
    aint[nod]=min(aint[2*nod],aint[2*nod+1]);
}
void query(int nod, int st, int dr)
{
    if(start<=st && dr<=sfarsit)
    {
        min1=min(min1,aint[nod]);
        return;
    }
    int mij=(st+dr)/2;
    if(start<=mij)
        query(2*nod,st,mij);
    if(mij<sfarsit)
        query(2*nod+1,mij+1,dr);
}
int main()
{
    f>>n>>small>>big;
    for(int i=1;i<=n;++i)
    {
        f>>sp[i];
        sp[i]+=sp[i-1];
        val=sp[i];
        poz=i;
        build(1,1,n);
    }
    int smax=sp[small];
    for(int i=small+1;i<=n;++i)
    {
        if(i<=big)
            smax=max(smax,sp[i]);
        start=max(1,i-big);
        sfarsit=i-small;
        min1=2e9;
        query(1,1,n);
        smax=max(smax,sp[i]-min1);
    }
    g<<smax;
    return 0;
}
*/

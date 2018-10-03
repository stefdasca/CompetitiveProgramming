#include <bits/stdc++.h>
using namespace std;
ifstream f("multisum.in");
ofstream g("multisum.out");
int n,tip,i,j,A[1<<17],B[1<<17],C[1<<17],D[1<<17];
pair <int,int> V[1<<10];
bool cmp(int a,int b)
{
    if(C[a]!=C[b])
        return C[a]<C[b];
    if(B[a]!=B[b])
        return B[a]<B[b];
    return D[a/B[a]]<D[b/B[b]];
}
int main()
{
    f>>n>>tip;
    for(i=0;i<n;++i)
        f>>V[i].first>>V[i].second;
    A[1]=B[1]=C[1]=1;
    for(i=1;i<=100000;++i)
        if(A[i])
            for(j=i*2;j<100000;j+=i)
                if(A[i]+1>=A[j+1])
                {
                    A[j+1]=A[i]+1;
                    B[j+1]=j/i;
                    C[j+1]=1;
                }
    int best=0;
    for(i=100000;i>0;--i)
    {
        best=max(best,A[i]);
        D[i]=-1;
        for(j=i*2;j<=100000;j+=i)
            if(A[i]>A[j])
            {
                A[j]=A[i];
                B[j]=j/i;
                C[j]=j/i;
            }
    }
    D[1]=0;
    D[2]=1;
    for(i=2;i<=best;++i)
    {
        vector<int>aux;
        for(j=1;j<=100000;++j)
            if(A[j]==i)
                aux.push_back(j);
        sort(aux.begin(),aux.end(),cmp);
        for(j=0;j<(int)aux.size();++j)
            D[aux[j]]=j;
    }
    for(j=0;j<n;++j)
    {
        int P=0,L=0,M=V[j].first;
        for(i=V[j].first;i<=V[j].second;++i)
            if(A[i]>P)
            {
                P=A[i];
                L=1;
                M=i;
            }
            else
                if(A[i]==P)
                {
                    ++L;
                    if(D[i]<D[M])
                        M=i;
                }
        if(tip==1)
            g<<P<<'\n';
        else
            if(tip==2)
                g<<L<<'\n';
            else
                g<<M<<'\n';
    }
    return 0;
}

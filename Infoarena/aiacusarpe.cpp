#include<bits/stdc++.h>
using namespace std;
ifstream f("aiacusarpe.in");
ofstream g("aiacusarpe.out");
int n,m,lmov[1002][1002],Lsir,Lmax[1000002];
char c[1000002];
int RiL(char c)
{
    if(c=='E' || c=='V')
        return 0;
    if(c=='N')
        return -1;
    return 1;
}
int RiC(char c)
{
    if(c=='N' || c=='S')
        return 0;
    if(c=='V')
        return -1;
    return 1;
}
int main()
{
    f>>n>>m>>Lsir;
    f>>c+1;
    int L=1,C=1;
    lmov[1][1]=0;
    int max1=1;
    Lmax[0]=1;
    for(int i=1;i<=Lsir;++i)
    {
        L+=RiL(c[i]);
        C+=RiC(c[i]);
        if(L==0 || L>n)
            break;
        if(C==0 || C>m)
            break;
        if(!lmov[L][C] && L+C>2)
            max1=max(max1,Lmax[i-1]+1),Lmax[i]=Lmax[i-1]+1;
        else
            max1=max(max1,min(Lmax[i-1]+1,i-lmov[L][C])),Lmax[i]=min(Lmax[i-1]+1,i-lmov[L][C]);
        lmov[L][C]=i;
      //  g<<Lmax[i]<<" ";
    }
    g<<max1;
    return 0;
}

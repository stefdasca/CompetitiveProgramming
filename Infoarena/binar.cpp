#include<bits/stdc++.h>
using namespace std;
ifstream f("binar.in");
ofstream g("binar.out");
int n,m;
char c1[2002];
bitset<2002>mat[2002];
short v[2002],place[2002];
void ranking(short v[],short sp,short ep,short l)
{
    short sz1=0,sz2=0;
    for(short i=1;i<=ep-sp+1;++i)
        if(mat[l][v[i]]==0)
            ++sz1;
        else
            ++sz2;
    if(sz1){
        short v0[sz1+2];
        sz1=0;
         for(short i=1;i<=ep-sp+1;++i)
            if(mat[l][v[i]]==0)
                v0[++sz1]=v[i];
        if(sz1==1)
            place[ep]=v0[1];
        else
            if(sz1>=2)
                if(l==n)
                    for(short i=1;i<=sz1;++i)
                        place[ep--]=v0[i];
                else
                    ranking(v0,ep-sz1+1,ep,l+1);
    }
    if(sz2)
    {
        short v1[sz2+2];
        sz2=0;
         for(short i=1;i<=ep-sp+1;++i)
            if(mat[l][v[i]]==1)
                v1[++sz2]=v[i];
        if(sz2==1)
            place[sp]=v1[1];
        else
            if(sz2>=2)
                if(l==n)
                    for(short i=1;i<=sz2;++i)
                        place[sp+sz2-i]=v1[i];
                else
                    ranking(v1,sp,sp+sz2-1,l+1);
    }
}
int main()
{
    f>>n>>m;
    for(short i=1;i<=n;++i)
    {
        f>>(c1+1);
        for(short j=1;j<=m;++j)
            mat[i][j]=c1[j]-'0';
    }
    for(short i=1;i<=m;++i)
        v[i]=i;
    ranking(v,1,m,1);
    for(short i=m;i>=1;--i)
        g<<place[i]<<" ";
    return 0;
}

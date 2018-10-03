#include <bits/stdc++.h>
using namespace std;
ifstream f("suma3.in");
ofstream g("suma3.out");
int dl[8]={-1,1,0,0,-1,1,-1,1};
int dc[8]={0,0,-1,1,1,-1,-1,1};
int n,smin=3<<29,s[33],p[33][101],v[10][10],x[33],xm[33],w[6401],e[6401];
vector <int> L[6401];
void prelsol()
{   smin=s[n];
    for(int i=1;i<=n;i++)
        xm[i]=x[i];
}
struct cmp
{   bool operator()(const int &a, const int &b) const
    {   return a>=b;}
};
void back(int i,int k)
{   w[i]=1;
    int l=(i>>3)&7,c=i&7,ss=0;
    x[k]=(i>>6);
    s[k]=s[k-1]+p[k][x[k]];
    for(int vl=k+1,j=1;j<=n;j++)
        if(!w[e[j]]){
            ss+=vl*(e[j]>>6);
            vl++;
        }
    if(s[k]+ss<smin)
    {
        v[l][c]=0;
        if(k==n)
            prelsol();
        else
            for(int r=0,sf=L[i].size();r<sf;++r)
                if(v[(L[i][r]>>3)&7][L[i][r]&7])
                    back(L[i][r],k+1);
        v[l][c]=x[k];
    }
    w[i]=0;
}
int main()
{   int a,b,i,j;
    f>>a>>b;
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            f>>v[i][j];
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            if(v[i][j])
            {
                n++;
                e[n]=(v[i][j]<<6)+(i<<3)+j;
                for(int l,c,r=0;r<8;r++)
                {
                    l=i+dl[r];
                    c=j+dc[r];
                    if(v[l][c])
                        L[e[n]].push_back((v[l][c]<<6)+(l<<3)+c);
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=100;j++)
            p[i][j]=i*j;
    sort(e+1,e+n+1,cmp());
    for(i=1;i<=n;i++)
        back(e[i],1);
    g<<smin<<'\n';
    for(i=1;i<=n;i++)
        g<<xm[i]<<' ';
    return 0;
}

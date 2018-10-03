#include<bits/stdc++.h>
using namespace std;
ifstream f("suma4.in");
ofstream g("suma4.out");
int n;
int va[70002];
int smin[70002];
int vb[70002];
int mat[101][101];
int lvl=1,pp=1,st=1;
int R=0;
void find_level(int n)
{
    R=0;
    while(n)
        n-=(R+1)*(R+1),++R;
}
void init()
{
    for(int i=1;i<=n;smin[i]=1e9,++i)
        f>>va[i];
    smin[1]=va[1];
}
void srch(int curr, int L, int C)
{
    if(smin[curr]+va[mat[L][C]]<smin[mat[L][C]])
        smin[mat[L][C]]=smin[curr]+va[mat[L][C]],vb[mat[L][C]]=curr;
    if(smin[curr]+va[mat[L+1][C]]<smin[mat[L+1][C]])
        smin[mat[L+1][C]]=smin[curr]+va[mat[L+1][C]],vb[mat[L+1][C]]=curr;
    if(smin[curr]+va[mat[L][C+1]]<smin[mat[L][C+1]])
        smin[mat[L][C+1]]=smin[curr]+va[mat[L][C+1]],vb[mat[L][C+1]]=curr;
    if(smin[curr]+va[mat[L+1][C+1]]<smin[mat[L+1][C+1]])
        smin[mat[L+1][C+1]]=smin[curr]+va[mat[L+1][C+1]],vb[mat[L+1][C+1]]=curr;
}
void solve()
{
    g<<R<<" ";
    int mins=1e9;
    int nr=0;
    int L=1,C=1;
    for(int i=1;i<=n;++i)
    {
        if(lvl==R){
            if(smin[i]<mins)
                mins=smin[i],nr=i;
        }
        else{
            if(i==st){
                int RIP=i+pp;
                for(int j=1;j<=lvl+1;++j)
                    for(int k=1;k<=lvl+1;++k)
                        mat[j][k]=RIP++;
                L=1;
                C=1;
            }
            srch(i,L,C);
            ++C;
            if(C>lvl)
                C=1,++L;
            if(L>lvl)
            {
                st+=pp;
                ++lvl;
                pp=lvl*lvl;
            }
        }
    }
    g<<mins<<'\n';
    deque<int>d;
    d.push_back(nr);
    while(vb[nr])
        d.push_front(vb[nr]),nr=vb[nr];
    for(int i=0;i<R;++i)
        g<<d[i]<<" ";
}
int main()
{
    f>>n;
    find_level(n);
    init();
    solve();
    return 0;
}

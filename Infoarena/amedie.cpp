#include<bits/stdc++.h>
using namespace std;
ifstream f("amedie.in");
ofstream g("amedie.out");
int n,m,q,mat[802][802];
bool viz[802][802];
int aib[100002];
int frq[100002];
char Lit;
int val;
void add(int nod, int val)
{
    for(;nod<=100000;nod+=nod&(-nod))
        aib[nod]+=val;
}
int Compute(int nod)
{
    int s=0;
    for(;nod;nod-=nod&(-nod))
        s+=aib[nod];
    return s;
}
int main()
{
    f>>n>>m>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            f>>mat[i][j],add(mat[i][j],1),++frq[mat[i][j]];
    int tot=n*m;
    for(int i=1;i<=q;++i)
    {
        f>>Lit;
        if(Lit=='Q')
        {
            int b=1;
            int e=100000;
            int nrm=tot/2+tot%2;
            while(b<=e)
            {
                int m=(b+e)/2;
                if(Compute(m)>=nrm && Compute(m)-frq[m]<nrm){
                    g<<m<<'\n';
                    break;
                }
                else
                    if(Compute(m)>=nrm)
                        e=m-1;
                    else
                        b=m+1;
            }
        }
        else
        {
            f>>val;
            if(Lit=='L')
                for(int j=1;j<=m;++j)
                    if(viz[val][j]==0)
                        viz[val][j]=1,frq[mat[val][j]]--,add(mat[val][j],-1),--tot;
            if(Lit=='C')
                for(int j=1;j<=n;++j)
                    if(viz[j][val]==0)
                        viz[j][val]=1,frq[mat[j][val]]--,add(mat[j][val],-1),--tot;
        }
    }
    return 0;
}

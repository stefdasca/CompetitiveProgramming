#include<bits/stdc++.h>
using namespace std;
ifstream f("dreptunghiuri3.in");
ofstream g("dreptunghiuri3.out");
struct {int x1,x2,y1,y2,val;} d[1010];
int n,m,k,i,xx1,xx2,yy1,yy2,j, maxx(1LL<<31);
long long nr;
vector <int> linii,coloane;
map <int,int> ln,cl;
set <int> l,c;
set <int> ::iterator it;
int a[4500][4500];
int main()
{
    f>>n>>m>>k;
    for(i=1;i<=k;++i)
    {
        f>>d[i].x1>>d[i].y1>>d[i].x2>>d[i].y2>>d[i].val;
        l.insert(d[i].x1),l.insert(d[i].x2),l.insert(d[i].x2+1);
        c.insert(d[i].y1),c.insert(d[i].y2),c.insert(d[i].y2+1);
    }
    l.insert(0),c.insert(0);l.insert(n+1);c.insert(m+1);
    for(it=l.begin(),i=0;it!=l.end();++it,++i)
        linii.push_back(*it),ln[*it]=i;
    for(it=c.begin(),i=0;it!=c.end();++it,++i)
        coloane.push_back(*it),cl[*it]=i;
    for(i=1;i<=k;++i)
    {
        a[ln[d[i].x1]][cl[d[i].y1]]+=d[i].val;
        a[ln[d[i].x2+1]][cl[d[i].y1]]-=d[i].val;
        a[ln[d[i].x1]][cl[d[i].y2+1]]-=d[i].val;
        a[ln[d[i].x2+1]][cl[d[i].y2+1]]+=d[i].val;
    }
    for(i=1;i<=linii.size();++i)
        for(j=1;j<=coloane.size();++j)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            if(a[i][j]>maxx)
            {
                maxx=a[i][j];
                nr=1LL*(linii[i+1]-linii[i])*(coloane[j+1]-coloane[j]);
            }
            else
                if(a[i][j]==maxx)
                    nr+=1LL*(linii[i+1]-linii[i])*(coloane[j+1]-coloane[j]);
        }
    g<<maxx<<' '<<nr;
    return 0;
}

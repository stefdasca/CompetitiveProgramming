#include<bits/stdc++.h>
using namespace std;
ifstream f("dreptunghiuri4.in");
ofstream g("dreptunghiuri4.out");
struct
{
    int x1,x2,y1,y2;
}d[1010];
int n,m,k,i,j;
long long nr;
vector <int> linii,coloane;
map <int,int> ln,cl;
set <int> l,c;
set <int> ::iterator it;
short a[3003][3003];
int main()
{
    f>>n>>k;
    for(i=1;i<=n;++i)
    {
        f>>d[i].x1>>d[i].y1>>d[i].x2>>d[i].y2;
        if(d[i].x1>d[i].x2 || (d[i].x1==d[i].x2 && d[i].y1>d[i].y2))
            swap(d[i].x1,d[i].x2),swap(d[i].y1,d[i].y2);
        l.insert(d[i].x1),l.insert(d[i].x2);
        c.insert(d[i].y1),c.insert(d[i].y2);
    }
    l.insert(0),c.insert(0);l.insert(1e9+1);c.insert(1e9+1);
    for(it=l.begin(),i=0;it!=l.end();++it,++i)
        linii.push_back(*it),ln[*it]=i;
    for(it=c.begin(),i=0;it!=c.end();++it,++i)
        coloane.push_back(*it),cl[*it]=i;
    for(i=1;i<=n;++i)
    {
        a[ln[d[i].x1]][cl[d[i].y1]]++;
        a[ln[d[i].x2]][cl[d[i].y1]]--;
        a[ln[d[i].x1]][cl[d[i].y2]]--;
        a[ln[d[i].x2]][cl[d[i].y2]]++;
    }
    for(i=0;i<=linii.size();++i)
        for(j=0;j<=coloane.size();++j)
        {
            a[i][j]+=(i>0)*a[i-1][j]+(j>0)*a[i][j-1]-(j>0 && i>0)*a[i-1][j-1];
            if(a[i][j]==k)
                nr+=1LL*(linii[i+1]-linii[i])*(coloane[j+1]-coloane[j]);
        }
    g<<nr;
    return 0;
}

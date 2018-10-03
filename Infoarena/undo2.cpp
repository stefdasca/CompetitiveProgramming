#include<bits/stdc++.h>
#define DN 200005
using namespace std;
ifstream f("undo2.in");
ofstream g("undo2.out");
int q,n,nn,v[DN];
vector<int> poz[DN];
void ups() {
  for(int i=max(nn,n); i>min(nn,n); --i)
    poz[v[i]].pop_back();
}
int main()
{
  int op,x,m;
  f>>m;
  for(int i=1;i<=m;++i)
  {
     f>>op>>x;
    if(op==1)
    {
      ups();
      v[++n]=x;
      nn=n;
      poz[x].push_back(n);
    }
    if(op==2) {
      ups();
      nn=n;
      n-=x;
    }
    if(op==3)
        n+=x;
    if(op==4)
    {
      int p=upper_bound(poz[x].begin(), poz[x].end(),n)-poz[x].begin();
      g<<p<<'\n';
    }
  }
  return 0;
}

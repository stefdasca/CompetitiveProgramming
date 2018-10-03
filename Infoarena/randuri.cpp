#include<bits/stdc++.h>
using namespace std;
ifstream f("randuri.in");
ofstream g("randuri.out");
vector<int>nrs;
int q=1,t[140][140];
char c[130];
struct sr{
    char c[131];
   int l;
};
sr v[101];
int main(){
      while(f.getline(v[q].c,129))
     {
         nrs.push_back(q);
         v[q].l=strlen(v[q].c);
         ++q;
     }
    int nre=0;
    bool ok=1;
    --q;
   while(ok){
        ok=0;
       for(int i=0;i+2<q;++i)
      {
          for(int j=0;j<v[nrs[i]].l;++j)
               for(int k=0;k<v[nrs[i+2]].l;k++)
                  if(v[nrs[i]].c[j]==v[nrs[i+2]].c[k])
                      t[j][k]=t[j-1][k-1]+1;
                  else
                     t[j][k]=max(t[j-1][k], t[j][k-1]);
          if(t[v[nrs[i]].l-1][v[nrs[i+2]].l-1]>6)
          {
              nrs.erase(nrs.begin()+i+1);
              --i;
              ok=1;
              nre++;
              --q;
          }
     }
   }
     g<<nre;
     return 0;
}

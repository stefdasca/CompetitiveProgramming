#include<bits/stdc++.h>
using namespace std;
ifstream f("staropramen.in");
ofstream g("staropramen.out");
int t,n,nr9,w,s;
char x,y;
int main()
{
  f>>t;
  for(;t;--t)
  {
    f>>n;
    nr9=0;
    w=-1;
    for(int i=0;i<n;++i)
    {
         f>>x>>y;
         s=x+y-2*'0';
         if(s==9)
            nr9++;
         else
          if(s>9)
          {
            if(w==-1)
                g<<1;
            else
             g<<w+1;
            while(nr9){
                g<<0;nr9--;
            }
            w=s%10;
          }
          else
          {
              if(w!=-1)
                g<<w;
              while(nr9){
                  g<<9;nr9--;
              }
              w=s;
          }
    }
    g<<w;
    while(nr9){
        g<<9;nr9--;
    }
    g<<'\n';
  }
  return 0;
}

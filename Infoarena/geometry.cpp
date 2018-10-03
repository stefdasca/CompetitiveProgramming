#include<bits/stdc++.h>
using namespace std;
ifstream f("geometry.in");
ofstream g("geometry.out");
struct element
{
   long long  x1,y1,x2,y2;
};
element v[10000];
int verificare(int i,int j)
{
   int ok=0,a1,a2,b1,b2,c1,c2;
   a1=v[i].y2-v[i].y1;
   b1=v[i].x2*(-1)+v[i].x1;
   c1=v[i].y1*v[i].x2-v[i].y2*v[i].x1;
   a2=v[j].y2-v[j].y1;
   b2=v[j].x2*(-1)+v[j].x1;
   c2=v[j].y1*v[j].x2-v[j].y2*v[j].x1;
   if((a1*v[j].x1+b1*v[j].y1+c1)*(a1*v[j].x2+b1*v[j].y2+c1)<=0)
      if((a2*v[i].x1+b2*v[i].y1+c2)*(a2*v[i].x2+b2*v[i].y2+c2)<=0)
         ok=1;
   return ok;
}
int conditie1(int i,int j)
{
   float n1,n2;
   n1=(float)(v[i].y2-v[i].y1)/(v[i].x2-v[i].x1);
   n2=(float)(v[j].y2-v[j].y1)/(v[j].x2-v[j].x1);
   if(n1!=n2)
      return 1;
   return 0;
}
long long n,i,j,nr=0;
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
      f>>v[i].x1>>v[i].y1>>v[i].x2>>v[i].y2;
   for(i=1;i<n;i++)
      for(j=i+1;j<=n;j++)
         if(conditie1(i,j) && verificare(i,j))
            nr++;
   g<<nr;
   return 0;
}

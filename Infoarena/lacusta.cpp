#include <cstdio>
using namespace std;
#define M 251
int main()
{
  FILE *fi,*fo;
  unsigned short a[M][M],b[M][M],m,n,i,j,min1,min2,jmin;
  fi=fopen("lacusta.in", "rt");
  fscanf(fi,"%hu %hu", &m, &n);
  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      fscanf(fi,"%hu",&a[i][j]);
  fclose(fi);
  b[1][0]=32000;
  for(i=1; i<n; i++)
    b[1][i]=a[0][0]+a[0][i]+a[1][i];
  for(i=1; i<m-1; i++)
    {
      if(b[i][0]<=b[i][1])
        {
          min1=b[i][0];
          min2=b[i][1];
          jmin=0;
        }
      else
        {
          min1=b[i][1];
          min2=b[i][0];
          jmin=1;
        }
      for(j=2; j<n; j++)
        if(b[i][j]<min1)
          {
            min2=min1;
            min1=b[i][j];
            jmin=j;
          }
		else
          if(b[i][j]<min2)
            min2=b[i][j];
      for(j=0; j<n; j++)
        if(j!=jmin)
          b[i+1][j]=min1+a[i][j]+a[i+1][j];
		else
          b[i+1][j]=a[i][j]+a[i+1][j]+min2;
    }
  min1=b[m-1][0];
  for (j=1; j<n; j++)
    if(b[m-1][j]<min1) min1=b[m-1][j];
  fo=fopen("lacusta.out", "wt");
  fprintf(fo,"%hu\n", min1+a[m-1][n-1]);
  fclose(fo);
  return 0;
}

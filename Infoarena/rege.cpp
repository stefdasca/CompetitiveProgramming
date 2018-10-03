#include <fstream>
using namespace std;
int a[1001][1001],m,n,s;
ifstream f("rege.in");
ofstream g("rege.out");
void calc(int l,int c)
{
	int l1,c1;
	int dx[8]={-1,-1,-1,0,0,1,1,1};
	int dy[8]={-1,0,1,-1,1,-1,0,1};
	if (l<=0 || l>m || c<=0 || c>n)
		return;
	for (int i=0;i<8;i++)
	{
		l1=l+dx[i];
		c1=c+dy[i];
		if (l1>0 && l1<=m && c1>0 && c1<=n && a[l1][c1]*s>0)
			a[l][c]=(a[l][c]+s*a[l1][c1]) % 666013;
	}
	a[l][c]=a[l][c]*(-s);
}
int main()
{
    int l1,l2,c1,c2,max1,i,j;
    f>>m>>n;
	f>>l1>>c1;
	f>>l2>>c2;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			a[i][j]=0;
	a[l1][c1]=1;
	if (l2>l1)
		max1=l2-l1;
	else
		max1=l1-l2;

	if (c2>c1)
	{
		if (c2-c1>max1)
			max1=c2-c1;
	}
	else
		if (c1-c2>max1)
			max1=c1-c2;
	s=1;
	for (int p=1;p<=max1;p++)
	{
		for (j=c1-p;j<=c1+p;j++)
		{
			calc(l1-p,j);
			calc(l1+p,j);
		}
		for (i=l1-p+1;i<=l1+p-1;i++)
		{
			calc(i,c1-p);
			calc(i,c1+p);
		}
		s=s*(-1);
	}
	if (a[l2][c2]>0)
		g<<max(a[l2][c2],-a[l2][c2])<<"\n";
	else
		g<<(-a[l2][c2])<<"\n";
}

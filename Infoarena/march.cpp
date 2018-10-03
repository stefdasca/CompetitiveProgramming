#include<bits/stdc++.h>
using namespace std;
ifstream f("march.in");
ofstream g("march.out");
int c,n,i,j;
unsigned long long k,v[1002];
int v1[25],v2[25];
int qq[25][25];
int lev(int n,int m)
{
    for(i=0;i<=n;i++) qq[i][0]=i;
	for(i=0;i<=m;i++) qq[0][i]=i;
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
			if(v1[i]==v2[j])
				qq[i][j]=qq[i-1][j-1];
			else
				qq[i][j]=min(qq[i-1][j]+1,       // deletion
							  min(qq[i][j-1]+1,   // insertion
								  qq[i-1][j-1]+1  // substitution
								  )
							  );
	return qq[n][m];
}
void cerinta1()
{
    int sol=0;
    while(v[1])
    {
        ++sol;
        v1[sol]=v[1]%10;
        v[1]/=10;
    }
    int l1=sol;
    for(int i=2;i<=n;++i)
    {
        int l2=0;
        while(v[i])
        {
            ++l2;
            v2[l2]=v[i]%10;
            v[i]/=10;
        }
        sol+=lev(l1,l2);
        for(int j=1;j<=l2;++j)
            v1[j]=v2[j];
        l1=l2;
    }
    g<<sol;
}
void cerinta2()
{
    int sol=0;
    for(int i=1;i<=n;++i){
        unsigned long long s=0;
        for(int j=i;j<=n;++j)
        {
            s+=v[j];
            if(s>=k)
            {
                sol=sol+n-j+1;
                break;
            }
        }
    }
    g<<sol;
}
void cerinta3()
{
    int sol=n;
    for(int i=1;i<=n;++i){
        unsigned long long s=0;
        for(int j=i;j<=n;++j)
        {
            s+=v[j];
            if(s>=k)
            {
                sol=min(sol,j-i+1);
                break;
            }
        }
    }
    g<<sol;
}
int main()
{
    f>>c;
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    if(c==1)
        cerinta1();
    if(c==2)
        cerinta2();
    if(c==3)
        cerinta3();
    return 0;
}

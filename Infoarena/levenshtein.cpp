#include<bits/stdc++.h>
using namespace std;
char c1[102],c2[102];
int a,b;
int qq[102][102];
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
int main()
{
    f>>c1;
    f>>c2;
    a=strlen(c1);
    b=strlen(c2);
    cout<<lev(a,b);
    return 0;
}

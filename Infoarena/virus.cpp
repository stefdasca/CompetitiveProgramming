#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int l,n,k;
char x[100002],x2[1002];
unsigned int v[100002];
int main()
{
    freopen("virus.in","r",stdin);
    freopen("virus.out","w",stdout);
    scanf("%d%d",&l,&n);
    scanf("%s",&x);
    for(int i=0;i<l;++i)
        v[i+1]=(x[i]-'0')+1;
    for(;n;--n)
    {
        scanf("%d",&k);
        scanf("%s",&x2);
        unsigned int hsh=0,p3=1,hash2=0;
        for(int i=0;i<k;++i)
        {
            hsh=hsh*3+(x2[i]-'0')+1;
            p3*=3;
        }
        int sol=0;
        for(int j=1;j<k;++j)
            hash2=hash2*3+v[j];
        for(int j=k;j<=l;j++)
        {
            hash2=hash2*3+v[j]-p3*v[j-k];
            if(hash2==hsh)
                sol++;
        }
        printf("%d\n",sol);
    }
    return 0;
}

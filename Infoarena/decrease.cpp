#include<cstdio>
using namespace std;
int n,v[5002];
bool q[33000];
int lastnum,lastways;
unsigned int nrsmax[5002],lsmax[5002];
int main()
{
    freopen("decrease.in","r",stdin);
    freopen("decrease.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&v[i]);
    for(int i=1;i<=n+1;++i){
        lsmax[i]=1;
        nrsmax[i]=1;
        lastnum=-1;
        for(int j=1;j<i;++j)
            if(v[i]<v[j])
                if(lsmax[j]+1>lsmax[i])
                    lsmax[i]=lsmax[j]+1,nrsmax[i]=nrsmax[j],lastnum=v[j],lastways=nrsmax[i];
                else
                    if(lsmax[j]+1==lsmax[i]){
                        if(v[j]!=lastnum)
                            nrsmax[i]+=nrsmax[j];
                        else
                            nrsmax[i]=nrsmax[i]+nrsmax[j]-lastways;
                        lastnum=v[j];
                        lastways=nrsmax[j];
                    }
    }
    printf("%u %u",lsmax[n+1]-1,nrsmax[n+1]);
    return 0;
}

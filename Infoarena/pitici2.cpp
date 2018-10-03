#include<cstdio>
#include<cmath>
#define eps 1e-3
using namespace std;
int n,ar[5];
double val[5];
bool zz[5];
struct points
{
    int L,C;
};
points v[5002];
int main()
{
    freopen("pitici2.in","r",stdin);
    freopen("pitici2.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",&v[i].L,&v[i].C);
    for(int i=1;i<=n;++i)
    {
        int len=0;
        ar[1]=0;
        ar[2]=0;
        ar[3]=0;
        for(int j=1;j<=n;++j)
            if(j!=i){
                bool ok=0,rr=0;
                double pd=(v[j].C-v[i].C+0.0)/(v[j].L-v[i].L+0.0);
                if(v[j].L==v[i].L)
                    rr=1;
                for(int k=1;k<=len;++k)
                    if(rr || zz[k]){
                        if(rr && zz[k]){
                            ok=1;
                            break;
                        }
                    }
                    else
                        if(abs(pd-val[k])<=eps)
                        {
                             ok=1;
                             break;
                        }
                if(!ok){
                    if(len==3)
                        break;
                    ar[++len]=j;
                    zz[len]=rr;
                    val[len]=pd+0.0;
                }
            }
        if(len<=3)
        {
            printf("Piticii se vor salva.\n");
            printf("%d %d\n",i,ar[1]);
            if(ar[2]==0)
                printf("%d %d\n",i,ar[1]);
            else
                printf("%d %d\n",i,ar[2]);
            if(ar[3]==0)
                printf("%d %d\n",i,ar[1]);
            else
                printf("%d %d\n",i,ar[3]);
            return 0;
        }
    }
    printf("Piticii sunt in pericol.\n");
    return 0;
}

#include<cstdio>
#include<bitset>
using namespace std;
int n,m,n1,m1;
bitset<100002>a;
int main()
{
    freopen("impartire.in","r",stdin);
    freopen("impartire.out","w",stdout);
    scanf("%d%d",&n,&m);
    printf("0.");
    n1=n*10;
    while(n)
    {
        if(a[n]==1)
            break;
        else
            a[n]=1;
        n*=10;
        n%=m;
    }
    if(n==0)
        while(n1!=0)
        {
            printf("%d",n1/m);
            n1%=m;
            n1*=10;
        }
    else
    {
        int sp=n*10;
        while(n1!=sp)
        {
            printf("%d",n1/m);
            n1%=m;
            n1*=10;
        }
        printf("(");
        int k=0;
        while(k<2)
        {
            if(n1==sp){
                ++k;
                if(k==2)
                    break;
            }
            printf("%d",n1/m);
            n1%=m;
            n1*=10;
        }
        printf(")");
    }
    return 0;
}

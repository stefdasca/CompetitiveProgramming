#include<cstdio>
char a[210],b[210],q;
short la,lb,lc,n,nr,i,j;
int main()
{
    freopen("nunta.in","r",stdin);
    freopen("nunta.out","w",stdout);
    scanf("%hd",&n);
    if(n==1)
        printf("1");
    else
        if(n==2)
            printf("2");
        else
        {
            a[1]=1;
            b[1]=2;
            la=1;
            lb=1;
            for(i=3;i<=n;++i){
                for(j=1;j<=lb;++j)
                {
                    nr=b[j];
                    if(j<=la)
                        b[j]+=a[j];
                    a[j]=nr;
                }
                la=lb;
                for(j=1;j<=lb;++j)
                    if(b[j]>9)
                    {
                        b[j+1]++;
                        b[j]-=10;
                        if(j==lb)
                            ++lb;
                    }
            }
            for(i=lb;i>=1;--i){
                q=b[i]+'0';
                printf("%c",q);
            }
        }
    return 0;
}

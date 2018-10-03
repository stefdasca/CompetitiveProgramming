#include<cstdio>
using namespace std;
int n,x1,x2;
long long p5[30],p3[30],s1,s2;
short q[30],q1[30];
int main()
{
    freopen("puteri35.in","r",stdin);
    freopen("puteri35.out","w",stdout);
    scanf("%d",&n);
    p3[0]=1,p5[0]=1;
    for(int i=1;i<=21;++i)
        p5[i]=p5[i-1]*5,p3[i]=p3[i-1]*3;
    q[0]=1,q1[0]=1;
    x1=0;
    x2=0;
    s1=s2=1;
    while(x1<n)
    {
        if(s1<=s2)
        {
            printf("%lld\n",s1);
            q[0]++;
            if(q[0]==1)
                s1++;
            int z=0;
            while(q[z]==2)
            {
                s1-=p3[z];
                q[z]=0;
                q[z+1]++;
                ++z;
                if(q[z]==1)
                    s1+=p3[z];
            }
            ++x1;
        }
        else
        {
            printf("%lld\n",s2);
            q1[0]++;
            int z=0;
            if(q1[0]==1)
                s2++;
            while(q1[z]==2)
            {
                s2-=p5[z];
                q1[z]=0;
                q1[z+1]++;
                ++z;
                if(q1[z]==1)
                    s2+=p5[z];
            }
            ++x2;
        }
    }
    while(x2<n)
    {
        printf("%lld\n",s2);
        q1[0]++;
        int z=0;
        if(q1[0]==1)
            s2++;
        while(q1[z]==2)
        {
            s2-=p5[z];
            q1[z]=0;
            q1[z+1]++;
            ++z;
            if(q1[z]==1)
                s2+=p5[z];
        }
        ++x2;
    }
    return 0;
}

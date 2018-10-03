#include<fstream>
#include<cstring>
#include<deque>
using namespace std;
ifstream f("lant.in");
ofstream g("lant.out");
int k,n,sol;
int dp[202];
bool wlast[202];
struct words
{
    char c[32];
};
words v[202];
char c[1002],*p;
char sep[]=",:;.!? -";
int d[35][35];
int simi(int a, int b)
{
    memset(d,0,sizeof(d));
    int n=strlen(v[a].c);
    int m=strlen(v[b].c);
    for(int i=0;i<=n;++i)
        d[i][m]=n-i;
    for(int i=0;i<=m;++i)
        d[n][i]=m-i;
    for(int i=n-1;i>=0;--i)
        for(int j=m-1;j>=0;--j){
            if(v[a].c[i]==v[b].c[j])
                d[i][j]=min(d[i][j+1]+1,d[i+1][j+1]);
            else
                d[i][j]=d[i][j+1]+1;
            d[i][j]=min(d[i][j],d[i+1][j]+1);
        }
    return d[0][0];
}
int main()
{
    f>>k;
    while(f>>c)
    {
        p=c;
        strtok(p,sep);
        while(p)
        {
            bool gut=1;
            for(int j=0;j<strlen(p);++j)
                if(!(p[j]>='a' && p[j]<='z'))
                    gut=0;
            for(int j=1;j<=n;++j)
                if(strcmp(p,v[j].c)==0){
                    gut=0;
                    break;
                }
            if(gut)
                strcpy(v[++n].c,p);
            p=strtok(NULL,sep);
        }
    }
    dp[n]=1;
    for(int i=n-1;i>=1;--i){
        for(int j=i+1;j<=n;++j)
            if(simi(i,j)<=k)
                dp[i]+=dp[j];
        dp[i]=max(1,dp[i]);
    }
    g<<dp[1];
    return 0;
}

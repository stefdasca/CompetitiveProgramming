#include<bits/stdc++.h>
using namespace std;
ifstream f("movedel.in");
ofstream g("movedel.out");
char c1[2002],c2[2002];
int n,m,val;
long long sum=2;
bool nrp[500002];
bool mrq[2002];
void sieve()
{
    for(int i=4;i<=500000;i+=2)
        nrp[i]=1;
    int con=1;
    mrq[2]=1;
    for(int j=3;con<n;j+=2)
        if(!nrp[j])
        {
            sum+=j;
            if(mrq[sum%n]==0){
                ++con,mrq[sum%n]=1;
                if(con==n)
                    val=sum%n;
            }
            for(int k=j+j;k<=500000;k+=j)
                nrp[k]=1;
        }
}
int main()
{
    f>>n>>m;
    sieve();
    for(int i=0;i<n;++i)
        c1[i]='b';
    c1[val]='a';
    g<<c1<<'\n';
    g<<'a';
    for(int i=2;i<=n;++i)
        g<<'c';
}

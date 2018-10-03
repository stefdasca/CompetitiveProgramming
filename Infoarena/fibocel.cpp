#include<bits/stdc++.h>
using namespace std;
ifstream f("fibocel.in");
ofstream g("fibocel.out");
int q;
long long a,b;
bool gut[57];
int Huge[102];
long long sols[56][56];
void combi()
{
    for(int i=0;i<=52;++i)
        sols[i][0]=sols[i][i]=1;
    for(int i=1;i<=52;++i)
        for(int j=1;j<i;++j)
            sols[i][j]=sols[i-1][j-1]+sols[i-1][j];
}
long long fibi(long long nr)
{
    long long sol=0;
    deque<int>biti;
    while(nr)
    {
        biti.push_front(nr&1);
        nr>>=1;
    }
    int nr1=0;
    for(int i=0;i<biti.size();++i)
    {
        if(biti[i])
        {
            int pos=biti.size()-i-1;
            for(int j=0;j<=pos;++j)
                if(gut[nr1+j])
                    sol+=sols[pos][j];
        }
        nr1+=(biti[i]==1);
    }
    return sol+gut[nr1];
}
int main()
{
    f>>q;
    gut[1]=gut[2]=gut[3]=gut[5]=1;
    gut[8]=gut[13]=gut[21]=gut[34]=gut[55]=1;
    combi();
    for(;q;--q)
    {
        f>>a>>b;
        g<<fibi(b)-fibi(a-1)<<'\n';
    }
    return 0;
}

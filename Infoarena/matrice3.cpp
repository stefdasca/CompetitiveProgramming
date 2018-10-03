#include<bits/stdc++.h>
using namespace std;
ifstream f("matrice3.in");
ofstream g("matrice3.out");
int n,m,q,i;
char cc[302];
bool Rose[252][252];
char RMQ[10][10][252][252];
int LG[252];
int a, b, c, d;
void read_the_data()
{
    f>>n>>m>>q;
    for(int i=1;i<=n;++i)
    {
        f>>cc+1;
        for(int j=1;j<=m;++j)
            Rose[i][j]=(cc[j]-'0');
    }
}
void find_best_rose()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(Rose[i][j]==0)
                RMQ[0][0][i][j]=1+min(RMQ[0][0][i-1][j],min(RMQ[0][0][i-1][j-1],RMQ[0][0][i][j-1]));
}
void rose_mustembrace_quality() // RMQ scris smechereste
{
    for( i = 2; i <= 251; i ++ )
       LG[i] = LG[i/2]+1;
    for(int l=1;l<8;++l)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                RMQ[l][0][i][j]=max(RMQ[l-1][0][i][j],RMQ[l-1][0][max(i-(1<<(l-1)),0)][j]);
                RMQ[0][l][i][j]=max(RMQ[0][l-1][i][j],RMQ[0][l-1][i][max(j-(1<<(l-1)),0)]);
            }

    for(int l=1;l<8;++l)
        for(int c=1;c<8;++c)
            for(int i=1<<(l-1);i<=n;++i)
                for(int j=1;j<=m;++j)
                    RMQ[l][c][i][j]=max(RMQ[l-1][c][i][j],RMQ[l-1][c][i-(1<<(l-1))][j]);
}
int check(int a,int b,int A,int B)
{
    int p=LG[A-a+1],P=LG[B-b+1];
    return max(max(RMQ[p][P][A][B],RMQ[p][P][a+(1<<p)-1][B]),max(RMQ[p][P][A][b+(1<<P)-1],RMQ[p][P][a+(1<<p)-1][b+(1<<P)-1]));
}
void ask_the_rose()
{
    while(q--)
    {
        f>>a>>b>>c>>d;
        int sol_max=min(c-a+1,d-b+1),sol=0;
        for(int step=1<<LG[sol_max];step;step>>=1)
            if(sol+step<=sol_max)
                if(sol+step<=check(a+sol+step-1,b+sol+step-1,c,d)) sol+=step;
        g<<sol<<'\n';
    }
}
int main()
{
    read_the_data();
    find_best_rose();
    rose_mustembrace_quality();
    ask_the_rose();
    return 0;
}

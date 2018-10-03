#include<bits/stdc++.h>
using namespace std;
ifstream f("mostenire2.in");
ofstream g("mostenire2.out");
int m[102][1002];
bool st[102][1002];
char c[1002];
int L,C;
int sol;
int getSum(int i1, int j1, int i2, int j2) {
    return m[i2][j2] - m[i2][j1-1] - m[i1-1][j2] + m[i1-1][j1-1];
}
int main()
{
    f>>L>>C;
    for(int i=1;i<=L;++i)
    {
        f>>(c+1);
        for(int j=1;j<=C;++j)
            st[i][j]=(c[j]-'0');
    }
    for(int i=1;i<=L;++i)
        for(int j=1;j<=C;++j)
            m[i][j]=m[i-1][j]+m[i][j-1]-m[i-1][j-1]+st[i][j];
    for(int i=1;i<=L-2;++i)
        for(int j=i+2;j<=L;++j)
        {
            int lines = 0;
            int cons = 0;
            int h = j-i+1;
            for (int q = 1; q< C+1; ++q) {
                if (st[i][q] != 1 || st[j][q] !=1) {
                    lines = 0;
                    cons = 0;
                    continue;
                }
                if (getSum(i, q, j, q) == h){
                    cons++;
                    sol += lines;
                }
                else{
                    lines += cons;
                    cons = 0;
                }
            }
        }
    g<<sol<<'\n';
    return 0;
}

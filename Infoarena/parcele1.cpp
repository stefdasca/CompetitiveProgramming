/// #bettercoderthanshebeautiful
/// 800th problem
/// special edition
/*
Roses are red
Violets are blue
I loved her
But she didn't love me
*/
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("parcele1.in");
ofstream g("parcele1.out");
int D[32][32],S[32][32],P[32][32],N,K,M;
int abs(int x)
{
    return max(x,-x);
}
int sum(int x1, int y1, int x2, int y2)
{
    return S[x2][y2]-S[x1-1][y2]-S[x2][y1-1]+S[x1-1][y1-1];
}
int main () {
    f>>N>>M>>K;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
        {
            f>>S[i][j];
            S[i][j]+=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
        }
    memset(D,0x3f3f3f3f,sizeof(D));
    for (int i = 1; i <= N; i ++)
    for (int j = 1; j  < M; j ++)
        if (D[1][i] > abs(sum(1, 1, i, j) - sum(1, j+1, i, M)))
        {
            D[1][i] = abs(sum(1, 1, i, j) - sum(1, j+1, i, M));
            P[1][i] = 1;
        }
        else
            if (D[1][i] == abs(sum(1, 1, i, j) - sum(1, j+1, i, M)))
                P[1][i] ++;
    for (int k = 2; k <= K; k ++)
    for (int i = k; i <= N; i ++)
        for (int l = i; l >= k; l --)
        for (int j = 1; j  < M; j ++)
            if (D[k][i] > D[k-1][l-1] + abs(sum(l, 1, i, j) - sum(l, j+1, i, M)))
            {
                D[k][i] = D[k-1][l-1] + abs(sum(l, 1, i, j) - sum(l, j+1, i, M));
                P[k][i] = P[k-1][l-1];
            }
            else
                if (D[k][i] == D[k-1][l-1] + abs(sum(l, 1, i, j) - sum(l, j+1, i, M)))
                    P[k][i] += P[k-1][l-1];
    g<<D[K][N]<<'\n'<<P[K][N]<<'\n';
    return 0;
}

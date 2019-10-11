// https://www.infoarena.ro/problema/gauss

#include<bits/stdc++.h>
#define eps 0.0000001
using namespace std;
ifstream f("gauss.in");
ofstream g("gauss.out");
int n, m;
double A[310][310];
double X[310];
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m+1; ++j)
            f >> A[i][j];
    int i = 1, j = 1, k;
    double aux;
    while(i <= n && j <= m)
    {
        for(k = i; k <= n; ++k)
            if(A[k][j]<-eps || A[k][j]>eps)
                break;
        if(k == n+1)
        {
            ++j;
            continue;
        }
        if(k != i)
            for(int l = 1; l <= m+1; ++l)
            {
                aux = A[i][l];
                A[i][l] = A[k][l];
                A[k][l] = aux;
            }
        for(int l = j+1; l <= m+1; ++l)
            A[i][l] = A[i][l] / A[i][j];
        A[i][j] = 1;
        for(int u = i+1; u <= n; ++u)
        {
            for(int l = j+1; l <= m+1; ++l)
                A[u][l] -= A[u][j] * A[i][l];
            A[u][j] = 0;
        }
        ++i; ++j;
    }
    for(int i = n; i>0; --i)
        for(int j = 1; j <= m+1; ++j)
            if(A[i][j]>eps || A[i][j]<-eps)
            {
                if(j == m+1)
                {
                    g << "Imposibil\n";
                    return 0;
                }
                X[j] = A[i][m+1];
                for(int k = j+1; k <= m; ++k)
                    X[j] -= X[k] * A[i][k];
                break;
            }
    for(int i = 1; i <= m; ++i)
        g << fixed << setprecision(10) << X[i] << " ";
    return 0;
}

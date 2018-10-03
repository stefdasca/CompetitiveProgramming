#include<fstream>
using namespace std;
ifstream in("plantatie.in");
ofstream out("plantatie.out");
int n,m,mat[10][501][501],p[10],aux[501],i,j,maxim,k,h,a,b,alfa;
void prelc()
{
    in >> n >> m;
    for( i = 1; i <= n; i ++ )
        for ( j = 1; j <= n; j ++ )
            in >> mat[0][i][j];
    p[0] = 1;
    for( i = 1; i <= 9; i ++ )
        p[i] = p[i-1]*2;
    for( i = 2; i <= n; i ++ )
        aux[i] = aux[i/2]+1;
}
void rmq()
{
    for( k = 1; k <= 8; k ++ )
        for( i = 1; i <= n-p[k]+1; i ++ )
            for( j = 1; j <= n-p[k]+1; j ++ )
                mat[k][i][j] = max( max(mat[k-1][i][j], mat[k-1][i+p[k-1]][j]), max(mat[k-1][i][j + p[k-1]], mat[k-1][i+p[k-1]][j+p[k-1]]));
}
void q()
{
    for( h = 1; h <= m; h ++ ){
        in>>a>>b>>k;
        alfa=aux[k];
        maxim=max(max(mat[alfa][a][b],mat[alfa][a][b+k-p[alfa]]),max(mat[alfa][a+k-p[alfa]][b],mat[alfa][a+k-p[alfa]][b+k-p[alfa]]));
        out<<maxim<<'\n';
    }
}
int main(){
    prelc();
    rmq();
    q();
    return 0;
}

#include<fstream>
using namespace std;
ifstream f("progresii.in");
ofstream g("progresii.out");
int n, m, v[100005], sol[100005];
long long k, l, nr;
int main(){
    f >> n >> m >> k >> l;
    for( int i = 1; i <= n; i++ ){
        f >> v[i];
        nr += (l- v[i] ) / m + 1;
        sol[i] = m;
    }
    if(nr>k){
        g << "-1";
        return 0;
    }
    for( int i = 1; i <= n; i++ ){
        nr=nr-( l - v[i]) / m -1;
        sol[i] = ( l - v[i] ) / ( k - nr ) + 1;
        nr =nr+( l - v[i] ) / sol[i] + 1;
        g<<sol[i]<<'\n';
    }
    return 0;
}

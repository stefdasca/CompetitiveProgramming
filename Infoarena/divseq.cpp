#include<bits/stdc++.h>
using namespace std;
ifstream f("divseq.in");
ofstream g("divseq.out");
int N, K, F[260000];
long long V[260000], W[260000], answer;
int find_val( long long val ) {
    for( int i = 1; i <= K; i ++ )
        if( W[i] == val )
            return i;
    return K + 1;
}
bool wrong_val( long long val ) {
    for( int i = 1; i <= K; i ++ )
        if( val >= W[i] ){
            if( val % W[i] != 0 )
                return 1;
        }
        else{
            if( W[i] % val != 0 )
                return 1;
        }
    return 0;
}
int main() {
    f>>N;
    for( int i = 1; i <= N; i ++ )
       f>>V[i];
    for( int i = 1, j = 1; j <= N; j ++ ) {
        int pos = find_val( V[j] );
        W[pos] = V[j];
        F[pos] ++;
        K = max( K, pos );
        while( wrong_val( V[j] ) ) {
            int pos2 = find_val( V[i] );
            F[pos2] --;
            if( F[pos2] == 0 ) {
                swap( W[K], W[pos2] );
                swap( F[K], F[pos2] );
                K --;
            }
            i ++;
        }
        answer += j - i + 1;
    }
    g<<answer;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("critice.in");
ofstream g("critice.out");
int n, m, viz[1005], C[1005][1005], F[1005][1005], minim, T[1005];
vector<int> v[1005], sol;
pair<int,int> p[10005];
queue<int> q;
int bfs( int S ){
    memset(T, 0, sizeof(T));
    memset(viz, 0, sizeof(viz));
    q.push( S );
    viz[S] = 1;
    while( !q.empty() ){
        int nod = q.front();
        q.pop();
        if( nod == n )
            continue;
        for( int i = 0; i < v[nod].size(); i++ ){
            int vecin = v[nod][i];
            if( viz[vecin] == 0 && C[nod][vecin] > F[nod][vecin] ){
                viz[vecin] = 1;
                T[vecin] = nod;
                q.push( vecin );
            }
        }
    }
    return viz[n];
}
void dfs( int nod ){
    viz[nod] = 1;
    for( int i = 0; i < v[nod].size(); i++ ){
        int vecin = v[nod][i];
        if( viz[vecin] == 0 && C[nod][vecin] > F[nod][vecin] )
            dfs( vecin );
    }
}
int main(){
    f >> n >> m;
    for( int i = 1; i <= m; i++ ){
        int c;
        f>> p[i].first >> p[i].second >> c;
        v[ p[i].first ].push_back( p[i].second );
        v[ p[i].second ].push_back( p[i].first );
        C[ p[i].first ][ p[i].second ] = C[ p[i].second ][ p[i].first ] = c;
    }
    while( bfs( 1 ) == 1 ){
        for( int i = 0; i < v[n].size(); i++ ){
            int nod = v[n][i];
            int minim = C[nod][n] - F[nod][n];
            for( ; nod != 1 && minim != 0; nod = T[nod] )
                minim = min( minim, C[ T[nod] ][nod] - F[ T[nod] ][nod] );
            nod = v[n][i];
            F[nod][n] += minim;
            F[n][nod] -= minim;
            for( ; nod != 1 && minim != 0; nod = T[nod] ){
                F[ T[nod] ][nod] += minim;
                F[nod][ T[nod] ] -= minim;
            }
        }
    }
    memset( viz, 0, sizeof(viz) );
    dfs( 1 );
    for( int i = 1; i <= m; i++ ){
        if( viz[ p[i].first ] != viz[ p[i].second ] )
            sol.push_back( i );
    }
    g << (int)sol.size() << "\n";
    for( int i = 0; i < sol.size(); i++ )
       g<< sol[i] << "\n";
    return 0;
}

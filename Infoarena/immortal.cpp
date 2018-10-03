#include<fstream>
#include<vector>
using namespace std;
ifstream fin("immortal.in");
ofstream fout("immortal.out");
int N, M, K, A[25][25], Is_not[25];
bool ok = false;
pair<int,int> Im[20];
vector< pair<int,int> > S;
void solve( int k ){
    if( ok == true )
        return;
    if( k == K ){
        ok = true;
        for( int i = 0; i < S.size(); i += 2 )
            fout << S[i].first << " " << S[i].second << " " << S[i + 1].first << " " << S[i + 1].second << "\n";
        return;
    }
    for( int p = 1; p <= K && ok == false; p++ ){
        if( Is_not[p] == 1 )
            continue;
        int i = Im[p].first;
        int j = Im[p].second;
        S.push_back( { i, j } );
        if( ok == false && i + 2 <= N && A[i + 1][j] != 0 && A[i + 2][j] == 0 ){
            int nr = A[i + 1][j];
            Is_not[nr] = 1;  A[i + 1][j] = 0;  A[i + 2][j] = p;  A[i][j] = 0;
            pair<int,int> new_pos = { i + 2, j };  S.push_back( new_pos );  Im[p] = new_pos;
            solve( k + 1 );
            Is_not[nr] = 0;  A[i + 1][j] = nr;  A[i + 2][j] = 0;  A[i][j] = p;
            S.pop_back(); Im[p] = {i, j};
        }
        if( ok == false && i - 2 >= 1 && A[i - 1][j] != 0 && A[i - 2][j] == 0 ){
            int nr = A[i - 1][j];
            Is_not[nr] = 1;  A[i - 1][j] = 0;   A[i - 2][j] = p;  A[i][j] = 0;
            pair<int,int> new_pos = { i - 2, j };  S.push_back( new_pos );  Im[p] = new_pos;
            solve( k + 1 );
            Is_not[nr] = 0;  A[i - 1][j] = nr;  A[i - 2][j] = 0;  A[i][j] = p;
            S.pop_back(); Im[p] = {i, j};
        }
        if( ok == false && j + 2 <= M && A[i][j + 1] != 0 && A[i][j + 2] == 0 ){
            int nr = A[i][j + 1];
            Is_not[nr] = 1;  A[i][j + 1] = 0;   A[i][j + 2] = p;  A[i][j] = 0;
            pair<int,int> new_pos = { i, j + 2 };  S.push_back( new_pos );  Im[p] = new_pos;
            solve( k + 1 );
            Is_not[nr] = 0;  A[i][j + 1] = nr;  A[i][j + 2] = 0;  A[i][j] = p;
            S.pop_back(); Im[p] = {i, j};
        }
        if( ok == false && j - 2 >= 1 && A[i][j - 1] != 0 && A[i][j - 2] == 0 ){
            int nr = A[i][j - 1];
            Is_not[nr] = 1;  A[i][j - 1] = 0;   A[i][j - 2] = p;  A[i][j] = 0;
            pair<int,int> new_pos = { i, j - 2 };  S.push_back( new_pos );  Im[p] = new_pos;
            solve( k + 1 );
            Is_not[nr] = 0;  A[i][j - 1] = nr;  A[i][j - 2] = 0;  A[i][j] = p;
            S.pop_back(); Im[p] = {i, j};
        }
        S.pop_back();
    }
    return;
}
int main(){
    fin >> N >> M >> K;
    for( int i = 1; i <= K; i++ ){
        fin >> Im[i].first >> Im[i].second;
        A[ Im[i].first ][ Im[i].second ] = i;
    }
    solve( 1 );
    return 0;
}

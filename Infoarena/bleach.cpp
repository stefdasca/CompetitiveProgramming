#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream fin("bleach.in");
ofstream fout("bleach.out");
int n, k, x;
long long sol, put;
vector<int> v;
int main(){
    fin >> n >> k;
    k++;
    for( int i = 1; i <= k; i++ ){
        fin >> x;
        v.push_back( x );
        push_heap( v.begin(), v.end(), greater<int>() );
    }
    for( int i = k + 1; i <= n; i++ ){
        fin >> x;
        if( put < v.front() ){
            sol += v.front() - put;
            put = 2 * v.front();
        }else{
            put += v.front();
        }
        pop_heap( v.begin(), v.end(), greater<int>() );
        v.pop_back();
        v.push_back( x );
        push_heap( v.begin(), v.end(), greater<int>() );
    }
    while( !v.empty() ){
        if( put < v.front() ){
            sol += v.front() - put;
            put = 2 * v.front();
        }else{
            put += v.front();
        }
        pop_heap( v.begin(), v.end(), greater<int>() );
        v.pop_back();
    }
    fout << sol;
    return 0;
}

#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int timp[1000001], a, b, i, n, m, k;
struct str
{
    int b, e;
}v[1000001];
bool compar( str x, str y )
{
    return x.b < y.b;
}
struct compar1
{
    bool operator()( int x, int y ){
        return timp[x]>timp[y];
    }
};
struct compar2
{
    bool operator()( int x, int y ){
        return x > y;
    }
};
priority_queue <int,vector<int>,compar2> h_i;
priority_queue <int,vector<int>,compar1> h_t;
int main()
{
    freopen("proc2.in", "r", stdin);
    freopen("proc2.out", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for( i = 1; i <= n; i++ )
        h_i.push( i );
    for( i = 1; i <= m; i++ ){
        scanf("%d%d\n", &v[i].b, &v[i].e);
        v[i].e+=v[i].b;
    }
    sort( v + 1, v + m + 1, compar );
    for( i = 1; i <= m; i++ )
        {
        while (!h_t.empty() && timp[h_t.top()] <= v[i].b)
        {
            h_i.push(h_t.top());
            h_t.pop();
        }
        printf("%d\n",h_i.top());
        timp[ h_i.top() ] = v[i].e;
        h_t.push( h_i.top() );
        h_i.pop();
    }
    return 0;
}

/*
        POI 15-Trips

    It is obvious that we need to find the kth shortest path in the graph and we can do binary search for the answer.
Small constraints make matrix exponentiation obvious, but implementing it isn't that easy.

    For solving edge_weight = 1 subtask, we can create a matrix with N+1 lines where we keep the recurrence relation.
(we have to add an extra vertex, thus finding A^0 + A^1 + ... + A^n is equivalent with finding B^(n+1), where A is the initial recurrence
relation matrix and B is the new one)

    A = n*n matrix, a[i][j] = how many roads exist from i to j
    B = (n+1) * (n+1) matrix, b[i][j] = 1 if j = n, otherwise b[i][j] = a[i][j].

    For full solve, we can keep a matrix of 3n*3n which can be built as you observe below. (let's note it C)

    In order to optimize the runtime, we are going to compute C^2, C^4, C^8 and so on, in order to optimize one log from the complexity(instead of bin search
greedily increase the answer).

    For proof of the solution, please check the official solution
     -> https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2015/editorial/wyc.pdf

*/
#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

ll n, m, k;

ll mxx = (1LL<<60);

int SZ;

struct Matrix
{
    vector<vector<ll> >v;
    Matrix()
    {
        v.resize(SZ, vector<ll>(SZ, 0));
    }
};
inline ll realval(ll a, ll b)
{
    if(a == 0)
        return 0;
    if(mxx/a < b)
        return mxx;
    return a*b;
}
inline Matrix operator *(Matrix a, Matrix b)
{
    Matrix ans;
    for(int i = 0; i < SZ; ++i)
        for(int j = 0; j < SZ; ++j)
            for(int kk = 0; kk < SZ; ++kk)
                ans.v[j][kk] = min(ans.v[j][kk] + realval(a.v[j][i], b.v[i][kk]), mxx);
    return ans;
}

Matrix rec, pw[69], zero;

inline Matrix exp(Matrix mat, ll put)
{
    Matrix ans;
    for(int i = 0; i < SZ; ++i)
        ans.v[i][i] = 1;
    while(put)
    {
        if(put & 1)
            ans = ans * mat;
        mat = mat * mat;
        put >>= 1;
    }
    return ans;
}
inline ll chk(Matrix r)
{
    ll ans = 0;
    for(int i = 0; i < n; ++i)
        ans = min(ans + r.v[3*n][3*i], mxx);
    return ans;
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    SZ = 3*n+1;
    Matrix rec;
    k += n;
    rec.v[3*n][3*n] = 1;
    for(int i = 0; i < n; ++i)
    {
        rec.v[3*n][3*i] = 1;
        rec.v[3*i][3*i+1] = 1;
        rec.v[3*i+1][3*i+2] = 1;
    }
    for(int i = 1; i <= m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        rec.v[3*a+c-1][3*b]++;
    }
    ll ans = 0;
    int ind = 0;
    pw[0] = rec;
    while((1LL << ind) <= (k+k) && chk(pw[ind]) < k)
    {
		pw[ind + 1] = pw[ind] * pw[ind];
		ind++;
	}
    if(chk(pw[ind]) >= k)
    {
		Matrix m = rec;
		for(int i = ind; i >= 0; i--)
			if(chk(m * pw[i]) < k)
			{
				 m = m * pw[i];
				 ans |= (1LL << i);
			}
		ans++;
		cout << ans;
	}
    else
        cout << -1;
    return 0;
}

/*
        JOISC 19-naan

    We can break the naan evenly(by happiness) into n pieces for each person.

    Let's define p(i, j) as the position of the jth cut for the ith person.
For each j from 1 to n, take the smallest p(i, j) out of the remaining people and stop considering i afterwards.

    The only problem left is finding the fractions without complicated operations, and this can be done using two pointers
for each person.

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

int n, l;
int mat[2002][2002];
ll num[2002][2002], den[2002][2002];

bool tk[2002];

bool smaller(int a, int b, int pz)
{
    double rap = (0.0000 + num[b][pz]) / (0.0000 + den[b][pz]);
    double rap2 = (0.0000 + num[a][pz]) / (0.0000 + den[a][pz]);
    return (rap < rap2);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < l; ++j)
            cin >> mat[i][j];
    for(int i = 0; i < n; ++i)
    {
        int sum = 0;
        for(int j = 0; j < l; ++j)
            sum += mat[i][j];
        int cursum = 0;
        int pp = 0;
        for(int j = 0; j < n; ++j)
        {
            while(1LL * cursum * n < 1LL * sum * (j+1))
                cursum += mat[i][pp++];
            num[i][j] = 1LL * pp * n * mat[i][pp - 1] - 1LL * cursum * n + 1LL * sum * (j+1);
            den[i][j] = 1LL * n * mat[i][pp - 1];
        }
    }
    vector<int> wh;
    for(int i = 0; i < n; ++i)
    {
        int cn = -1;
        for(int j = 0; j < n; ++j)
            if(!tk[j])
            {
                if(cn == -1 || smaller(cn, j, i))
                    cn = j;
            }
        wh.pb(cn);
        tk[cn] = 1;
    }
    for(int i = 0; i < n - 1; ++i)
        cout << num[wh[i]][i] << " " << den[wh[i]][i] << '\n';
    for(int i = 0; i < wh.size(); ++i)
        cout << wh[i] + 1 << " ";
    return 0;
}

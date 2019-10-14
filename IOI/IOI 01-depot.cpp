/*
        IOI 01-depot(98.13) solution

    * Do backtracking, and try to optimize as much as possible by discarding the impossible states
(wrong row, wrong column, rows are too big/small, wrong value and so on)


    100 points solution - https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/IOI/official/2001

*/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int r, n, row[102], col[102];
int a[18][18], mt[11][11];
int nr[16], ct[16];
bool viz[16];
int perm[16];
int xx;
inline void bkt(int poz, int mat[11][11])
{
    int ind = 1;
    xx++;
    if(xx >= 10000000)
        exit(0);
    if(poz > n)
    {
        while(mat[ind][0])
        {
            for(int j = 1; j <= mat[ind][0]; ++j)
                if(row[mat[ind][j]] != ind)
                    return;
            ++ind;
        }
        for(int i = 1; i <= n; ++i)
            cout << perm[i] << " ";
        cout << '\n';
        return;
    }
    while(mat[ind][0])
    {
        if(mat[ind][0] + (n - poz + 1) < a[ind][0])
            return;
        ++ind;
    }
    if(mat[1][0] == a[1][0])
    {
        for(int i = n; nr[i] > mat[1][mat[1][0]]; --i)
            if(!viz[i])
                return;
    }
    if((ind - 1) + (n - poz + 1) < r)
        return;
    int mat2[11][11];
    for(int i = 1; i <= n; ++i)
    {
        if(viz[i])
            continue;
        memset(mat2, 0, sizeof(mat2));
        int pp = 1;
        if(row[nr[i]] == r && ct[row[nr[i]]] + 1 != col[nr[i]])
            return;
        while(mat[pp][0])
        {
            for(int j = 0; j <= mat[pp][0]; ++j)
                mat2[pp][j] = mat[pp][j];
            ++pp;
        }
        int rw = 1;
        bool ok = 1;
        int nn = nr[i];
        bool rau = 0;
        while(ok)
        {
            ok = 0;
            if(rw > row[nn])
                return;
            if(nn > mat2[rw][mat2[rw][0]])
            {
                ++mat2[rw][0];
                mat2[rw][mat2[rw][0]] = nn;
                if((n - poz) + rw < row[nn])
                    return;
                if(mat2[rw][0] > a[rw][0])
                    return;
                if(mat2[rw][mat2[rw][0]] < a[rw][mat2[rw][0]])
                    return;
                if(row[nn] == rw && col[nn] != mat2[rw][0])
                    rau = 1;
            }
            else
            {
                int ans = 1;
                while(mat2[rw][ans] < nn)
                    ++ans;
                swap(nn, mat2[rw][ans]);
                if(mat2[rw][ans] < a[rw][ans])
                    return;
                ++rw;
                ok = 1;
            }
        }
        if(!rau)
        {
            viz[i] = 1;
            ++ct[row[nr[i]]];
            perm[poz] = nr[i];
            bkt(poz + 1, mat2);
            --ct[row[nr[i]]];
            viz[i] = 0;
        }
    }
}
int main()
{
    cin >> r;
    for(int i = 1; i <= r; ++i)
    {
        cin >> a[i][0];
        for(int j = 1; j <= a[i][0]; ++j)
        {
            cin >> a[i][j];
            nr[++n] = a[i][j];
            row[a[i][j]] = i;
            col[a[i][j]] = j;
        }
    }
    sort(nr + 1, nr + n + 1);
    bkt(1, mt);
    return 0;
}

/*
        IOI 01-depot(98.13) solution

    * Do backtracking, and try to optimize as much as possible by discarding the impossible states
(wrong row, wrong column, rows are too big/small, wrong value and so on)


    100 points solution - https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/IOI/official/2001

*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int r, n, row[102], col[102];
int a[18][18], mt[11][11];
int nr[16];
bool viz[16];
int perm[16];
int xx = 0;
inline void bkt(int poz, int mat[11][11])
{
    int ind = 1;
    ++xx;
    if(xx >= 9000000)
        exit(0);
    int smr = 10000;
    for(int i = 1; i <= n; ++i)
        if(!viz[i])
        {
            smr = nr[i];
            break;
        }
    while(mat[ind][0])
    {
        if(mat[ind][0] > a[ind][0])
            return;
        if(mat[ind][0] + (n - poz + 1) < a[ind][0])
            return;
        int bg = 0;
        for(int j = 1; j <= mat[ind][0]; ++j)
            if(row[mat[ind][j]] < ind)
                return;
            else
                if(row[mat[ind][j]] == ind && col[mat[ind][j]] != j)
                    return;
                else
                    if(mat[ind][j] < a[ind][j])
                        return;
                    else
                        if(mat[ind][j] > a[ind][j])
                            ++bg;
        if(bg > (n - poz + 1))
            return;
        ++ind;
    }
    if(mat[1][0] == a[1][0])
    {
        for(int i = 1; i <= n; ++i)
            if(!viz[i] && nr[i] > mat[1][mat[1][0]])
                return;
    }
    if((ind - 1) + (n - poz + 1) < r)
        return;
    if(poz > n)
    {
        ind = 1;
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
    for(int i = 1; i <= n; ++i)
    {
        if(viz[i])
            continue;
        int mat2[11][11] = {0};
        int pp = 1;
        while(mat[pp][0])
        {
            memcpy(mat2[pp], mat[pp], sizeof(mat[pp]));
            ++pp;
        }
        int rw = 1;
        bool ok = 1;
        int nn = nr[i];
        while(ok)
        {
            ok = 0;
            int st = 1;
            int dr = mat2[rw][0];
            if(rw > row[nn])
                return;
            if(nn > mat2[rw][mat2[rw][0]])
            {
                ++mat2[rw][0];
                mat2[rw][mat2[rw][0]] = nn;
                if(mat2[rw][0] > a[rw][0])
                    return;
            }
            else
            {
                int ans = 0;
                while(st <= dr)
                {
                    int mid = (st + dr) / 2;
                    if(mat2[rw][mid] > nn)
                        ans = mid, dr = mid - 1;
                    else
                        st = mid + 1;
                }
                swap(nn, mat2[rw][ans]);
                if(mat2[rw][ans] < a[rw][ans])
                    return;
                ++rw;
                ok = 1;
            }
        }
        viz[i] = 1;
        perm[poz] = nr[i];
        bkt(poz + 1, mat2);
        viz[i] = 0;
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

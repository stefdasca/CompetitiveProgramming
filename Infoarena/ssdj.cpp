/*
        infoarena ssdj

    Given a n*n matrix with latin lowercase letters, find how many submatrices exist such that upper left and lower right corner letters are bigger
than all other letters

    We can assume each letter from 'z' to 'a' to be the 2nd largest letter in the matrix, and we will use prefix min/max + stacks to find how many submatrixes
have one of the corners in point (i, j)

*/
#include<bits/stdc++.h>
using namespace std;
ifstream f("ssdj.in");
ofstream g("ssdj.out");
int n;
char mat[1002][1002];
int d[1002], ss;
int lst[1002][1002], lst2[1002][1002];
bool pus[1002][1002];
long long ans;
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> (mat[i] + 1);
    for(int i = 1; i <= n; ++i)
        lst2[n+1][i] = n+2;
    for(char i = 'z'; i >= 'a'; --i)
    {
        for(int R = 1; R <= n; ++R)
        {
            ss = 0;
            for(int S = 1; S <= n; ++S)
            {
                if(mat[R][S] >= i)
                    lst[R][S] = R;
                else
                    lst[R][S] = lst[R-1][S];
                while(ss && lst[R-1][S] >= lst[R][d[ss]])
                    --ss;
                if(mat[R][S] == i)
                {
                    ans += ss;
                    if(ss && d[1] == S)
                        --ans;
                }
                while(ss && lst[R][S] >= lst[R][d[ss]])
                    --ss;
                if(lst[R][S] <= (R - 1) && lst[R][S] != 0)
                    d[++ss] = S;
            }
        }
        for(int R = n; R >= 1; --R)
        {
            ss = 0;
            int hm = 0;
            for(int S = n; S >= 1; --S)
            {
                if(mat[R][S] >= i)
                    lst2[R][S] = R;
                else
                    lst2[R][S] = lst2[R+1][S];
                while(ss && lst2[R+1][S] <= lst2[R][d[ss]])
                {
                    if(mat[lst2[R][d[ss]]][d[ss]] == i)
                        --hm;
                    --ss;
                }
                if(mat[R][S] == i)
                {
                    int aa = ss;
                    ans += ss;
                    ans -= hm;
                    if(ss && d[ss] == S)
                        --ans, --aa;
                }
                while(ss && lst2[R][S] <= lst2[R][d[ss]])
                {
                    if(mat[lst2[R][d[ss]]][d[ss]] == i)
                        --hm;
                    --ss;
                }
                if(lst2[R][S] >= (R + 1) && lst2[R][S] != (n+2))
                {
                    if(mat[lst2[R][S]][S] == i)
                        ++hm;
                    d[++ss] = S;
                }
            }
        }
    }
    g << ans << '\n';
    return 0;
}

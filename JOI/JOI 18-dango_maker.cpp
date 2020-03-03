/*
        JOI 18-dango_maker

    idea: https://codeforces.com/blog/entry/57637?#comment-413356

*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[3002][3002];
bool viz[3002][3002], scos[3002][3002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> (a[i] + 1);
    int dir = 1;
    int L = 1;
    int C = 1;
    int rem = n*m;
    int ans = 0;
    while(rem >= 0)
    {
        int okb = 0;
        if(rem == 0)
            okb = 1;
     //   cout << L << " " << C << " " << dir << " " << rem << '\n';
        if(dir == 1)
        {
            if(rem != n*m)
            {
                ++L;
                viz[L][C] = 0;
                ++rem;
            }
            while(C <= m && !viz[L][C])
            {
                if(C+2 <= m && a[L][C] == 'R' && a[L][C+1] == 'G' && a[L][C+2] == 'W')
                    if(!scos[L][C] && !scos[L][C+1] && !scos[L][C+2])
                    {
                       // cout << L << " " << C << '\n';
                        scos[L][C] = scos[L][C+1] = scos[L][C+2] = 1;
                        ++ans;
                    }
                if(a[L][C-1] == 'R' && a[L][C] == 'G' && a[L][C+1] == 'W')
                {
                    if(!scos[L][C-1] && !scos[L][C] && !scos[L][C+1])
                    {
                        // cout << L << " " << C-1 << '\n';
                        scos[L][C-1] = scos[L][C] = scos[L][C+1] = 1;
                        ++ans;
                    }
                }
                if(C - 2 > 0 && a[L][C-2] == 'R' && a[L][C-1] == 'G' && a[L][C] == 'W')
                {
                    if(!scos[L][C-2] && !scos[L][C-1] && !scos[L][C])
                    {
                      //  cout << L << " " << C - 2 << '\n';
                        scos[L][C-2] = scos[L][C-1] = scos[L][C] = 1;
                        ++ans;
                    }
                }
                viz[L][C] = 1;
                --rem;
                ++C;
            }
            dir = 2;
        }
        else
            if(dir == 2)
            {
                --C;
                ++rem;
                viz[L][C] = 0;
                while(L <= n && !viz[L][C])
                {
                    if(L+2 <= n && a[L][C] == 'R' && a[L+1][C] == 'G' && a[L+2][C] == 'W')
                    {
                        if(!scos[L][C] && !scos[L+1][C] && !scos[L+2][C])
                        {
                         //   cout << L << " " << C << '\n';
                            ++ans;
                            scos[L][C] = scos[L+1][C] = scos[L+2][C] = 1;
                        }
                    }
                    if(L-2 >= 0 && a[L-2][C] == 'R' && a[L-1][C] == 'G' && a[L][C] == 'W')
                    {
                        if(!scos[L-2][C] && !scos[L-1][C] && !scos[L][C])
                        {
                         //   cout << L << " " << C << '\n';
                            ++ans;
                            scos[L-2][C] = scos[L-1][C] = scos[L][C] = 1;
                        }
                    }
                    if(a[L-1][C] == 'R' && a[L][C] == 'G' && a[L+1][C] == 'W')
                    {
                        if(!scos[L-1][C] && !scos[L][C] && !scos[L+1][C])
                        {
                            ++ans;
                        //    cout << L << " " << C << '\n';
                            scos[L-1][C] = scos[L][C] = scos[L+1][C] = 1;
                        }
                    }
                    viz[L][C] = 1;
                    --rem;
                    ++L;
                }
                dir = 3;
            }
            else
                if(dir == 3)
                {
                    ++rem;
                    --L;
                    viz[L][C] = 0;
                    while(C && !viz[L][C])
                    {
                        if(C+2 <= m && a[L][C] == 'R' && a[L][C+1] == 'G' && a[L][C+2] == 'W')
                            if(!scos[L][C] && !scos[L][C+1] && !scos[L][C+2])
                            {
                            //    cout << L << " " << C << '\n';
                                scos[L][C] = scos[L][C+1] = scos[L][C+2] = 1;
                                ++ans;
                            }
                        if(a[L][C-1] == 'R' && a[L][C] == 'G' && a[L][C+1] == 'W')
                        {
                            if(!scos[L][C-1] && !scos[L][C] && !scos[L][C+1])
                            {
                             //   cout << L << " " << C-1 << '\n';
                                scos[L][C-1] = scos[L][C] = scos[L][C+1] = 1;
                                ++ans;
                            }
                        }
                        if(C - 2 > 0 && a[L][C-2] == 'R' && a[L][C-1] == 'G' && a[L][C] == 'W')
                        {
                            if(!scos[L][C-2] && !scos[L][C-1] && !scos[L][C])
                            {
                              //  cout << L << " " << C - 2 << '\n';
                                scos[L][C-2] = scos[L][C-1] = scos[L][C] = 1;
                                ++ans;
                            }
                        }
                        viz[L][C] = 1;
                        --rem;
                        --C;
                    }
                    dir = 4;
                }
                else
                {
                    ++rem;
                    ++C;
                    viz[L][C] = 0;
                    while(L && !viz[L][C])
                    {
                        if(L+2 <= n && a[L][C] == 'R' && a[L+1][C] == 'G' && a[L+2][C] == 'W')
                        {
                            if(!scos[L][C] && !scos[L+1][C] && !scos[L+2][C])
                            {
                            //    cout << L << " " << C << '\n';
                                ++ans;
                                scos[L][C] = scos[L+1][C] = scos[L+2][C] = 1;
                            }
                        }
                        if(L-2 >= 0 && a[L-2][C] == 'R' && a[L-1][C] == 'G' && a[L][C] == 'W')
                        {
                            if(!scos[L-2][C] && !scos[L-1][C] && !scos[L][C])
                            {
                             //   cout << L << " " << C << '\n';
                                ++ans;
                                scos[L-2][C] = scos[L-1][C] = scos[L][C] = 1;
                            }
                        }
                        if(a[L-1][C] == 'R' && a[L][C] == 'G' && a[L+1][C] == 'W')
                        {
                            if(!scos[L-1][C] && !scos[L][C] && !scos[L+1][C])
                            {
                                ++ans;
                             //   cout << L << " " << C << '\n';
                                scos[L-1][C] = scos[L][C] = scos[L+1][C] = 1;
                            }
                        }
                        viz[L][C] = 1;
                        --rem;
                        --L;
                    }
                    dir = 1;
                }
        if(okb)
            break;
    }
    cout << ans;
    return 0;
}

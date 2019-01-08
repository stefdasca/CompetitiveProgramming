#include<bits/stdc++.h>
using namespace std;
long long n, m;
string s;
vector<int>v[300002];
vector<int>v2[300002];
vector<int>ans[300002];
int convert(char x)
{
    if(x == 'A')
        return 1;
    if(x == 'C')
        return 2;
    if(x == 'G')
        return 3;
    return 4;
}
char convert2(int x)
{
    if(x == 1)
        return 'A';
    if(x == 2)
        return 'C';
    if(x == 3)
        return 'G';
    return 'T';
}
int vv[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        for(int j = 0; j < m; ++j)
            v[i].push_back(convert(s[j])), v2[i].push_back(v[i].back()), ans[i].push_back(v[i].back());
    }
    int mini = (1<<30);
    for(int i = 0; i <= 3; ++i)
        vv[i] = i+1;
    do
    {
        int opp = 0;
        for(int i = 1; i <= n; ++i)
        {
            int ta = 0;
            int tb = 0;
            if(i % 2 == 1)
            {
                for(int j = 0; j < m; ++j)
                {
                    if(j % 2 == 0)
                    {
                        ta += (v[i][j] != vv[0]);
                        tb += (v[i][j] != vv[1]);
                    }
                    else
                    {
                        ta += (v[i][j] != vv[1]);
                        tb += (v[i][j] != vv[0]);
                    }
                }
                if(ta <= tb)
                {
                    for(int j = 0; j < m; ++j)
                        if(j % 2 == 0)
                            v2[i][j] = vv[0];
                        else
                            v2[i][j] = vv[1];
                }
                else
                {
                    for(int j = 0; j < m; ++j)
                        if(j % 2 == 0)
                            v2[i][j] = vv[1];
                        else
                            v2[i][j] = vv[0];
                }
                opp += min(ta, tb);
            }
            else
            {
                for(int j = 0; j < m; ++j)
                {
                    if(j % 2 == 0)
                    {
                        ta += (v[i][j] != vv[2]);
                        tb += (v[i][j] != vv[3]);
                    }
                    else
                    {
                        ta += (v[i][j] != vv[3]);
                        tb += (v[i][j] != vv[2]);
                    }
                }
                if(ta <= tb)
                {
                    for(int j = 0; j < m; ++j)
                        if(j % 2 == 0)
                            v2[i][j] = vv[2];
                        else
                            v2[i][j] = vv[3];
                }
                else
                {
                    for(int j = 0; j < m; ++j)
                        if(j % 2 == 0)
                            v2[i][j] = vv[3];
                        else
                            v2[i][j] = vv[2];
                }
                opp += min(ta, tb);
            }
        }
        if(opp < mini)
        {
            mini = opp;
            for(int i = 1; i <= n; ++i)
                for(int j = 0; j < m; ++j)
                    ans[i][j] = v2[i][j];
        }
        opp = 0;
        for(int i = 0; i < m; ++i)
        {
            int ta = 0;
            int tb = 0;
            if(i % 2 == 1)
            {
                for(int j = 1; j <= n; ++j)
                {
                    if(j % 2 == 0)
                    {
                        ta += (v[j][i] != vv[0]);
                        tb += (v[j][i] != vv[1]);
                    }
                    else
                    {
                        ta += (v[j][i] != vv[1]);
                        tb += (v[j][i] != vv[0]);
                    }
                }
                if(ta <= tb)
                {
                    for(int j = 1; j <= n; ++j)
                        if(j % 2 == 0)
                            v2[j][i] = vv[0];
                        else
                            v2[j][i] = vv[1];
                }
                else
                {
                    for(int j = 1; j <= n; ++j)
                        if(j % 2 == 0)
                            v2[j][i] = vv[1];
                        else
                            v2[j][i] = vv[0];
                }
                opp += min(ta, tb);
            }
            else
            {
                for(int j = 1; j <= n; ++j)
                {
                    if(j % 2 == 0)
                    {
                        ta += (v[j][i] != vv[2]);
                        tb += (v[j][i] != vv[3]);
                    }
                    else
                    {
                        ta += (v[j][i] != vv[3]);
                        tb += (v[j][i] != vv[2]);
                    }
                }
                if(ta <= tb)
                {
                    for(int j = 1; j <= n; ++j)
                        if(j % 2 == 0)
                            v2[j][i] = vv[2];
                        else
                            v2[j][i] = vv[3];
                }
                else
                {
                    for(int j = 1; j <= n; ++j)
                        if(j % 2 == 0)
                            v2[j][i] = vv[3];
                        else
                            v2[j][i] = vv[2];
                }
                opp += min(ta, tb);
            }
        }
        if(opp < mini)
        {
            mini = opp;
            for(int i = 1; i <= n; ++i)
                for(int j = 0; j < m; ++j)
                    ans[i][j] = v2[i][j];
        }
    }while(next_permutation(vv, vv + 4));
    for(int i = 1; i <= n; cout << '\n', ++i)
        for(int j = 0; j < m; ++j)
            cout << convert2(ans[i][j]);
    return 0;
}

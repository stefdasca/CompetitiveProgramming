/*
            UVA 10040

    Classical problem which can be solved in two ways(either eulerian cycle or backtracking).

    Precomputing the answers is necessary for AC.

*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool v[(1<<22)];
string s;
bool ok;
int qq;
void bkt()
{
    if(ok)
        return;
    if(qq==(1<<n)+n-1)
    {
        ok=1;
        return;
    }
    for(char x='0';x<='1';++x)
    {
        if(qq+1>=n)
        {
            int p2=2;
            int nr=0;
            for(int p=qq-1;p>qq-n;--p)
            {
                nr+=p2*(s[p]-'0');
                p2*=2;
            }
            nr+=(x-'0');
            if(!v[nr])
            {
                v[nr]=1;
                s[qq]=x;
                ++qq;
                bkt();
                if(ok)
                    return;
                --qq;
                v[nr]=0;
            }
        }
        else
        {
            s[qq]=x;
            ++qq;
            bkt();
            if(ok)
                return;
        }
    }
}
string ans[26];
int vals[22][(1<<22)];
int main()
{
    n = 1;
    for(; n <= 21; ++n)
    {
        ok = 0;
        qq = 0;
        memset(v, 0, sizeof(v));
        s.clear();
        s.resize((1<<n)+n-1);
        bkt();
        int xx = n-1;
        while(xx)
            s.pop_back(), --xx;
        ans[n] = s;
    }
    for(int i = 1; i <= 21; ++i)
    {
        int x = 0;
        for(int j = 0; j < i; ++j)
            x += (1<<(i - j - 1)) * (ans[i][j] - '0');
        vals[i][0] = x;
        int st = 1;
        int sf = i;
        int ct = 1;
        while(st != 0)
        {
            x <<= 1;
            if(x & (1<<i))
                x ^= (1<<i);
            x += (ans[i][sf] - '0');
            vals[i][ct] = x;
            ++st;
            ++sf;
            ++ct;
            if(st == ans[i].size())
                st = 0;
            if(sf == ans[i].size())
                sf = 0;
        }
    }
    int t;
    cin >> t;
    for(; t; --t)
    {
        int n, k;
        cin >> n >> k;
        cout << vals[n][k] << '\n';
    }
    return 0;
}

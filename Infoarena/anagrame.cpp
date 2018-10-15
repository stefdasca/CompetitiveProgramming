#include<bits/stdc++.h>
using namespace std;
ifstream f("anagrame.in");
ofstream g("anagrame.out");
int p;
int frq[27];
int sum[100002][27];
int sum2[100002][27];
int mmx[100002];
int f2[27], cc[27];
int sol = 0;
int lst[100002];
string s1, s2;
string ans;
void dp()
{
    int Rp = s1.size();
    int mx = 0;
    lst[0] = s1.size();
    for(int i = s1.size() - 1; i >= 1; --i)
    {
        for(int j = 0; j <= 25; ++j)
            sum2[i][j] = sum2[i+1][j];
        sum2[i][s1[i] - 'a']++;
        while(1)
        {
            bool gg = 1;
            for(int j = 0; j <= 25; ++j)
                if(sum2[i][j] - sum2[Rp][j] < frq[j])
                    gg = 0;
            if(gg)
            {
                mx = max(mx, mmx[Rp]);
                --Rp;
            }
            else
                break;
        }
        bool gg = 1;
        for(int j = 0; j <= 25; ++j)
            if(sum2[i][j] < frq[j])
                gg = 0;
        if(gg)
        {
            mmx[i] = 1 + mx;
            if(!lst[mmx[i]])
                lst[mmx[i]] = i;
        }
    }
    int prevsol = 0;
    for(int i = 1; i <= sol; ++i)
    {
        for(int j = 0; j <= 25; ++j)
            f2[j] = frq[j], cc[j] = 0;
        deque<int>Rose;
        for(int j = prevsol + 1; j < lst[sol - i]; ++j)
        {
            if(cc[s1[j] - 'a'] < frq[s1[j] - 'a'])
            {
                while(!Rose.empty() && s1[j] < s1[Rose.back()])
                {
                    int x = (s1[Rose.back()] - 'a');
                    if(sum2[j][x] - sum2[lst[sol - i]][x] + cc[x] - 1 < f2[x])
                        break;
                    --cc[x];
                    Rose.pop_back();
                }
                Rose.push_back(j);
                ++cc[s1[j] - 'a'];
            }
        }
        for(int j = 0; j < Rose.size(); ++j)
        {
            int x = (s1[Rose[j]] - 'a');
            if(f2[x])
            {
                g << s1[Rose[j]];
                prevsol = Rose[j];
                --f2[x];
            }
        }
    }
}
int main()
{
    f >> p;
    f >> s1;
    f >> s2;
    for(int i = 0; i < s2.size(); ++i)
        frq[s2[i] - 'a']++;
    string s3;
    s3 += ' ';
    for(int i = 0; i < s1.size(); ++i)
        if(frq[s1[i] - 'a'])
            s3 += s1[i];
    s1 = s3;
    for(int i = 1; i < s1.size(); ++i)
    {
        for(int j = 0; j <= 25; ++j)
            sum[i][j] = sum[i-1][j];
        sum[i][s1[i] - 'a']++;
        ++f2[s1[i] - 'a'];
        bool gg = 1;
        for(int j = 0; j <= 25; ++j)
            if(f2[j] < frq[j])
                gg = 0;
        if(gg)
        {
            ++sol;
            memset(f2, 0, sizeof(f2));
        }
    }
    if(p == 1)
    {
        g << sol << '\n';
        return 0;
    }
    dp();
    g << ans;
    return 0;
}

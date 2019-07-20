#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long ll;

vector<int>v[5];
string s;
string s2;
int ct[4][1000002];
int n;
void tri(char a, char b)
{
    string snsd;
    vector<int>pz;
    bool ok = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(ok == 0 && s[i] == a)
            snsd += a, ok = 1, pz.pb(i);
        else
            if(ok == 1 && s[i] == b)
                snsd += b, ok = 0, pz.pb(i);
    }
    if(a == b && snsd.size() >= n/2)
    {
        cout << snsd;
        exit(0);
    }
    if(!snsd.size())
        return;
    if(snsd.size() % 2 == 0)
        snsd.pop_back(), pz.pop_back();
    if(snsd.size() >= n/2)
    {
        cout << snsd;
        exit(0);
    }
    int aa = snsd.size();
    if(pz[0] != 0 && pz.back() != s.size()-1)
    {
        int mxx = 0;
        for(int i = 0; i <= 2; ++i)
            mxx = max(mxx, min(ct[i][pz[0] - 1], ct[i][s.size()-1] - ct[i][pz.back()]));
        aa += mxx;
    }
    for(int xx = 0, yy = pz.size()-1; xx < yy; ++xx, --yy)
    {
        int mxx = 0;
        for(int i = 0; i <= 2; ++i)
            mxx = max(mxx, min(ct[i][pz[xx+1]-1] - ct[i][pz[xx]], ct[i][pz[yy]-1] - ct[i][pz[yy-1]]));
        aa += mxx;
    }
    if(aa >= n/2)
    {
        deque<char>d1, d2;
        int mxx = 0;
        for(int i = 0; i <= 2; ++i)
            mxx = max(mxx, min(ct[i][pz[0] - 1], ct[i][s.size()-1] - ct[i][pz.back()]));
        for(int i = 0; i <= 2; ++i)
        {
            int xx = min(ct[i][pz[0] - 1], ct[i][s.size()-1] - ct[i][pz.back()]);
            if(xx == mxx)
            {
                int yy = xx;
                for(int j = 0; j < pz[0] && yy; ++j)
                    if(s[j] == 'a' + i)
                        --yy, d1.push_back(s[j]);
                yy = xx;
                for(int j = s.size() - 1; j > pz.back() && yy; --j)
                    if(s[j] == 'a' + i)
                        --yy, d2.push_front(s[j]);
                break;
            }
        }
        int xx = 0, yy = pz.size()-1;
        for(; xx < yy; ++xx, --yy)
        {
            d1.push_back(s[pz[xx]]);
            d2.push_front(s[pz[yy]]);
            int mxx = 0;
            for(int i = 0; i <= 2; ++i)
                mxx = max(mxx, min(ct[i][pz[xx+1]-1] - ct[i][pz[xx]], ct[i][pz[yy]-1] - ct[i][pz[yy-1]]));
            for(int i = 0; i <= 2; ++i)
            {
                int xxx = min(ct[i][pz[xx+1]-1] - ct[i][pz[xx]], ct[i][pz[yy]-1] - ct[i][pz[yy-1]]);
                if(xxx == mxx)
                {
                    int yyy = xxx;
                    for(int j = pz[xx]+1; j < pz[xx+1] && yyy; ++j)
                        if(s[j] == 'a' + i)
                            --yyy, d1.push_back(s[j]);
                    yyy = xxx;
                    for(int j = pz[yy]-1; j > pz[yy-1] && yyy; --j)
                        if(s[j] == 'a' + i)
                            --yyy, d2.push_front(s[j]);
                    break;
                }
            }
        }
        d1.push_back(s[pz[xx]]);
        for(int i = 0; i < d1.size(); ++i)
            cout << d1[i];
        for(int i = 0; i < d2.size(); ++i)
            cout << d2[i];
        exit(0);
    }
}
bool is[1000002];
int nxt[5][1000002];
int prv[5][1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i)
            ct[0][i] = ct[0][i-1], ct[1][i] = ct[1][i-1], ct[2][i] = ct[2][i-1];
        ct[s[i] - 'a'][i]++;
    }
    for(int j = 0; j <= 2; ++j)
        nxt[j][s.size()] = s.size(), prv[j][0] = -1;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        for(int j = 0; j <= 2; ++j)
            nxt[j][i] = nxt[j][i+1];
        nxt[(s[i] - 'a')][i] = i;
    }
    prv[s[0] - 'a'][0] = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        for(int j = 0; j <= 2; ++j)
            prv[j][i] = prv[j][i-1];
        prv[s[i] - 'a'][i] = i;
    }

    int st = 0;
    int dr = s.size() - 1;
    int sss = 0;
    while(st <= dr)
    {
        if(st == dr)
        {
            ++sss;
            is[st] = 1;
            break;
        }
        int mn = (1<<30);
        for(int i = 0; i <= 2; ++i)
            if(prv[i][dr] > nxt[i][st])
                mn = min(mn, (nxt[i][st] - st + (dr - prv[i][dr])));
        for(int i = 0; i <= 2; ++i)
            if(prv[i][dr] > nxt[i][st])
            {
                if((nxt[i][st] - st + (dr - prv[i][dr])) == mn)
                {
                    is[nxt[i][st]] = 1;
                    is[prv[i][dr]] = 1;
                    st = nxt[i][st] + 1;
                    dr = prv[i][dr] - 1;
                }
            }
        if(mn == (1<<30))
        {
            ++sss;
            is[st] = 1;
            break;
        }
    }
    if(sss >= n/2)
    {
        for(int i = 0; i < s.size(); ++i)
            if(is[i])
                cout << s[i];
        return 0;
    }
    n = (int)s.size();
    tri('a', 'a');
    tri('b', 'b');
    tri('c', 'c');
    tri('a', 'b');
    tri('b', 'c');
    tri('a', 'c');
    tri('b', 'a');
    tri('c', 'a');
    tri('c', 'b');
    return 0;
}


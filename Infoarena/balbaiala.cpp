#include<bits/stdc++.h>
using namespace std;
ifstream f("balbaiala.in");
ofstream g("balbaiala.out");
int n, q;
string s;
int frq[27][100002], cnt[27], frq2[27][100002];
bool check(string a, int le)
{
    int stp = 0;
    for(int i = 1; i < a.size(); ++i)
    {
        int val = frq2[a[i]-'a'][stp];
        int val2 = frq[a[i]-'a'][val+le];
        if(val2 == 0)
            return 0;
        stp = val2;
    }
    return 1;
}
int main()
{
    f >> n >> q;
    f >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++i)
    {
        frq[s[i] - 'a'][++cnt[s[i]-'a']] = i;
        for(int j = 0; j <= 25; ++j)
            frq2[j][i] = cnt[j];
    }
    for(int i = 0; i < q; ++i)
    {
        string r;
        f >> r;
        r = ' ' + r;
        int b = 0;
        int e = (n/(r.size()-1));
        int sol = 0;
        while(b <= e)
        {
            int mid = (b+e)/2;
            if(check(r, mid))
                sol = mid, b = mid + 1;
            else
                e = mid - 1;
        }
        g << sol << '\n';
    }
    return 0;
}

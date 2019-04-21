#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand_seed()
{
	long long a = rng();
    return a;
}
string s;
string ss2;
int lst = -1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] != 'a')
            ss2 += s[i];
        else
            lst = i;
    if(lst == -1)
    {
        string s2;
        string s3;
        for(int i = 0; i < s.size() / 2; ++i)
            s2 += s[i];
        for(int j = s.size() / 2; j < s.size(); ++j)
            s3 += s[j];
        if(s2 != s3)
        {
            cout << ":(";
            return 0;
        }
        cout << s2;
        return 0;
    }
    if((int)ss2.size() % 2 == 1)
    {
        cout << ":(";
        return 0;
    }
    string ans;
    int pp = 0;
    for(int i = 0; i <= lst; ++i)
    {
        ans += s[i];
        if(s[i] != 'a')
            ++pp;
    }
    int oo = pp;
    pp = lst + 1;
    while(oo < (int)ss2.size() / 2)
        ans += s[pp], ++pp, ++oo;
    if(oo > (int)ss2.size() / 2)
    {
        cout << ":(";
        return 0;
    }
    for(int i = 0; i < ss2.size() / 2; ++i)
        if(ss2[i] != ss2[ss2.size()/2+i])
        {
            cout << ":(";
            return 0;
        }
    cout << ans;
    return 0;
}


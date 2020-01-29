#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

bool ok(string s)
{
    bool aoa = 0, bob = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(i+1 < s.size() && s[i] == s[i+1])
        {
            if(s[i] == 'A')
                aoa = 1;
            else
                bob = 1;
        }
        else
            if(i + 1 == s.size() && s[i] == s[0])
            {
                if(s[i] == 'A')
                    aoa = 1;
                else
                    bob = 1;
            }
    }
    if(aoa && bob)
        return 0;
    else
        if(!aoa && !bob)
            return 1;
        else
        {
            if(bob)
                for(int i = 0; i < s.size(); ++i)
                    if(s[i] == 'A')
                        s[i] = 'B';
                    else
                        s[i] = 'A';
        }
    if(s.size() == 2 && s[0] != s[1])
        return 1;
    int ps = -1;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == 'B')
        {
            ps = i;
            break;
        }
    if(ps == -1)
        return 0;
    vector<int> v;
    int poz = ps;
    int mn = -1, mx = -1;
    do{
        int strL = 0;
        int j = poz;
        do
        {
            ++strL;
            ++poz;
            if(poz == s.size())
                poz = 0;
        }while(poz != ps && s[j] == s[poz]);
        if(s[j] == 'A')
        {
            if(mn == -1)
                mn = mx = strL;
            else
            {
                mn = min(mn, strL);
                mx = max(mx, strL);
            }
            v.pb(strL);
        }
    }while(poz != ps);
    if(mx - mn > 1)
        return 0;
    if(v.size() == 1 || mn == mx)
        return 1;
    string s2;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == mn)
            s2 += 'A';
        else
            s2 += 'B';
    return ok(s2);
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(; t; --t)
    {
        string s;
        cin >> s;
        if(s.size() == 1)
            cout << 1 << '\n';
        else
            cout << ok(s) << '\n';
    }
    return 0;
}


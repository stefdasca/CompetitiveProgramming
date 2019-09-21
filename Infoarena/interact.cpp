/*

    * We can keep the "sorted" array of letters at each step.

    * A letter L1 will be before another letter L2 if we can insert L1 before all
letters L2(this can be binary searched)

    * At each step we are going to add to the answer the letter on position 0 and we will try
to insert it again using the same algorithm.

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

int n, s, ct[28];
string generator(char c, int le)
{
    string ans;
    for(int i = 1; i <= le; ++i)
        ans += c;
    return ans;
}
int gg[28][28];
string curent;
int ask(string s)
{
    int ans;
    cout << "? " << s << endl;
    cin >> ans;
    return ans;
}
int main()
{
    int n = 0;
    for(char c = 'a'; c <= 'z'; ++c)
        for(int j = 1; j <= 100; ++j)
        {
            int val = ask(generator(c, j));
            if(val == 1)
                ct[c - 'a'] = j, ++n;
            else
                break;
        }
    for(char c = 'a'; c <= 'z'; ++c)
    {
        if(!ct[c - 'a'])
            continue;
        for(char p = 'a'; p <= 'z'; ++p)
        {
            if(p == c)
            {
                gg[(c - 'a')][(p - 'a')] = 1;
                continue;
            }
            if(!ct[p - 'a'])
            {
                gg[c - 'a'][p - 'a'] = 1;
                continue;
            }
            string pos;
            pos += c;
            pos += generator(p, ct[p - 'a']);
            gg[(c - 'a')][(p - 'a')] = ask(pos);
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int poz = 0; poz <= 25; ++poz)
        {
            if(!ct[poz])
                continue;
            int cot = 0;
            for(int j = 0; j <= 25; ++j)
                cot += gg[poz][j];
            if(cot == 26)
            {
                curent += ('a' + poz);
                --ct[poz];
                char opp = ('a' + poz);
                for(char c = 'a'; c <= 'z'; ++c)
                {
                    if(!ct[c - 'a'])
                    {
                        for(int j = 0; j <= 25; ++j)
                            gg[(c - 'a')][j] = 0;
                        continue;
                    }
                    for(char p = 'a'; p <= 'z'; ++p)
                    {
                        if(c == opp || p == opp)
                        {
                            if(!ct[p - 'a'])
                            {
                                gg[c - 'a'][(p - 'a')] = 1;
                                continue;
                            }
                            if(c == p)
                            {
                                gg[(c - 'a')][(p - 'a')] = 1;
                                continue;
                            }
                            string pos = curent;
                            pos += c;
                            pos += generator(p, ct[p - 'a']);
                            gg[(c - 'a')][(p - 'a')] = ask(pos);
                        }
                    }
                }
                break;
            }
        }
    int ans;
    cout << "! " << curent << endl;
    cin >> ans;
    return 0;
}



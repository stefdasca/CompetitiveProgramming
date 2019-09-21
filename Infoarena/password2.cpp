/*
            Infoarena password2

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
int ask(string s)
{
    int ans;
    cout << s << endl;
    cin >> ans;
    if(ans == n)
        exit(0);
    return ans;
}
string curent;
char litera[28];
bool before(char lit, int poz)
{
    string qu = curent;
    if(!ct[lit - 'a'])
        return 0;
    qu += lit;
    qu += generator(litera[poz], ct[litera[poz] - 'a']);
    return (ask(qu) == qu.size());
}
int main()
{
    cin >> n >> s;
    for(char c = 'a'; c < ('a' + s); ++c)
        ct[c - 'a'] = ask(generator(c, n));
    litera[0] = 'a';
    for(int i = 1; i < s; ++i)
    {
        char lit = 'a' + i;
        int st = 0;
        int dr = (i - 1);
        int ans = i;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(before(lit, mid))
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        for(int j = s; j >= ans; --j)
            litera[j+1] = litera[j];
        litera[ans] = lit;
    }
    for(int i = 1; i <= n; ++i)
    {
        curent += litera[0];
        --ct[litera[0] - 'a'];
        char lit = litera[0];
        for(int j = 0; j < s; ++j)
            litera[j] = litera[j+1];
        if(i == n)
            continue;
        int st = 0;
        int dr = s - 2;
        int ans = s - 1;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;
            if(before(lit, mid))
                ans = mid, dr = mid - 1;
            else
                st = mid + 1;
        }
        for(int j = s; j >= ans; --j)
            litera[j+1] = litera[j];
        litera[ans] = lit;
    }
    ask(curent);
    return 0;
}


/*
        POI 16-Not_Nim

    https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/POI/official/2016/editorial/wca.pdf

*/
#include<bits/stdc++.h>
using namespace std;

int n, v[500002];
int Log(int nr)
{
    if(nr == 1)
        return 0;
    return 1 + Log(nr / 2);
}
int LeadingOnes(int n)
{
    int ans = 0;
    for(int i = 29; i >= 0; i--)
    {
        if(((1<<i) & n) != 0)
            ans++;
        else
            if(ans > 0)
                break;
    }
    return ans;
}
multiset<int>s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int ans = 4 * n - 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        ans += 2 * Log(v[i]);
        s.insert(-LeadingOnes(v[i]));
    }
    s.erase(s.begin());
    while(!s.empty())
    {
        int bst = *s.begin();
        if(bst == -1)
        {
            ans -= 2;
            s.erase(s.begin());
        }
        else
        {
            s.erase(s.begin());
            s.insert(bst + 1);
            s.erase(s.begin());
        }
    }
    cout << ans;
    return 0;
}

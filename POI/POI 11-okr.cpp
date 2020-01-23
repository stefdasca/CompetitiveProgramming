/*
        POI 11-okr



*/
#include<bits/stdc++.h>
using namespace std;


vector<int> extract(string s, int n)
{
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    vector<int> borders;
    int j = n;
    while(j > 0)
    {
        borders.push_back(j);
        j = pi[j-1];
    }
    reverse(borders.begin(), borders.end());
    return borders;
}
int main()
{
    int t;
    cin >> t;
    for(; t; --t)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> p = extract(s,n);
        char ans[n+1];
        if(p[0] == 1)
            ans[0] = '0';
        else
            for(int i = 0; i < p[0]; i++)
                ans[i] = '0' + (i == p[0] - 1);
        for(int i = 1; i < p.size(); i++)
        {
            if(p[i] - 2 * p[i-1] <= 0)
                memcpy(ans + p[i-1], ans + 2 * p[i-1] - p[i], sizeof(char) * (p[i] - p[i-1]));
            else
            {
                for(int j = p[i - 1]; j < p[i] - p[i - 1]; j++)
                    ans[j] = '0';
                memcpy(ans + p[i] - p[i-1], ans, sizeof(char) * p[i - 1]);
                vector<int> border_now = extract(ans, p[i]);
                if (!equal(p.begin(), p.begin()+i+1, border_now.begin()))
                    ans[p[i] - p[i-1] - 1] = '1';
            }
        }
        ans[n] = 0;
        cout << ans << '\n';
    }
    return 0;
}

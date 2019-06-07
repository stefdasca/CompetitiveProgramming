#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
bool bad;
int ans[100002];
void divimp(int bit, vector<int>P, vector<int>N)
{
    if(bad == 1)
        return;
    if(P.size() != N.size())
    {
        bad = 1;
        return;
    }
    if(P.size() == 1)
    {
        if(P[0] == N[0])
            bad = 1;
        ans[P[0]] = N[0];
        return;
    }
    vector<int>P2, P3;
    vector<int>N2, N3;
    for(int i = 0; i < P.size(); ++i)
        if(P[i] & (1<<bit))
            P2.push_back(P[i]);
        else
            P3.push_back(P[i]);
   for(int i = 0; i < N.size(); ++i)
        if(N[i] & (1<<bit))
            N2.push_back(N[i]);
        else
            N3.push_back(N[i]);
    if(P3.size() > N2.size())
    {
        while(P3.size() > N2.size())
        {
            N2.push_back(N3.back());
            N3.pop_back();
        }
    }
    divimp(bit + 1, P2, N3);
    divimp(bit + 1, P3, N2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int>pos;
    vector<int>nr;
    for(int i = 1; i <= n; ++i)
        pos.push_back(i), nr.push_back(i);
    divimp(0, pos, nr);
    if(bad)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << '\n';
    }
    if(n <= 3)
        cout << "NO\n";
    else
    {
        int pp = 1;
        while(pp * 2 <= n)
            pp *= 2;
        if(pp == n)
        {
            cout << "NO\n";
            return 0;
        }
        if(n >= 7)
        {
            cout << "YES\n";
            vector<int>ans;
            for(int i = 1; i <= n; i *= 2)
            {
                if(i == 4)
                {
                    for(int j = i + 2; j < min(n+1, i * 2); ++j)
                        ans.push_back(j);
                    ans.push_back(i);
                    ans.push_back(i+1);
                }
                else
                {
                    for(int j = i + 1; j < min(n+1, i * 2); ++j)
                        ans.push_back(j);
                    ans.push_back(i);
                }
            }
            swap(ans[0], ans[6]);
            for(int i = 0; i < ans.size(); ++i)
                cout << ans[i] << " ";
            cout << '\n';
            return 0;
        }
        if(n == 6)
        {
            cout << "YES\n";
            cout << "3 6 2 5 1 4";
            return 0;
        }
        if(n == 5)
        {
            cout << "NO\n";
            return 0;
        }
    }
    return 0;
}

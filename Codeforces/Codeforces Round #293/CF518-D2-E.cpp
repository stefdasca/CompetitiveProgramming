#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n, k;

string s;

bool pus[100002];

int val[100002];

bool viz[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        if(s[0] == '?')
            pus[i] = 1;
        else
        {
            bool sgn = 0;
            int pzb = 0;
            if(s[0] == '-')
                sgn = 1, pzb = 1;
            int nr = 0;
            for(int j = pzb; j < s.size(); ++j)
                nr = nr * 10 + (s[j] - '0');
            val[i] = nr;
            if(sgn == 1)
                val[i] *= -1;
        }
    }
    for(int i = n; i >= 1; --i)
    {
        if(!viz[i])
        {
            vector<int> tt;
            for(int j = i; j >= 1; j -= k)
            {
                tt.pb(j);
                viz[j] = 1;
            }
            reverse(tt.begin(), tt.end());
            int prv = n+1;
            while(!tt.empty())
            {
                vector<int> poz;
                while(!tt.empty() && pus[tt.back()])
                {
                    poz.pb(tt.back());
                    tt.pop_back();
                }
                if(tt.empty())
                {
                    if(prv == n+1)
                    {
                        int start_value = (int)poz.size() / 2;
                        for(int j = 0; j < (int)poz.size(); ++j)
                            val[poz[j]] = start_value--;
                    }
                    else
                    {
                        int start_value = val[prv] - 1;
                        if(start_value >= ((int)poz.size() / 2))
                            start_value = ((int)poz.size() / 2);
                        for(int j = 0; j < (int)poz.size(); ++j)
                            val[poz[j]] = start_value--;
                    }
                }
                else
                {
                    if(prv == n+1)
                    {
                        int start_value = val[tt.back()] + 1;
                        if(start_value < -((int)poz.size() / 2))
                            start_value = -((int)poz.size() / 2);
                        for(int j = poz.size() - 1; j >= 0; --j)
                            val[poz[j]] = start_value++;
                    }
                    else
                    {
                        if(val[tt.back()] + 1 >= -((int)poz.size() / 2))
                        {
                            int start_value = val[tt.back()] + 1;
                            for(int j = poz.size() - 1; j >= 0; --j)
                                val[poz[j]] = start_value++;
                        }
                        else
                        {
                            int start_value = min(val[prv] - (int)poz.size(), -((int)poz.size() / 2));
                            for(int j = poz.size() - 1; j >= 0; --j)
                                val[poz[j]] = start_value++;
                        }
                    }
                    prv = tt.back();
                    tt.pop_back();
                }
            }
        }
    }
    for(int i = k+1; i <= n; ++i)
        if(val[i] <= val[i - k])
        {
            cout << "Incorrect sequence";
            return 0;
        }
    for(int i = 1; i <= n; ++i)
        cout << val[i] << " ";
    return 0;
}

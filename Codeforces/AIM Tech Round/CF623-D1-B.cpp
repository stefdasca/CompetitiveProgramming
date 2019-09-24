#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a, b, ans;

int v[1000002];

vector<int>divprim, divprimsuf;
void procprefix()
{
    int nr = v[1];
    for(int i = 2; i * i <= nr; ++i)
    {
        if(nr % i == 0)
        {
            divprim.push_back(i);
            while(nr % i == 0)
                nr /= i;
        }
    }
    if(nr > 1)
        divprim.push_back(nr);
    for(int o = v[1] - 1; o <= v[1] + 1; o += 2)
    {
        int nr = o;
        for(int i = 2; i * i <= nr; ++i)
        {
            if(nr % i == 0)
            {
                bool gs = 0;
                for(int j = 0; j < divprim.size(); ++j)
                    if(divprim[j] == i)
                    {
                        gs = 1;
                        break;
                    }
                if(!gs)
                    divprim.push_back(i);
                while(nr % i == 0)
                    nr /= i;
            }
        }
        if(nr > 1)
        {
            bool gs = 0;
            for(int j = 0; j < divprim.size(); ++j)
                if(divprim[j]== nr)
                {
                    gs = 1;
                    break;
                }
            if(!gs)
                divprim.push_back(nr);
        }
    }

}
void procsufix()
{
    int nr = v[n];
    for(int i = 2; i * i <= nr; ++i)
    {
        if(nr % i == 0)
        {
            divprimsuf.push_back(i);
            while(nr % i == 0)
                nr /= i;
        }
    }
    if(nr > 1)
        divprimsuf.push_back(nr);
    for(int o = v[n] - 1; o <= v[n] + 1; o += 2)
    {
        int nr = o;
        for(int i = 2; i * i <= nr; ++i)
        {
            if(nr % i == 0)
            {
                bool gs = 0;
                for(int j = 0; j < divprimsuf.size(); ++j)
                {
                    if(divprimsuf[j] == i)
                    {
                        gs = 1;
                        break;
                    }
                }
                if(!gs)
                    divprimsuf.push_back(i);
                while(nr % i == 0)
                    nr /= i;
            }
        }
        if(nr > 1)
        {
            bool gs = 0;
            for(int j = 0; j < divprimsuf.size(); ++j)
            {
                if(divprimsuf[j] == nr)
                {
                    gs = 1;
                    break;
                }
            }
            if(!gs)
                divprimsuf.push_back(nr);
        }
    }
}
ll cost[1000002];
ll best[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);;
    cin >> n >> a >> b;
    ans = min(n * b, (n-1) * a);
    int cmmdc = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if(i == 1)
            cmmdc = v[i];
        else
            cmmdc = __gcd(cmmdc, v[i]);
    }
    if(cmmdc != 1)
    {
        cout << 0;
        return 0;
    }
    procprefix();
    procsufix();
    for(int i = 0; i < divprim.size(); ++i)
    {
        deque<int>divi;
        divi.push_back(n+1);
        memset(best, -1, sizeof(best));
        memset(cost, 0, sizeof(cost));
        bool rip = 0;
        for(int j = n; j >= 1; --j)
        {
            if(!rip)
                if(v[j] % divprim[i] == 0)
                    cost[j] = cost[j+1];
                else
                    if(v[j] % divprim[i] == 1 || v[j] % divprim[i] == (divprim[i] - 1))
                        cost[j] = cost[j+1] + b;
                    else
                        rip = 1;
            if(!divi.empty())
                best[j] = divi.front();
            if(!rip)
            {
                while(!divi.empty() && cost[j] < cost[divi.back()] + a * (divi.back() - j))
                    divi.pop_back();
                divi.push_back(j);
            }
        }
        ll co = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(v[j] % divprim[i] == 0);
            else
                if(v[j] % divprim[i] == 1 || v[j] % divprim[i] == (divprim[i] - 1))
                    co = co + b;
                else
                    break;
            if(best[j] == -1)
                ans = min(ans, co + (n - j) * a);
            else
                ans = min(ans, co + cost[best[j]] + (best[j] - j - 1) * a);
        }
    }
    for(int i = 0; i < divprimsuf.size(); ++i)
    {
        memset(cost, 0, sizeof(cost));
        deque<int>divi;
        divi.push_back(0);
        memset(best, -1, sizeof(best));
        bool rip = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(!rip)
                if(v[j] % divprimsuf[i] == 0)
                    cost[j] = cost[j-1];
                else
                    if(v[j] % divprimsuf[i] == 1 || v[j] % divprimsuf[i] == (divprimsuf[i] - 1))
                        cost[j] = cost[j-1] + b;
                    else
                        rip = 1;
            if(!divi.empty())
                best[j] = divi.front();
            if(!rip)
            {
                while(!divi.empty() && cost[j] < cost[divi.back()] + a * (j - divi.back()))
                    divi.pop_back();
                divi.push_back(j);
            }
        }
        ll co = 0;
        for(int j = n; j >= 1; --j)
        {
            if(v[j] % divprimsuf[i] == 0);
            else
                if(v[j] % divprimsuf[i] == 1 || v[j] % divprimsuf[i] == (divprimsuf[i] - 1))
                    co = co + b;
                else
                    break;
            if(best[j] == -1)
                ans = min(ans, co + (j - 1) * a);
            else
                ans = min(ans, co + cost[best[j]] + (j - best[j] - 1) * a);
        }
    }
    cout << ans;
    return 0;
}

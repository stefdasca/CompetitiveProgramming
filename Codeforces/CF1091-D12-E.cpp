#include<bits/stdc++.h>
using namespace std;
int n;
long long v[500005], sum;
bool odd, exists;
long long aib[500005], nr[500005];
void add(int poz, long long qt, int sgn)
{
    if(poz == 0)
    {
        aib[0] += qt;
        if(sgn == 1)
            ++nr[0];
        else
            --nr[0];
        return;
    }
    for(; poz <= n; poz += (poz & (-poz)))
    {
        aib[poz] += qt;
        if(sgn == 1)
            ++nr[poz];
        else
            --nr[poz];
    }
}
long long computenr(int poz)
{
    if(poz > n)
        poz = n;
    long long ans = nr[0];
    for(; poz; poz -= (poz & -(poz)))
        ans += nr[poz];
    return ans;
}
long long computesum(int poz)
{
    if(poz > n)
        poz = n;
    long long ans = aib[0];
    for(; poz; poz -= (poz & -(poz)))
        ans += aib[poz];
    return ans;
}
int check(int nr)
{
    /// 1 - good, 2 - left, 0 - right
    bool pus = 0;
    long long s = 0;
    for(int i = 1; i <= n; ++i)
        add(v[i], v[i], 1);
    add(nr, nr, 1);
    v[0] = 103454934;
    long long sss = 0;
    int ans = -1;
    for(int i = 1; i <= n; ++i)
    {
        if(!pus && v[i-1] >= nr && nr >= v[i])
        {
            pus = 1;
            s += nr;
            ++sss;
            add(nr, -nr, -1);
            int k = nr;
            long long ta = sss * (sss - 1) + computesum(sss) + 1LL * (computenr(n) - computenr(sss)) * sss;
            if(s > ta)
            {
                if(ans == -1)
                    ans = 2;
            }
        }
        int r = v[i];
        s += r;
        ++sss;
        add(r, -r, -1);
        int k = r;
        long long ta = sss * (sss - 1) + computesum(sss) + 1LL * (computenr(n) - computenr(sss)) * sss;
        if(s > ta)
        {
            if(ans != -1)
                continue;
            if(!pus)
                ans = 0;
            else
                ans = 2;
        }
    }
    if(!pus)
    {
        pus = 1;
        s += nr;
        ++sss;
        add(nr, -nr, -1);
        int k = nr;
        long long ta = sss * (sss - 1) + computesum(sss) + 1LL * (computenr(n) - computenr(sss)) * sss;
        if(s > ta)
        {
            if(ans == -1)
                ans = 2;
        }
    }
    if(ans == -1)
        return 1;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];
    sort(v+1, v+n+1, greater<int>());
    if(sum % 2 == 1)
        odd = 1;
    int st, dr;
    if(sum % 2 == 1)
        st = 1, dr = n - (n % 2 == 0);
    else
        st = 0, dr = n - (n % 2 == 1);
    int md = 0;
    while(st <= dr)
    {
        int tp1 = st / 2 + dr / 2 + st % 2 + dr % 2;
        int mid = tp1 / 2;
        if(sum % 2 == 1)
            mid = 2 * mid - 1;
        else
            mid = mid * 2;
        int ans = check(mid);
        if(ans == 1)
        {
            exists = 1;
            md = mid;
            break;
        }
        if(ans == 0)
            st = mid + 2;
        else
            dr = mid - 2;
    }
    if(!exists)
    {
        cout << -1;
        return 0;
    }
    else
    {
        int lft, rgt;
        if(sum % 2 == 1)
            st = 1, dr = n - (n % 2 == 0);
        else
            st = 0, dr = n - (n % 2 == 1);
        dr = md;
        while(st <= dr)
        {
            int tp1 = st / 2 + dr / 2 + st % 2 + dr % 2;
            int mid = tp1 / 2;
            if(sum % 2 == 1)
                mid = 2 * mid - 1;
            else
                mid = mid * 2;
            int ans = check(mid);
            if(ans == 1)
                lft = mid, dr = mid - 2;
            else
                st = mid + 2;
        }
        if(sum % 2 == 1)
            st = 1, dr = n - (n % 2 == 0);
        else
            st = 0, dr = n - (n % 2 == 1);
        st = md;
        while(st <= dr)
        {
            int tp1 = st / 2 + dr / 2 + st % 2 + dr % 2;
            int mid = tp1 / 2;
            if(sum % 2 == 1)
                mid = 2 * mid - 1;
            else
                mid = mid * 2;
            int ans = check(mid);
            if(ans == 1)
                rgt = mid, st = mid + 2;
            else
                dr = mid - 2;
        }
        for(int i = lft; i <= rgt; i += 2)
            cout << i << " ";
    }
    return 0;
}

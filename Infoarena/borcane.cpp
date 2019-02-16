#include<bits/stdc++.h>
using namespace std;
ifstream f("borcane.in");
ofstream g("borcane.out");
int n;
struct str
{
    int val, poz;
};
str v[102];
bool cmp(str a, str b)
{
    return a.val < b.val;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i)
        f >> v[i].val, v[i].poz = i;
    sort(v+1, v+n+1, cmp);
    for(int p = 1; p <= 10; ++p)
    {
        sort(v+1, v+n+1, cmp);
        int i = n-1;
        for(; i >= 1; )
        {
            if(v[i].val == 0)
                break;
            int sum = v[i-2].val + v[i-1].val + v[i].val;
            while(sum % 2 == 1 || v[i].val > v[i-1].val + v[i-2].val)
            {
                if(v[i].val && v[i-1].val && sum % 2 == 0)
                {
                    g << v[i].poz << " " << v[i-1].poz << " " << v[i-2].poz << '\n';
                    --v[i].val, --v[i-1].val, v[i-2].val += 2;
                }
                else
                {
                    g << v[n].poz << " " << v[i].poz << " " << v[i-2].poz << '\n';
                    --v[n].val, --v[i].val, v[i-2].val += 2;
                }
                sum = v[i-2].val + v[i-1].val + v[i].val;
                sort(v + i - 2, v + i + 1, cmp);
            }
            sum = v[i].val + v[i-1].val + v[i-2].val;
            while(sum)
            {
                int mx1 = 0, mx2 = 0;
                for(int j = i - 2; j <= i; ++j)
                    if(v[j].val > v[mx1].val)
                        mx2 = mx1, mx1 = j;
                    else
                        if(v[j].val > v[mx2].val)
                            mx2 = j;
                g << v[mx1].poz << " " << v[mx2].poz << " " << v[n].poz << '\n';
                --v[mx1].val, --v[mx2].val, v[n].val += 2;
                sum -= 2;
            }
            i -= 3;
            if(i < 3)
                i = 3;
        }
    }
    return 0;
}

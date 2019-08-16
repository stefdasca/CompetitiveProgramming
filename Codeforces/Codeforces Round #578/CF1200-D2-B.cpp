#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define x v[i]
#define y v[i+1]
using namespace std;
int n, m, k, t, v[101], q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(; t; t--)
    {
        bool ok=1;
        cin>>n>>m>>k;
        for(int i=1; i<=n; i++)
            cin>>v[i];
        ok = 1;
        for(int i = 1; i < n && ok; ++i)
        {
            if(x >= y)
            {
                if(y - k >= 0)
                    m += x - y + k;
                else
                    m += x;
            }
            else
            {
                if(x >= y - k)
                {
                    if(y - k >= 0)
                        m += x - y + k;
                    else
                        m += x ;
                    }
                else
                {
                    m -= y - k - x;
                    if(m < 0)
                    {
                        ok = 0;
                        break;
                    }
                }
            }
            //cout << m << '\n';
        }
        if(ok)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<'\n';

    }
    return 0;
}

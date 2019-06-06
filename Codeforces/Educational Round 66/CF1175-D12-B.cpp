#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int l;
deque<long long>val;
deque<long long>prd;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l;
    long long value = 0;
    long long intmx = (1LL<<32) - 1;
    for(; l; --l)
    {
        string s;
        cin >> s;
        long long z;
        if(s[0] == 'f')
            cin >> z;
        if(s[0] == 'f')
        {
            val.push_back(z);
            if(!prd.empty())
                prd.push_back(min(intmx+1, z * prd.back()));
            else
                prd.push_back(z);
        }
        else
        {
            if(s[0] == 'e')
            {
                if(!val.empty())
                    val.pop_back(), prd.pop_back();
            }
            else
            {
                if(!val.empty())
                    value += prd.back();
                else
                    ++value;
                if(value > intmx)
                {
                    cout << "OVERFLOW!!!";
                    return 0;
                }
            }
        }
    }
    cout << value;
    return 0;
}


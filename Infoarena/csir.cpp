#include<bits/stdc++.h>
using namespace std;
ifstream fi ("csir.in");
ofstream fo ("csir.out");
int t;
string s;
bool good (string a)
{
    string b;
    bool isA = 0;
    bool isB = 0;
    int pos = -1;
    for(int i=0; i < a.size(); ++i)
    {
        if(a[i] == 'A')
            isA = 1;
        else
            isB = 1, pos = i;
    }
    if(!isA || !isB)
        return 1;
    for(int j = pos + 1; j < a.size(); ++j)
        b += a[j];
    for(int j = 0; j <= pos; ++j)
        b += a[j];
    int lenmax = -1;
    int lenmin = -1;
    int len = 0;
    for(int j = 0; j < b.size(); ++j)
    {
        if(b[j] == 'A')
            ++len;
        else
        {
            if(lenmax == -1)
                lenmax = len, lenmin = len;
            else
                lenmax = max(lenmax, len), lenmin = min(lenmin, len);
            len = 0;
        }
    }
    if(lenmax - lenmin >= 2)
        return 0;
    string c;
    len = 0;
    for(int j = 0; j < b.size(); ++j)
    {
        if(b[j] == 'A')
            ++len;
        else
        {
            if(len == lenmax)
                c += 'B';
            else
                c += 'A';
            len = 0;
        }
    }
    return good(c);
}
int main()
{
    fi >> t;
    for(; t; --t)
    {
        fi >> s;
        fo << good(s) << '\n';
    }
    return 0;
}

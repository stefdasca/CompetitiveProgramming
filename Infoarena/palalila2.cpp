#include<bits/stdc++.h>
using namespace std;
ifstream f("palalila2.in");
ofstream g("palalila2.out");
int n,i,sol;
char s[500002];
int main()
{
    f>>s;
    n=strlen(s);
    i = 0;
    while (i+1 < n)
    {
        while (s[i] >= s[i+1] && i+1 < n)
            i++;
        sol++;
        if (i+1 < n)
            sol++;
        while (s[i] <= s[i+1] && i+1 < n)
            i++;
    }
    g<<sol;
    return 0;
}

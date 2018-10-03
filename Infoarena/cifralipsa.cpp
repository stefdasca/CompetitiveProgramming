#include<bits/stdc++.h>
using namespace std;
ifstream f("cifralipsa.in");
ofstream g("cifralipsa.out");
int t;
char c[100002];
int s;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>c;
        int L=strlen(c);
        s=0;
        for(int j=0;j<L;++j)
            s+=c[j]-'0';
        g<<9-s%9<<'\n';
    }
    return 0;
}

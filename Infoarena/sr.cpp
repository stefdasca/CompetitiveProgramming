#include<bits/stdc++.h>
using namespace std;
ifstream f("sr.in");
ofstream g("sr.out");
char c1[100002],c2[100002];
int main()
{
    f>>(c1+1);
    f>>c2;
    int l=strlen(c1+1);
    int q=0;
    for(int i=1;i<=l;++i)
        if(c1[i]==c2[q])
            g<<i<<" ",++q;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("diametru.in");
ofstream g("diametru.out");
int main()
{
    g<<499<<" "<<745<<'\n';
    int nr=1;
    g<<497<<" "<<499<<'\n';
    int a=497;
    int b=498;
    for(int i=1;i<=496;i+=2)
    {
        g<<a<<" "<<i<<'\n';
        g<<i<<" "<<i+1<<'\n';
        g<<i+1<<" "<<b<<'\n';
        nr+=3;
    }
    return 0;
}

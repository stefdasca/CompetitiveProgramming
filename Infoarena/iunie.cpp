#include<bits/stdc++.h>
using namespace std;
ifstream f("iunie.in");
ofstream g("iunie.out");
int n;
int main()
{
    f>>n;
    if(n%2==1)
        g<<0;
    else
        g<<n/4;
}

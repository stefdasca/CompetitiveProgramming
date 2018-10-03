#include<bits/stdc++.h>
using namespace std;
ifstream f("dmin2.in");
ofstream g("dmin2.out");
long long n,m;
int main()
{
    f>>n>>m;
    long long sol=n*(n-1)/2-m-n+1;
    g<<sol<<'\n';
    return 0;
}

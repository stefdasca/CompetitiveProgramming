#include<bits/stdc++.h>
using namespace std;
ifstream f("triplet.in");
ofstream g("triplet.out");
int n;
int main()
{
    f>>n;
    if(n%2==0)
        g<<n/2+1<<" "<<-n/2<<" "<<-1<<'\n';
    else
        g<<n/2+1<<" "<<-n/2<<" "<<0<<'\n';
    return 0;
}

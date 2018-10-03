#include<bits/stdc++.h>
using namespace std;
ifstream f("dreptunghi.in");
ofstream g("dreptunghi.out");
int n,m,mov;
int main()
{
    f>>n>>m;
    while(n && m)
    {
        if(m>=n){
            mov+=(m/n)*n;
            m%=n;
        }
        else
        {
            mov+=(n/m)*m;
            n%=m;
        }
    }
    g<<mov;
    return 0;
}

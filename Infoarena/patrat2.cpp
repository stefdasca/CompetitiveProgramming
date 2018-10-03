#include<bits/stdc++.h>
using namespace std;
ifstream f("patrat2.in");
ofstream g("patrat2.out");
int n;
int main()
{
    f>>n;
    while(n)
    {
        g<<(int)sqrt(n)<<'\n';
        n-=(int)sqrt(n)*(int)sqrt(n);
    }
    return 0;
}

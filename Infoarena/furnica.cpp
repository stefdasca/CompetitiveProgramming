#include<bits/stdc++.h>
using namespace std;
ifstream f("furnica.in");
ofstream g("furnica.out");
long long nr;
char s;
int main()
{
    f>>s;
    f>>nr;
    if(s=='C')
        g<<(nr+1)*(nr+1);
    else
        if(nr%2==0)
            g<<(nr/2+1)*(nr/2+1);
        else
            g<<((nr+1)*(nr+2)/2)-((nr+1)/2)*((nr+1)/2);
    return 0;
}

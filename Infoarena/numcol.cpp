#include<bits/stdc++.h>
using namespace std;
ifstream f("numcol.in");
ofstream g("numcol.out");
int n;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int nr=0;
        int j=i;
        while(j%2==0)
            j/=2,++nr;
        if(nr<10)
            g<<nr;
        else
        {
            char c='A'+nr-10;
            g<<c;
        }
    }
    return 0;
}

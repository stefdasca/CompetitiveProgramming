#include<bits/stdc++.h>
using namespace std;
ifstream f("perioada2.in");
ofstream g("perioada2.out");
int n,i,m,sol;
char c[10000002];
int main()
{
    f>>n;
    f>>c+1;
    ++sol;
    for(int j=2;j<=n;++j)
        if(c[1]!=c[j])
        {
            --sol;
            break;
        }
    for(int i=2;i<=n/2;++i)
        if(n%i==0){
            ++sol;
            for(int j=i+1;j<=n;j+=i)
                if(c[1]!=c[j] || c[i]!=c[j+i-1])
                {
                    --sol;
                    break;
                }
        }
    g<<sol;
    return 0;
}

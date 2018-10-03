#include<bits/stdc++.h>
using namespace std;
ifstream f("flori4.in");
ofstream g("flori4.out");
int a,b,c,n;
int main()
{
    f>>n;
    a=1;
    b=2;
    if(n==1)
        g<<1;
    else
        if(n==2)
            g<<2;
        else{
            for(int i=3;i<=n;++i){
                c=(a+b+1)%9001;
                a=b;
                b=c;
            }
            g<<c;
        }
    return 0;
}

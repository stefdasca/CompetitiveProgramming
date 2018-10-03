#include<bits/stdc++.h>
using namespace std;
ifstream f("guinness.in");
ofstream g("guinness.out");
long long a,m,t;
string b;
int main()
{
    f>>t;
    for(;t;--t)
    {
        f>>a>>b>>m;
        long long sol=1;
        for(int i=b.size()-1;i>=0;--i)
        {
            for(int j=1;j<=(b[i]-'0');++j)
                sol=(sol*a)%m;
            long long c=1;
            for(int j=1;j<=10;++j)
                c=(c*a)%m;
            a=c;
        }
        g<<sol<<'\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("kbiti.in");
ofstream g("kbiti.out");
int t;
char c1[33];
unsigned int p2;
long long nr;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>c1;
        int j=strlen(c1)-1;
        p2=1;
        nr=0;
        for(;j>=0;--j){
            if(c1[j]=='1')
                nr+=p2;
            p2<<=1;
        }
        g<<nr+1<<'\n';
    }
    return 0;
}

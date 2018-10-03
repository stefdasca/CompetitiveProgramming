#include<bits/stdc++.h>
using namespace std;
ifstream f("pietre.in");
ofstream g("pietre.out");
int t;
int a,b;
bool isu[1000002];
int p[1000002];
void cp()
{
    int d=1;
    for(int i=1;i+d<=1000000;++i)
        if(isu[i]==0){
            p[i]=i+d;
            isu[i]=1,isu[i+d]=1;
            d++;
        }
}
int main()
{
    f>>t;
    cp();
    for(int i=1;i<=t;++i)
    {
        f>>a>>b;
        if(a>b)
            swap(a,b);
        if(p[a]==b)
            g<<"2"<<'\n';
        else
            g<<"1"<<'\n';
    }
    return 0;
}

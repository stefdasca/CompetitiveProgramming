#include<bits/stdc++.h>
using namespace std;
ifstream f("alinuta.in");
ofstream g("alinuta.out");
int k,t;
int a,b;
bool isu[1000002];
int p[100002];
void cp()
{
    int d=k+1;
    for(int i=1;i+d<=100000;++i)
        if(isu[i]==0){
            p[i]=i+d;
            isu[i]=1,isu[i+d]=1;
            d+=k+1;
        }
}
int main()
{
    f>>k>>t;
    cp();
    for(int i=1;i<=t;++i)
    {
        f>>a>>b;
        if(a>b)
            swap(a,b);
        if(p[a]==b)
            g<<"B"<<'\n';
        else
            g<<"A"<<'\n';
    }
    return 0;
}

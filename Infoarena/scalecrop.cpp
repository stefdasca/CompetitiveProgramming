#include<bits/stdc++.h>
using namespace std;
ifstream f("scalecrop.in");
ofstream g("scalecrop.out");
double x,y,z,w;
int main()
{
    f>>x>>y>>z>>w;
    double raport=max(x/z,y/w);
    g<<setprecision(3)<<fixed<<z*raport<<' '<<w*raport;
    return 0;
}

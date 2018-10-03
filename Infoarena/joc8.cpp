#include<bits/stdc++.h>
using namespace std;
ifstream f("joc8.in");
ofstream g("joc8.out");
int a,b;
int nrq,nr;
int main()
{
    f>>a>>b;
    while(f>>nr)
    {
        if(nrq==0)
            if(nr==1){
                g<<(a+b)/2;
                return 0;
            }
        if(nrq==1)
            if(nr==0)
                a=(a+b)/2+1;
            else
                b=(a+b)/2-1;
        nrq=1-nrq;
    }
    g<<0;
}

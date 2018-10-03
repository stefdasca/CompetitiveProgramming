#include<bits/stdc++.h>
using namespace std;
ifstream f("numere.in");
ofstream g("numere.out");
int t,a,b,tr;
int win(int a, int b)
{
    if(a>=2*b)
        return 1;
    else
        if(b==0)
            return 0;
    return 1-win(b,a-b);
}
void euclid(int a, int b)
{
    int c=0;
    tr=1;
    while(b)
    {
        if(win(a,b)==1){
            g<<tr<<'\n';
            break;
        }
        c=a%b;
        a=b;
        b=c;
        tr=3-tr;
    }
}
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>a>>b;
        if(a<b)
            swap(a,b);
        euclid(a,b);
    }
    return 0;
}

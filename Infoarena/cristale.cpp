#include<bits/stdc++.h>
using namespace std;
ifstream f("cristale.in");
ofstream g("cristale.out");
char x1,x2,x3;
int t;
int l;
char c[102];
char afll(char a, char b)
{
    if(x1!=a && x1!=b)
        return x1;
     if(x2!=a && x2!=b)
        return x2;
     if(x3!=a && x3!=b)
        return x3;
}
deque<char>d;
int main()
{
    f>>x1>>x2>>x3;
    f>>t;
    for(;t;--t)
    {
        f>>l>>c;
        d.clear();
        d.push_back(c[0]);
        int ld=0;
        for(int i=1;i<l;++i)
        {
            char ch=c[i];
            while(ld>=0 && ch!=d.back())
            {
                ch=afll(ch,d.back());
                d.pop_back();
                --ld;
            }
            d.push_back(ch);
            ++ld;
        }
        if(d.size()==l || d.size()<=2)
            g<<d.size()<<'\n';
        else
            g<<2-d.size()%2<<'\n';
    }
    return 0;
}

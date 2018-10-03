#include<bits/stdc++.h>
using namespace std;
ifstream f("cutie.in");
ofstream g("cutie.out");
int t;
int n,k,m;
deque<int>Boxes;
int xorsum;
int dif=0;
int main()
{
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>n>>k>>m;
        Boxes.clear();
        for(int j=1;j<=k;++j)
        {
            int nr;
            f>>nr;
            Boxes.push_back(nr);
        }
        if(!Boxes.size() || Boxes[0]!=1)
            Boxes.push_front(1);
        if(Boxes.back()!=n)
            Boxes.push_back(n);
        int poz=0;
        xorsum=0;
        dif=0;
        for(int j=1;j<=m;++j)
        {
            int nr;
            f>>nr;
            while(nr>Boxes[poz])
                ++poz;
            int a=(nr-Boxes[poz-1])&1;
            int b=(Boxes[poz]-nr)&1;
            if(a==b)
                xorsum^=a;
            else
                dif^=1;
        }
        if(dif==1)
            g<<1;
        else{
            xorsum^=dif;
            g<<xorsum;
        }
    }
    return 0;
}

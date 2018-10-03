#include<bits/stdc++.h>
using namespace std;
ifstream f("sort.in");
ofstream g("sort.out");
int n,fr[5],v[1002],sol;
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>v[i],fr[v[i]]++;
    for(int i=1;i<=n;++i){
        if(i<=fr[1]){
            if(v[i]==2)
                for(int j=fr[1]+fr[2];j>fr[1];--j)
                    if(v[j]==1)
                    {
                        swap(v[i],v[j]);
                        ++sol;
                        break;
                    }
            if(v[i]==3)
                 for(int j=n;j>fr[1]+fr[2];--j)
                    if(v[j]==1)
                    {
                        swap(v[i],v[j]);
                        ++sol;
                        break;
                    }
        }
        if(i>fr[1] && i<=fr[1]+fr[2])
            if(v[i]==3)
                 for(int j=n;j>fr[1]+fr[2];--j)
                    if(v[j]==2)
                    {
                        swap(v[i],v[j]);
                        ++sol;
                        break;
                    }
    }
    int nr=0;
    for(int i=1;i<=n;++i){
        if(i<=fr[1])
            if(v[i]!=1)
                ++nr;
        if(i>fr[1] && i<=fr[1]+fr[2])
            if(v[i]!=2)
                nr++;
        if(i>fr[1]+fr[2])
            if(v[i]!=3)
                ++nr;
    }
    nr=nr/3*2;
    g<<sol+nr;
    return 0;
}

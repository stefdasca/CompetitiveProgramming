#include<bits/stdc++.h>
using namespace std;
ifstream f("secvdist.in");
ofstream g("secvdist.out");
int n,k;
int x;
deque<int>poz1; // minim
int v[1000002];
deque<int>poz2; // maxim
int main()
{
    f>>n>>k;
    for(int i=1;i<=n;++i)
        f>>v[i];
    int lmax=0;
    int le1=0;
    int le2=0;
    int st=0;
    for(int sf=1;sf<=n;++sf)
    {
        while(poz1.size() && v[sf]<v[poz1.back()])
            poz1.pop_back();
        while(poz2.size() && v[sf]>v[poz2.back()])
            poz2.pop_back();
        poz1.push_back(sf);
        poz2.push_back(sf);
        if(poz2.size()==1 && poz1.size()>1)
        {
            while(abs(v[poz2[0]]-v[poz1[0]])>k)
                st=max(st,poz1[0]),poz1.pop_front();
        }
        else
            if(poz2.size()>1 && poz1.size()==1)
            {
                while(abs(v[poz2[0]]-v[poz1[0]])>k)
                    st=max(st,poz2[0]),poz2.pop_front();
            }
        lmax=max(lmax,sf-st);
    }
    g<<lmax;
    return 0;
}

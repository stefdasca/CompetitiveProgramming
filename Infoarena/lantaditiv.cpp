#include<bits/stdc++.h>
using namespace std;
ifstream f("lantaditiv.in");
ofstream g("lantaditiv.out");
long long n;
deque<long long>sol;
int main()
{
    f>>n;
    sol.push_back(n);
    int st=0;
    int sf=0;
    while(st<=sf)
    {
        int sf1=sf;
        for(int i=st;i<=sf;++i)
        {
            if(sol[i]%2==1)
            {
                if(sol.back()!=sol[i]/2+1)
                    sol.push_back(sol[i]/2+1),++sf1;
                if(sol.back()!=sol[i]/2)
                    sol.push_back(sol[i]/2),++sf1;
            }
            else
                if(sol.back()!=sol[i]/2)
                    sol.push_back(sol[i]/2),++sf1;
        }
        st=sf+1;
        sf=sf1;
    }
    g<<sol.size()-1<<'\n';
    for(int i=sol.size()-2;i>=0;--i)
        g<<sol[i]<<" ";
}

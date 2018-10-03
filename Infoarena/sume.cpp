#include<bits/stdc++.h>
#define NMAX 25005
using namespace std;
ifstream f("sume.in");
ofstream g("sume.out");
int p,n;
int main()
{
    f>>p;
    n=(int)sqrt(2*p)+1;
    if(n*(n-1)/2!=p)
    {
        g<<"-1\n";
        return 0;
    }
    vector<int>v(p);
    for(int i=0;i<p;i++)
        f>>v[i];
    sort(v.begin(),v.end());
    for(int i=2;i<n;i++)
    {
        int s=v[0]+v[1]+v[i];
        if(s%2)
            continue;
        s/=2;
        vector<int>a(n);
        a[0]=s-v[i];
        a[1]=s-v[1];
        a[2]=s-v[0];
        unordered_map<int,int>M;
        M[v[0]]++;
        M[v[1]]++;
        M[v[i]]++;
        int pos=3;
        for(int j=0;j<p;j++)
        {
            if(M[v[j]]>0)
                M[v[j]]--;
            else
            {
                if(pos==n)
                {
                    pos=-1;
                    break;
                }
                a[pos]=v[j]-a[0];
                for(int k=1;k<pos;++k)
                    ++M[a[k]+a[pos]];
                ++pos;
            }
        }
        if(pos==n)
        {
            g<<n<<'\n';
            for(int i=0;i<n;i++)
                g<<a[i]<<' ';
            return 0;
        }
    }
    g<<"-1\n";
    return 0;
}

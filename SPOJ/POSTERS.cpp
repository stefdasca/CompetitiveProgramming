#include<bits/stdc++.h>
using namespace std;
int t,n;
struct sg
{
    int a,b;
};
sg v[50002];
int arr[10000002],urm[10000002];
set<int>s;
int main()
{
    cin>>t;
    for(;t;--t)
    {
        cin>>n;
        memset(arr,0,sizeof(arr));
        memset(urm,0,sizeof(urm));
        s.clear();
        int Zmax=0;
        for(int i=1;i<=n;++i)
            cin>>v[i].a>>v[i].b,Zmax=max(Zmax,v[i].b);
        for(int i=n;i>=1;--i)
            for(int j=v[i].a;j<=v[i].b;)
                if(!arr[j])
                {
                    arr[j]=i;
                    urm[j]=v[i].b+1;
                    ++j;
                }
                else
                    j=urm[j];
        for(int i=1;i<=Zmax;++i)
            if(arr[i])
                s.insert(arr[i]);
        cout<<s.size()<<'\n';
    }
    return 0;
}

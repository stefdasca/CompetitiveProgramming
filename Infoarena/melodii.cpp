#include<bits/stdc++.h>
using namespace std;
ifstream f("melodii.in");
ofstream g("melodii.out");
int t,r;
long long nr;
int v[1000002];
int main()
{
    f>>t>>r;
    v[1]=1;
    v[2]=1;
    int l=0;
    for(int i=3;;++i){
        v[i]=(v[i-1]+v[i-2])%r;
        if(v[i]==1 && v[i-1]==0){
            l=i-1;
            break;
        }
    }
    for(int i=1;i<=t;++i)
    {
        f>>nr;
        g<<v[(nr+1)%l]<<'\n';
    }
    return 0;
}

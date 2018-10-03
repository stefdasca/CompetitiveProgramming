#include<bits/stdc++.h>
using namespace std;
ifstream f("secv6.in");
ofstream g("secv6.out");
int n,nr[8200],v[16000003];
long long sol;
int s[1000002];
int main()
{
    f>>n;
    for(int i=0;i<min(n,8192);++i)
        f>>nr[i];
   for(int i=0;i<n;++i)
        v[i]=i+(nr[i/8192]^nr[i%8192]);
    sol=0;
    s[0]=v[0];
    int sz=0;
    for(int i=1;i<n;++i){
        int le=0;
        for(int j=sz;j>=0;--j){
            ++sol;
            if(v[i]<=s[j])
                break;
        }
        while(s[sz]<=v[i]){
            --sz;
            if(sz==-1)
                break;
        }
        ++sz;
        s[sz]=v[i];
    }
    g<<sol<<'\n';
    return 0;
}

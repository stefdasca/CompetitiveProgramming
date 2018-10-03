#include <bits/stdc++.h>
#define NMAX 100005
using namespace std;
ifstream fin("noname2.in");
ofstream fout("noname2.out");
long long v[NMAX],sp[NMAX];
int n,k;
bool check(int mid) {
    int st,dr,mij;
    for(st=1,dr=st+mid-1;dr<=n;++st,++dr){
        mij=(st+dr)/2;
        if(v[mij]*(mij-st+1)-1LL*(sp[mij]-sp[st-1]) + 1LL*sp[dr]-sp[mij] - v[mij]*(dr - mij) <= k)
            return 1;
    }
    return 0;
}
int main() {
    int i,j,st,dr,mid;
    fin>>n>>k;
    for(i=1;i<=n;++i)
        fin>>v[i];
    sort(v+1,v+n+1);
    for(i=1;i<=n;++i)
        sp[i]=sp[i-1]+v[i];
    st=1;dr=n;
    while(st<=dr){
        mid=(st+dr)/2;
        if(check(mid))
            st=mid+1;
        else
            dr=mid-1;
    }
    fout<<dr;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
ifstream f("sir.in");
ofstream g("sir.out");
int n,x,y,z;
int v[100002];
deque<int>max1;
deque<int>min1;
int l=1,lmax,a,b;
void dq()
{
    int s=0;
    for(int st=1, dr=1; dr<=n; ++dr) {
        while(!min1.empty() && (min1.back()<st || v[min1.back()]>=v[dr]))
            min1.pop_back();
        min1.push_back(dr);
        while(!max1.empty() && (max1.back()<st || v[max1.back()]<=v[dr]))
            max1.pop_back();
        max1.push_back(dr);
        while(st<dr && (v[max1.front()]-v[min1.front()]>z || dr-st>=y)){
            ++st;
            while(max1.front()<st) max1.pop_front();
            while(min1.front()<st) min1.pop_front();
        }

        if(dr-st+1>=x && dr-st+1<=y && dr-st+1>=lmax) {
            a=st;
            b=dr;
            lmax=dr-st+1;
        }
    }
}
int main()
{
    f>>n>>x>>y>>z;
    for(int i=1;i<=n;++i)
        f>>v[i];
    dq();
    if(lmax==0)
        g<<-1;
    else
        g<<lmax<<" "<<a<<" "<<b<<'\n';
    return 0;
}

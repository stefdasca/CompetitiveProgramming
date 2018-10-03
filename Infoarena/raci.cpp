#include <bits/stdc++.h>
using namespace std;
ifstream fin("raci.in");
ofstream fout("raci.out");
int n,k;
int a[500002],b[500002];
char s[15];
deque<int>Q[27];
int d[500002];
int i,maxi=0,mx=0;
int main()
{
    fin>>n>>k;
    for(i=1;i<=n;++i)
    {
       fin>>s;
       a[i]=s[0]-'a';
       b[i]=s[strlen(s)-1]-'a';
       maxi=0;
       while(!Q[a[i]].empty() && Q[a[i]].front()<i-k)
           Q[a[i]].pop_front();
       if(!Q[a[i]].empty())
           maxi=Q[a[i]].front();
       d[i]=d[maxi]+1;
       while(!Q[b[i]].empty() && d[Q[b[i]].back()]<d[i])
           Q[b[i]].pop_back();
       Q[b[i]].push_back(i);
       if(mx<d[i])
           mx=d[i];
    }
    fout<<mx;
    return 0;
}

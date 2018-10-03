#include<bits/stdc++.h>
using namespace std;
ifstream f("charlie.in");
ofstream g("charlie.out");
int c;
char c1[100002];
deque<char>v;
int l,sol;
void first()
{
    int s=1,maxs=0;
    for(int i=1;i<l;++i)
        if(s%2==1)
            if(c1[i]<c1[i-1] && c1[i]<c1[i+1])
                ++s;
            else
                maxs=max(maxs,s),s=1;
        else
            if(c1[i]>c1[i-1] && c1[i]>c1[i+1])
                ++s;
            else
                maxs=max(maxs,s),s=1;
    maxs=max(maxs,s);
    g<<maxs+(1-maxs%2);
}
void second()
{
    int sol=0;
    v.push_back(c1[0]);
    v.push_back(c1[1]);
    int lv=1;
    for(int i=2;i<l;++i)
    {
        while(c1[i]>v[lv] && v[lv]<v[lv-1]){
            sol=sol+max(c1[i],v[lv-1])-'a'+1,v.pop_back(),--lv;
            if(lv);
            else break;
        }
        v.push_back(c1[i]);
        ++lv;
    }
    for(int i=0;i<v.size();++i)
        g<<v[i];
    g<<'\n'<<sol;
}
int main()
{
    f>>c;
    f>>c1;
    l=strlen(c1);
    if(c==1)
        first();
    else
        second();
    return 0;
}

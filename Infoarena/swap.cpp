#include<bits/stdc++.h>
using namespace std;
ifstream f("swap.in");
ofstream g("swap.out");
char c1[50002],c2[50002];
bool wtaken[50002],ok[50002],good=1;
deque<int>v[30];
int AIB[50002],L,sol;
int fr1[30],fr2[30];
void intro()
{
    f>>c1+1;
    f>>c2+1;
    L=strlen(c1+1);
    for(int i=1;i<=L;++i){
        fr1[c1[i]-'a']++,fr2[c2[i]-'a']++;
        v[c1[i]-'a'].push_back(i);
    }
    for(int i=0;i<=25;++i)
        if(fr1[i]!=fr2[i])
            good=0;
}
void Add(int nod)
{
    for(;nod<=L;nod+=(nod&(-nod)))
        AIB[nod]++;
}
int compute(int nod)
{
    int s=0;
    for(;nod;nod-=(nod&(-nod)))
        s+=AIB[nod];
    return s;
}
void finito()
{
    for(int i=1;i<=L;++i)
    {
        sol+=v[c2[i]-'a'][0]+compute(L-v[c2[i]-'a'][0]+1)-i;
      //  g<<sol<<" ";
        Add(L-v[c2[i]-'a'][0]+1);
        v[c2[i]-'a'].pop_front();
    }
    g<<sol;
}
int main()
{
    intro();
    if(good)
        finito();
    else
        g<<-1;
    return 0;
}

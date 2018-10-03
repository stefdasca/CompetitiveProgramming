#include<bits/stdc++.h>
using namespace std;
ifstream f("multimi4.in");
ofstream g("multimi4.out");
int n,pos;
vector<int>v[25];
int lit[30];
string s;
string s2;
char L;
int a,b,p;
vector<int> intersect(vector<int>a, vector<int>b)
{
    vector<int>sol;
    int i=0,j=0;
    for(;i<a.size() && j<b.size();)
        if(a[i]==b[j])
            sol.push_back(a[i]),++i,++j;
        else
            if(a[i]<b[j])
                ++i;
            else
                ++j;
    return sol;
}
vector<int> reunion(vector<int>a, vector<int>b)
{
    vector<int>sol;
    int i=0,j=0;
    for(;i<a.size() && j<b.size();)
        if(a[i]==b[j])
            sol.push_back(a[i]),++i,++j;
        else
            if(a[i]<b[j])
                sol.push_back(a[i]),++i;
            else
                sol.push_back(b[j]),++j;
    while(i<a.size())
        sol.push_back(a[i]),++i;
    while(j<b.size())
        sol.push_back(b[j]),++j;
    return sol;
}
vector<int> termen();
vector<int> factor();
vector<int> eval()
{
    vector<int>sol;
    sol=factor();
    while(s2[pos]=='+')
    {
        ++pos;
        sol=reunion(sol,factor());
    }
    return sol;
}
vector<int> factor()
{
    vector<int>sol;
    sol=termen();
    while(s2[pos]=='*')
    {
        ++pos;
        sol=intersect(sol,termen());
    }
    return sol;
}
vector<int>termen()
{
    vector<int>sol;
    if(s2[pos]=='(')
    {
        ++pos;
        sol=eval();
        ++pos;
    }
    else
    {
        int posi=lit[s2[pos]-'A'];
        for(int j=0;j<v[posi].size();++j)
            sol.push_back(v[posi][j]);
        ++pos;
    }
    return sol;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>s;
        a=b=p=0;
        L=s[0];
        lit[L-'A']=i;
        pos=2;
        while(s[pos]!='-')
            a=a*10+s[pos]-'0',++pos;
        ++pos;
        while(s[pos]!='/')
            b=b*10+s[pos]-'0',++pos;
        ++pos;
        while(s[pos]>='0' && s[pos]<='9')
            p=p*10+s[pos]-'0',++pos;
        for(int j=a;j<=b;j+=p)
            v[i].push_back(j);
    }
    pos=0;
    f>>s2;
    vector<int>R=eval();
    g<<R.size()<<'\n';
    for(int i=0;i<R.size();++i)
        g<<R[i]<<" ";
    return 0;
}

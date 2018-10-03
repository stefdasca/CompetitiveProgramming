#include<bits/stdc++.h>
using namespace std;
ifstream f("expr.in");
ofstream g("expr.out");
string s;
vector<int>v;
int poz=0;
vector<int>termen();
vector<int> intersect(vector<int>a, vector<int>b)
{
    vector<int>sol;
    for(int i=0,j=0;i<a.size() && j<b.size();)
    {
        if(a[i]==b[j])
            sol.push_back(a[i]),++i,++j;
        else
            if(a[i]<b[j])
                ++i;
            else
                ++j;
    }
    return sol;
}
vector<int> reunion(vector<int>a, vector<int>b)
{
    vector<int>sol;
    int i=0,j=0;
    for(;i<a.size() && j<b.size();)
    {
        if(a[i]==b[j])
            sol.push_back(a[i]),++i,++j;
        else
            if(a[i]<b[j])
                sol.push_back(a[i]),++i;
            else
                sol.push_back(b[j]),++j;
    }
    while(i<a.size())
        sol.push_back(a[i]),++i;
    while(j<b.size())
        sol.push_back(b[j]),++j;
    return sol;
}
vector<int> diff(vector<int> a, vector<int> b)
{
    vector<int>sol;
    for(int i=0,j=0;i<a.size() && j<b.size();)
    {
        if(a[i]==b[j])
            sol.push_back(i),++i,++j;
        else
        {
            if(a[i]<b[j])
                ++i;
            else
                ++j;
        }
    }
    vector<int>sol2;
    for(int i=0,pos=0;i<a.size();++i)
    {
        if(pos<sol.size() && sol[pos]==i)
            ++pos;
        else
            sol2.push_back(a[i]);
    }
    return sol2;
}
vector<int> eval()
{
    vector<int>t1=termen();
    while(s[poz]=='*' || s[poz]=='+' || s[poz]=='-' || s[poz]=='%')
    {
        char q=s[poz];
        ++poz;
        vector<int>t2=termen();
        if(q=='*')
            t1=intersect(t1,t2);
        if(q=='+')
            t1=reunion(t1,t2);
        if(q=='-')
            t1=diff(t1,t2);
        if(q=='%')
        {
            vector<int>t3=diff(t1,t2);
            vector<int>t4=diff(t2,t1);
            t1=reunion(t3,t4);
        }
    }
    return t1;
}
vector<int>termen()
{
    vector<int>sol;
    if(s[poz]=='{')
    {
        ++poz;
        while(s[poz]!='}')
        {
            int nr=0;
            while(s[poz]>='0' && s[poz]<='9')
                nr=nr*10+s[poz]-'0',++poz;
            sol.push_back(nr);
            if(s[poz]==',')
                ++poz;
        }
        ++poz;
    }
    else
    {
        ++poz;
        sol=eval();
        ++poz;
    }
    return sol;
}
int main()
{
    f>>s;
    v=eval();
    if(v.size()==0)
    {
        g<<"{}";
        return 0;
    }
    g<<"{";
    for(int i=0;i<v.size();++i)
    {
        g<<v[i];
        if(i+1==v.size())
            g<<"}";
        else
            g<<",";
    }
    return 0;
}


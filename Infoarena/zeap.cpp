#include<bits/stdc++.h>
using namespace std;
ifstream f("zeap.in");
ofstream g("zeap.out");
char sir[50];
int nr;
int maxi,mini;
set<int>s;
set<int> ::iterator it,it2,it1;
multiset<int>s2;
int main()
{
    while(!f.eof())
    {
        f.getline(sir,50);
        int nr=0;
        if(sir[0]!='M')
        {
            int pos=0;
            while(!(sir[pos]>='0' && sir[pos]<='9'))
                ++pos;
            while(sir[pos]>='0' && sir[pos]<='9')
                nr=nr*10+(sir[pos]-'0'),++pos;
        }
        if(sir[0]=='I')
        {
            it=s.find(nr);
            if(it!=s.end())
                continue;
            if(s.size())
            {
                if(nr>*s.rbegin())
                    s2.insert(nr-*s.rbegin());
                else
                    if(nr<*s.begin())
                        s2.insert(*s.begin()-nr);
                    else
                    {
                        it1=s.upper_bound(nr);
                        it2=it1;
                        --it2;
                        s2.erase(s2.find(*it1-*it2));
                        s2.insert(nr-*it2);
                        s2.insert(*it1-nr);
                    }
            }
            s.insert(nr);
        }
        if(sir[0]=='S')
        {
            it=s.find(nr);
            if(it==s.end())
                g<<-1<<'\n';
            else
            {
                s.erase(it);
                if(nr>*s.rbegin())
                    s2.erase(nr-*s.rbegin());
                else
                    if(nr<*s.begin())
                        s2.erase(*s.begin()-nr);
                    else
                    {
                        it1=s.upper_bound(nr);
                        it2=it1;
                        --it2;
                        s2.insert(*it1-*it2);
                        s2.erase(s2.find(nr-*it2));
                        s2.erase(s2.find(*it1-nr));
                    }
            }
            continue;
        }
        if(sir[0]=='C')
        {
            it=s.find(nr);
            if(it!=s.end())
                g<<1<<'\n';
            else
                g<<0<<'\n';
        }
        if(sir[0]=='M' && sir[1]=='A')
            if(s.size()<2)
                g<<-1<<'\n';
            else
                g<<*s.rbegin()-*s.begin()<<'\n';
        if(sir[0]=='M' && sir[1]=='I')
            if(!s2.size())
                g<<-1<<'\n';
            else
                g<<*s2.begin()<<'\n';
    }
    return 0;
}

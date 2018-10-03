#include<bits/stdc++.h>
using namespace std;
ifstream f("nc.in");
ofstream g("nc.out");
vector<int>v;
int nrc;
char c[4002];
int main()
{
    while(f.getline(c,4001))
    {
        int q=strlen(c);
        int i=0;
        for(;i<q;++i){
            if(c[i]=='!' || c[i]=='?' || c[i]=='.'){
                if(c[i-1]>='A' && c[i-1]<='Z' || c[i-1]>='a' && c[i-1]<='z')
                        ++nrc;
                if(nrc)
                    v.push_back(nrc),nrc=0;
            }
            else
                if(c[i]==' ' || c[i]==',')
                    if(c[i-1]>='A' && c[i-1]<='Z' || c[i-1]>='a' && c[i-1]<='z')
                        ++nrc;
        }
        if(c[i-1]>='A' && c[i-1]<='Z' || c[i-1]>='a' && c[i-1]<='z')
            ++nrc;
    }
    g<<v.size()<<'\n';
    for(int i=0;i<v.size();++i)
        g<<v[i]<<'\n';
}

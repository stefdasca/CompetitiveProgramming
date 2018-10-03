#include<bits/stdc++.h>
using namespace std;
ifstream f("joben.in");
ofstream g("joben.out");
int t,fr[27],fr2[27];
char c1[100002];
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>c1;
        int l=strlen(c1);
        for(int i=0;i<l;++i)
            fr[c1[i]-'a']++;
        f>>c1;
        for(int i=0;i<l;++i)
            fr2[c1[i]-'a']++;
        sort(fr,fr+26);
        sort(fr2,fr2+26);
        bool ok=1;
        for(int i=0;i<=25;fr[i]=0,fr2[i]=0,++i)
            if(fr[i]!=fr2[i])
                ok=0;
        if(ok==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }
}
